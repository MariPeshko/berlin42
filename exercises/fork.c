#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
 
// The 'pid_t pid' value changes during the execution
// of the program.
// When you call fork(), a new process (child process) is
// created by duplicating the existing process (parent process).

int main()
{
    pid_t   pid;

    pid = fork();
    if (pid == 0)
    {
        // Child process
        printf("I am the child process\n");
    }
    else if (pid > 0)
    {
        // Parent process
        printf("I am the parent process\n");
    }
    return 0;
}