#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

// When you create a new process using fork(),
// the parent process receives the child process’s 
// PID as the return value of fork().
int main() {
    pid_t pid;
    pid = fork();
    if (pid == 0)
    {
        // Child process
        printf("Child PID: %d\n", getpid());
    }
    else if (pid > 0)
    {
        // Parent process
        printf("Parent PID: %d\n", getpid());
    }
    return 0;
}
