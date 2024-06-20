#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
# include <fcntl.h> 

void	forkexample(void)
{
	int		x;
	pid_t	p;
	int fd[2];
	int pp_ret;
	int	file;

	file = open("output.txt", O_WRONLY);

	x = 1;
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
		dup2(fd[1], file);
		close(fd[1]);
		printf("Child has x = %d\n", ++x);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		//printf("Parent has x = %d\n", --x);
	}
}
int	main(void)
{
	forkexample();
	return (0);
}
