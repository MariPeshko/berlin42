#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

void second_child(int in_fd)
{
    fprintf(stderr, "2nd\n");

    // Create another pipe for the second child
    int fd[2];
    if (pipe(fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid_t p = fork();
    if (p < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (p == 0) {
        // Child process
        close(fd[0]); // Close unused read end
        dup2(in_fd, STDIN_FILENO); // Read from the input file descriptor
        dup2(fd[1], STDOUT_FILENO); // Write to the pipe
        close(fd[1]); // Close the write end after duplicating
        close(in_fd);

        char *sort_argv[] = {"/usr/bin/head", "-n", "1", NULL};
        execvp(sort_argv[0], sort_argv);
        perror("execvp");
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        close(fd[1]); // Close unused write end

        // Wait for the child to finish
        waitpid(p, NULL, 0);

        // Now redirect the output to "rozout"
        int file_out = open("rozout", O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (file_out == -1) {
            perror("open");
            exit(EXIT_FAILURE);
        }

        // Read from the pipe and write to the file
        char buffer[4096];
        ssize_t bytes;
        while ((bytes = read(fd[0], buffer, sizeof(buffer))) > 0) {
            write(file_out, buffer, bytes);
        }
        close(fd[0]);
        close(file_out);
    }
}

void first_child(int in_fd)
{
    fprintf(stderr, "1st\n");

    int fd[2];
    if (pipe(fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid_t p = fork();
    if (p < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (p == 0) {
        // Child process
        close(fd[0]); // Close unused read end
        dup2(in_fd, STDIN_FILENO); // Read from the input file descriptor
        dup2(fd[1], STDOUT_FILENO); // Write to the pipe
        close(fd[1]); // Close the write end after duplicating
        close(in_fd);

        char *cat_argv[] = {"/usr/bin/sort", NULL};
        execvp(cat_argv[0], cat_argv);
        perror("execvp");
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        close(fd[1]); // Close unused write end
        close(in_fd); // Close the input file descriptor in the parent

        // Wait for the first child to finish
        waitpid(p, NULL, 0);

        // Pass the read end of the pipe to the second child
        second_child(fd[0]);
    }
}

int main(int argc, char *argv[])
{
    int file = open("roz", O_RDONLY);
    if (file == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    first_child(file);

    return 0;
}
