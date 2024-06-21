#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h> // waitpid, pid_t, WIFEXITED(status)

void second_child(char **argv, int fd_f)
{
	fprintf(stderr, "2nd\n");
	int fd[2];
	pid_t p;
	int pp_ret;

	int file_out = open("rozout", O_WRONLY);
	pp_ret = pipe(fd);
	if (pp_ret == -1) {
        perror("pipe fail");
        exit(1); }
	p = fork();
	if (p < 0)
	{
		perror("fork fail");
		exit(1);
	}
	else if (p == 0)
	{
		dup2(fd[0], fd_f);
		close(fd[0]);

		close(fd[1]);

		dup2(file_out, STDOUT_FILENO);
		close(file_out);
		char *sort_argv[] = {"wc", "-w", NULL};
		// "/usr/bin/sort", "-n", "1"
		if (execvp(sort_argv[0], sort_argv) < 0)
			exit(1);
	}
	else if (p > 0)
	{
		close(fd[0]);
		close(fd[1]);
		waitpid(p, NULL, 0);
	}
}

void first_child(char **argv)
{
	fprintf(stderr, "1st\n");
	int fd[2];
	pid_t p;
	int pp_ret;

	pp_ret = pipe(fd);
	p = fork();
	if (p < 0)
	{
		perror("fork fail");
		exit(1);
	}
	else if (p == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		//close(fd[1]);
		char *sort_argv[] = {"sort", NULL};
		if (execvp(sort_argv[0], argv) < 0)
			exit(1);
	}
	else if (p > 0)
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		//close(fd[0]);		
		waitpid(p, NULL, 0);

		second_child(argv, fd[0]);
	}
}

int main(int argc, char *argv[])
{
	int file;

	file = open("roz", O_RDONLY);
	if (file == -1)
		fprintf(stderr, "error file");
	dup2(file, STDIN_FILENO);
	close(file);
	first_child(argv);
	
	return (0);
}
