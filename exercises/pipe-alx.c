#include <unistd.h> // pipe(), read(), write()
#include <stdio.h> // printf()
#include <string.h> // strlen()
#include <sys/types.h> // pid_t

int	main(void)
{
	int	pipe_fd[2];
	pid_t	child_pid;
	pid_t	received_child_pid;
	char	message[] = "Hello from the child! PID:";
	char	buffer[42];

	pipe(pipe_fd); // Pipe initialization
	child_pid = fork();

	if (child_pid == 0) // Child process
	{
		printf("I'm in child process\n");
		close(pipe_fd[0]); // Close the read end of the pipe
		write(pipe_fd[1], message, strlen(message) + 1); // Write message to the pipe
		write(pipe_fd[1], &child_pid, sizeof(pid_t)); // Write child PID to the pipe
		close(pipe_fd[1]); // Close the write end of the pipe
	}
	else // Parent process
	{
		close(pipe_fd[1]); // Close the write end of the pipe
		printf("Here is the parent! PID: %d\n", child_pid);
		read(pipe_fd[0], buffer, sizeof(buffer)); // Read message from pipe
		read(pipe_fd[0], &received_child_pid, sizeof(pid_t)); // Read child PID from pipe
		printf("The child says: '%s %d'\n", buffer, received_child_pid);
		close(pipe_fd[0]); // Close the read end of the pipe
	}

	return (0);
}