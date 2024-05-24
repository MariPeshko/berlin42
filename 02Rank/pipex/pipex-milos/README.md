# pipex

1 week to complete, another 2 weeks to struggle with the bonus. The knowledge was worth achieving as now I can focus on other issues when doing minishell.

* An amazing introductory article (worth 1,5 days of detailed reading and trying out) by rozmichelle: [Link](https://www.rozmichelle.com/pipes-forks-dups/) to blog
* Top article for reviewing concepts nearing the finish line or post-completing the project: [Link](https://csnotes.medium.com/pipex-tutorial-42-project-4469f5dd5901) to medium.com
* A non-introductory and not-quite-complete article which however complements the other two well: [Link](https://reactive.so/post/42-a-comprehensive-guide-to-pipex) to reactive.so

## The juice (of mainly the bonus part)

This is not how most articles start off, but there are enough articles on pipex out there, some contradicting each other, that I think it warrants a direct deep dive into the biggest conceptual challenges of pipex that I've personally faced.

### How to set up a pipeline capable of infinite length

You may have heard stories of people getting away with only 3 pipes, with only 2 pipes, or even with only a single pipe. One single pipe() call for the entire pipex_bonus, capable of streming data in pipelines of infinite length. Personally I'm not a fan of that record, because it obscures some already difficult to grasp concepts further by toying with the STD i/o of the parent process. So I've used two pipes which get reused if complex condition checks are passed. The arithmetic determining of which pipe to use when is complex too. But what I wasn't realizing conceptually is that the reusing of a pipe necessarily must happen in the parent process.

### Closing the fds in code, which constitute the pipeline, before they are actually used by the program?

This one still puzzles me, so perhaps just as placeholder until I understand it better:
> You should close any pipe ends (i.e. fds which were duped onto STD i/o) once you're done using them.
You may have repeatedly seen this piece of advice without a detailed explanation of the underlying mechanism. I don't have it either. But if it helps in deciphering the advice, I've got three bits of understanding to share:
1. What the advice is saying is once you've used your pair of fds in dup2() calls in the code, close them.
2. The reason behind 1. is to prevent interruptions to the order of things during execution time.
3. Kernel using them =/= you using them. With this assumption, try re-reading the quoted piece of advice.

### How to 'wait' on the odd process of here_doc
The behavior of here_doc in 42 documentation, i.e. here-doc in official documentation, i.e. ultimately the behavior of '<<' in Shell will prompt input until a limiter word (exact match) is met. Now this operation doesn't require an execve() call. Furthermore, you'll either be storing that input into a file, into a variable, or forwarding it directly into the pipeline (which was my approach). So you might be thinking "I don't need a child process for that". And you might be correct. However for the sake of cleanliness, why wouldn't you fork() for that operation? It works like a charm. Until it doesn't. Your waitpid() for that child process needs to happen before the next fork() in the code. And it's super easy to overlook, because in an error-free scenario the entire pipeline might work even if you wait for all your child process at the bottom of your program's code. But with errors present, odd behaviors come skimming which reveal that waitpid() can only be safely called at the far end of the code if we assume a 'state change' of the child process.
```man
WAIT(2)
...
A  state  change is considered to be: the child terminated; the child was stopped by a signal; or the child
was resumed by a signal.
```
I suppose neither of these apply when we have a get_next_line in a continous loop in that first child process, so the way I finally got my program to work properly in an error-filled environment intended for stress-testing was to waitpid() for the input prompting child process was as described above. The rest of the waitpid() calls (numbered properly) still gets called at the very bottom of the code. I suppose for compactness? I don't have a better explanation.

### Immitating the error handling of shell
strerror(errno) vs. perror("Your err message"): either is fine and the choice is pretty much yours. But during your stress-testing or otherwise you may wonder why neither of the two will replicate the exact message such as this one, which bash itself would print: `xxxx: command not found`, but instead once execve fails executing you'll end up seeing the errno ENOENT which translates to `No such file or directory` or alternatively you'll have used perror(cmdname) to format it into `<cmdname>: No such file or directory` . The reason for the discrepancy is that the aforementioned message which bash provides isn't handled by errno(3), but by bash itself (sort of manually). But before you go on setting it up manually however, there is a workaround.

* If you're trying to execute 'xxxx', your execve call needs `execve(..., {"xxxx", NULL}, ...)`.
* But if you feed it this: `execve(..., {"sh" "-c" "xxxx", NULL}, ...)` it will actually end up invoking another instance of Shell (yes, a subshell, for which internally it is likely forked yet another time from within your child process) such that you're delegating the error handling to that instance of Shell. And that should then indeed result in `xxxx: command not found`, though potentially jumbled around. The exact message will depend on your system's default shell, so whichever is situated at /bin/sh

Personally, I've 

## Pipex features:

Function | Includes
:--- | :---
[open](#open)	| #include <sys/types.h><br>#include <sys/stat.h><br>#include <fcntl.h>
[close](#close) | #include <unistd.h>
[read](#read) | #include <unistd.h>
[write](#write) | #include <unistd.h>
[malloc](#malloc) | #include <stdlib.h>
[free](#free) | #include <stdlib.h>
[perror](#perror) | #include <stdlib.h><br>#include <errno.h>
[strerror](#strerror) | #include <string.h> 
[access](#access) | #include <unistd.h><br>#include <fcntl.h>
[dup](#dup) | #include <fcntl.h> */\* optionally, to obtain O_\* constant definitions \*/*<br>#include <unistd.h>
[dup2](#dup2) | #include <fcntl.h> */\* optionally, to obtain O_\* constant definitions \*/*<br>#include <unistd.h>
[execve](#execve) | #include <unistd.h> 
[exit](#exit) | #include <stdlib.h>
[fork](#fork) | #include <sys/types.h><br>#include <unistd.h>
[pipe](#pipe) | #include <fcntl.h> */\* optionally, to obtain O_\* constant definitions \*/*<br>#include <unistd.h>
[unlink](#unlink) | #include <fcntl.> */\* optionally, to obtain definition of AT_\* constants \*/*<br>#include <unistd.h>
[wait](#wait) | #include <sys/types.h> <br> #include <sys/wait.h>
[waitpid](#waitpid) | #include <sys/types.h> <br> #include <sys/wait.h>

### The functions I actually used:
close, read, write, malloc, free, perror, access, dup2, execve, exit, fork, pipe, waitpid

~~strerror, dup, wait, unlink~~

## Program behavior

The pipex program will be executed as follows:
> ./pipex file1 cmd1 cmd2 file2

Pipex must behave exactly as the shell command below:
> < file1 cmd1 | cmd2 > file2

## Authorized functions overview


The trinity:
* pipe(arr)
* fork(void)
* dup2(arr[1], STDOUT_FILENO) || dup2(arr[0], STDIN_FILENO)

### open

We need this one to get the file descriptors which are necessary for piping.

<details>
	<summary>table</summary>
  
| Function | Description | Retval | Declaration | Example |
|  :---:  |   :---      | :---:  |  :---   | :--- |
| open  | The  open()  system call opens the file specified by pathname. | the new fd, or -1 if error | int open(const char *pathname, int flags, mode_t mode); | open() |
| -      |  required flags  | - | O_RDONLY <br> O_WRONLY or <br> O_RDWR | fd_read = open("./block.txt", O_RDONLY); |
| -      | optional modes (don't include it if you don't need it, it's a different declaration)  | - | O_CLOEXEC <br> O_CREAT <br> O_DIRECTORY <br> O_EXCL <br> O_NOCTTY <br> O_NOFOLLOW <br> O_TMPFILE and <br> O_TRUNC | - |

* O_CREAT and O_TRUNC actually require an additional mandatory permissions (in octal), added past a comma in format, say 0644 

</details> 

_________________________________________________

### close

We use this to close any file descriptors irrelevant to the current process. Note that 'close' does not close actual files.

<details>
	<summary>table</summary>

| Function | Description | Retval | Declaration | Example |
|  :---:  |   :---      | :---:  |  :---   | :--- |
| close | close()  closes  a  file  descriptor,  so  that it no longer refers to any file and may be reused. | close()  returns  zero  on  success.  On error, -1 is returned. Sets errno. | int close(int fd); | da |

</details>
_________________________________________________

### read
<details>
	<summary>table</summary>
  
| Function | Description | Retval | Declaration | Example |
|  :---:  |   :---      | :---:  |  :---   | :--- |
| read | read() attempts to read up to count bytes from file descriptor fd into the buffer starting at buf | Bytes read or less. 0 upon EOF. -1 if error. Sets errno. | ssize_t read(int fd, void *buf, size_t count); | da |

</details>
_________________________________________________

### write
<details>
	<summary>table</summary>
  
| Function | Description | Retval | Declaration | Example |
|  :---:  |   :---      | :---:  |  :---   | :--- |

</details>
_________________________________________________

### malloc

Likely to be needed as part of ft_strjoin and ft_split.

<details>
	<summary>table</summary>
  
| Function | Description | Retval | Declaration | Example |
|  :---:  |   :---      | :---:  |  :---   | :--- |

</details>
_________________________________________________

### free

If malloc, then free.

<details>
	<summary>table</summary>
  
| Function | Description | Retval | Declaration | Example |
|  :---:  |   :---      | :---:  |  :---   | :--- |

</details>
_________________________________________________

### perror

Concatenates and prints `"the_string_you_give_it_as_the_argument"` + `": "` + `"contents of errno in human-readable form"`

<details>
	<summary>table</summary>
  
| Function | Description | Retval | Declaration | Example |
|  :---:  |   :---      | :---:  |  :---   | :--- |
| perror | The  perror() function produces a message <br> on standard error describing the last error <br> encountered during a call to a system or <br> library function. [...] The function perror() <br> serves to translate 'errno' into <br> humanreadable form.| da | void perror(const char *s); | perror("Access error"); |

</details>

_________________________________________________

### strerror
<details>
	<summary>table</summary>
  
| Function | Description | Retval | Declaration | Example |
|  :---:  |   :---      | :---:  |  :---   | :--- |
| strerror | The strerror() function returns a pointer to a string that describes the error code passed in the  argument errnum, possibly using the LC_MESSAGES part of the current locale to select the appropriate language.  (For example, if errnum is EINVAL, the  returned  description  will  be  "Invalid argument".)  This string must not be modified by the application, but may be modified by a subsequent call to strerror() or strerror_l().  No other  library function, including perror(3), will modify this string. |  strerror() [...] return(s)  the  appropriate error description string, or an "Unknown error nnn" message if the error number is unknown. | char *strerror(int errnum); | da |

</details>
_________________________________________________

### access
<details>
	<summary>table</summary>

<table>
  <tr>
    <th colspan="2" align="left">access</th>
  </tr>
  <tr>
    <td>Description</td>
    <td>access() checks whether the calling process can access the file pathname. If pathname is a symbolic link, it is dereferenced. The mode specifies the accessibility check(s) to be performed, and  is  either the value F_OK, or a mask consisting of the bitwise OR of one or more of R_OK, W_OK, and X_OK.  F_OK tests for the existence of the file. R_OK, W_OK, and X_OK test whether the file exists and grants read, write, and execute permissions, respectively. <br><br>The  check is done using the calling process's real UID and GID, rather than the effective IDs as is done when actually attempting an operation (e.g., open(2)) on the  file. Similarly, for the root user, the check uses the set of permitted capabilities rather than the set of effective capabilities; and for non-root users, the check uses an empty set of  capabilities.</td>
  </tr>
  <tr>
    <td>Retval</td>
    <td>On  success (all requested permissions granted, or mode is F_OK and the file exists), zero is returned.  On error (at least one bit in mode asked for a permission that is denied, or mode is F_OK and the file does not exist, or some other error occurred), -1 is returned, and errno is set appropriately.</td>
  </tr>
  <tr>
    <td>Declaration</td>
    <td>int access(const char *pathname, int mode);</td>
  </tr>
  <tr>
    <td>Example</td>
    <td>if (access(cmdpath, X_OK) == 0)</td>
  </tr>
</table>

</details>
_________________________________________________

### dup
<details>
	<summary>table</summary>
  
| Function | Description | Retval | Declaration | Example |
|  :---:  |   :---      | :---:  |  :---   | :--- |
| dup  | The  dup()  system call creates a copy of the file descriptor oldfd, using the lowest-numbered unused file descriptor for the new descriptor. | On  success, dup() and dup2() system calls return the new file descriptor.  On error, -1. They set errno. | int dup(int oldfd); | da |

</details>
_________________________________________________

### dup2

It does more than "creating a copy". It is able to perform redirection by "duplicating oldfd onto newfd". The wording can be confusing whichever reading source you choose, so just note that (1) dup2 is called in child processes and (2) the data is redirected such that the child process can now either read from, or write to the **first** argument.

<details>
	<summary>table</summary>

<table>
  <tr>
    <th colspan="2" align="left">dup2</th>
  </tr>
  <tr>
    <td>Description</td>
    <td>The dup2() system call performs the same task as dup(), but instead of using  the  lowest-numbered  unused  file  descriptor, it uses the file descriptor number specified in newfd.</td>
  </tr>
  <tr>
    <td>Retval</td>
    <td>On success, dup() and dup2() system calls return the new file descriptor.  On error, -1. They set errno.() does not return. On error -1 is returned. Sets errno.</td>
  </tr>
  <tr>
    <td>Declaration</td>
    <td>int dup2(int oldfd, int newfd);</td>
  </tr>
  <tr>
    <td>Example 1</td>
    <td>dup2(fds[0], STDIN_FILENO);</td>
  </tr>
  <tr>
    <td>Example 2</td>
    <td>dup2(infile_fd, STDIN_FILENO);</td>
  </tr>
</table>

</details>

_________________________________________________

### execve

Way cooler than the man page lets believe. Once it is successfully called within a child process, the entire child process is replaced by the program execution and the function does not return.

<details>
	<summary>table</summary>
  
<table>
  <tr>
    <th colspan="2" align="left">execve</th>
  </tr>
  <tr>
    <td>Description</td>
    <td>execve - execute program</td>
  </tr>
  <tr>
    <td>Retval</td>
    <td>execve() does not return. On error -1 is returned. Sets errno.</td>
  </tr>
  <tr>
    <td>Declaration</td>
    <td>int execve(const char *pathname, char *const argv[], char *const envp[]);</td>
  </tr>
  <tr>
    <td>Example</td>
    <td>execve({"/bin/sh", {"sh", "-c", "ls -l", NULL}, envp);</td>
  </tr>
</table>

</details>

*Trivia time*: The weird placement of the asterisk for the arrays of strings in the declaration signifies that not the strings themselves are constant, but the array of strings. Meaning the array's content can't be swapped around, but the strings themselves may in fact be modified by the program. It doesn't much matter to this project, it just made me curious.
_________________________________________________

### *execvp
\* Disallowed in the project, only showing for comparison.

<details>
	<summary>table</summary>
  
| Function | Description | Retval | Declaration | Example |
|  :---:  |   :---      | :---:  |  :---   | :--- |
| *execvp | execl, execlp, execle, execv, execvp, execvpe - execute a file | The exec() functions return -1 upon error. They set errno. | int execvp(const char *file, char *const argv[]); | da |

</details>

_________________________________________________

### exit

<details>
	<summary>table</summary>

<table>
  <tr>
    <th colspan="2" align="left">exit</th>
  </tr>
  <tr>
    <td>Description</td>
    <td>The exit utility shall cause the shell to exit from its current execution environment with the exit status specified by the unsigned decimal integer n.  If the current execution environment  is  a  subshell environment, the shell shall exit from the subshell environment with the specified exit status and continue in the environment from  which  that  subshell environment  was  invoked; otherwise, the shell utility shall terminate with the specified exit status. If n is specified, but its value is not between 0 and  255  inclusively,  the exit status is undefined. | Exit with a true value: exit 0 <br> Exit with a false value: exit 1 <br></td>
  </tr>
  <tr>
    <td>Retval</td>
    <td>Exit with a true value: exit 0 <br> Exit with a false value: exit 1 <br></td>
  </tr>
  <tr>
    <td>Declaration</td>
    <td>SYNOPSIS: exit [n] <br> STDIN: Not used. <br> STDOUT: Not used.</td>
  </tr>
  <tr>
    <td>Example</td>
    <td>if (execvp(argv[0], argv) < 0) exit(0);</td>
  </tr>
</table>

</details>
_________________________________________________

### fork

'fork(void);' creates a copy of a process which includes its file descriptors. The copy (child) and the original (parent) are unaware of each other and changes performed to fds in one do not reflect in the other, but when we use pipes then it is the kernel that keeps track of those pipes.

<details>
	<summary>table</summary>

<table>
  <tr>
    <th colspan="2" align="left">fork</th>
  </tr>
  <tr>
    <td>Description</td>
    <td>fork()  creates  a new process by duplicating the calling process.  The new process is referred to as the child process.  The calling process is referred to as the parent process.</td>
  </tr>
  <tr>
    <td>Retval</td>
    <td>On  success,  the PID of the child process is returned in the parent, and 0 is returned in the child.  On failure, -1 is returned in the parent, no child process is created, and errno is set appropriately.</td>
  </tr>
  <tr>
    <td>Declaration</td>
    <td>pid_t fork(void);</td>
  </tr>
  <tr>
    <td>Example</td>
    <td>child1 = fork(void);</td>
  </tr>
</table>

</details>

_________________________________________________

### pipe

A 'pipe' call with an array of two integers as its argument will populate said array with two integers which we mostly use with dup2, mostly to replace STDIN_FILENO and STDOUT_FILENO in the appropriate processes with the ends of the pipe.

<details>
	<summary>table</summary>

<table>
  <tr>
    <th colspan="2" align="left">pipe</th>
  </tr>
  <tr>
    <td>Description</td>
    <td>The  pipe() function shall create a pipe and place two file descriptors, one each into the arguments fildes[0] and fildes[1], that refer to the open file descriptions for  the  read and  write  ends of the pipe.</td>
  </tr>
  <tr>
    <td>Retval</td>
    <td>Upon successful completion, 0 shall be returned; otherwise, -1. Sets errno.</td>
  </tr>
  <tr>
    <td>Declaration</td>
    <td>int pipe(int fildes[2]);</td>
  </tr>
  <tr>
    <td>Example</td>
    <td>pipe(fds); // where int fds[2];</td>
  </tr>
</table>

</details>

_________________________________________________

### unlink

<details>
	<summary>table</summary>
  
| Function | Description | Retval | Declaration | Example |
|  :---:  |   :---      | :---:  |  :---   | :--- |
| unlink | unlink() deletes a name from the filesystem.  If that name was the last link to a file and no processes have the file open, the file is deleted and the space it was using is made available for reuse. | On success, zero is returned.  On error, -1. Sets errno. | int unlink(const char *pathname); | da |

</details>
_________________________________________________

### wait

Since pid isn't passed to this function, I guess 'wait' is only suitable when there's a single child?

<details>
	<summary>table</summary>

<table>
  <tr>
    <th colspan="2" align="left">waitpid</th>
  </tr>
  <tr>
    <td>Description</td>
    <td>wait, waitpid, waitid - wait for process to change state <br><br> All of these  system calls are used to wait for state changes in a child of the calling process, and obtain information about the child whose state has changed. A  state change is considered to be: the child terminated; the child was stopped by a signal; or the child was resumed by a signal. In the case of a terminated child, performing a wait allows the system  to  release  the  resources associated with the child; if a wait is not performed, then the terminated child remains in a "zombie" state (see NOTES below). <br><br> If a child has already changed state, then these  calls  return  immediately. Otherwise, they block until either a child changes state or a signal handler interrupts the call (assuming that system calls are not automatically restarted  using  the  SA_RESTART  flag of sigaction(2)). In  the remainder of this page, a child whose state has changed and which has not yet been waited upon by one of these system calls is termed **waitable**.</td>
  </tr>
  <tr>
    <td>Retval</td>
    <td>On success, returns the process ID of the terminated child; on error, -1  is  returned. Sets errno.</td>
  </tr>
  <tr>
    <td>Declaration</td>
    <td>pid_t wait(int *wstatus);</td>
  </tr>
  <tr>
    <td>Example</td>
    <td>I'm not sure.<br>int status; <br> pid_t wpid = wait(&status); // wait for child to finish before exiting</td>
  </tr>
</table>

</details>
_________________________________________________

### waitpid

Using this listens on children processes and ensures a success of the programs' completion before the parent process exits.

<details>
	<summary>table</summary>

<table>
  <tr>
    <th colspan="2">waitpid</th>
  </tr>
  <tr>
    <td>Description</td>
    <td>wait, waitpid, waitid - wait for process to change state <br><br> All of these  system calls are used to wait for state changes in a child of the calling process, and obtain information about the child whose state has changed. A  state change is considered to be: the child terminated; the child was stopped by a signal; or the child was resumed by a signal. In the case of a terminated child, performing a wait allows the system  to  release  the  resources associated with the child; if a wait is not performed, then the terminated child remains in a "zombie" state (see NOTES below). <br><br> If a child has already changed state, then these  calls  return  immediately. Otherwise, they block until either a child changes state or a signal handler interrupts the call (assuming that system calls are not automatically restarted  using  the  SA_RESTART  flag of sigaction(2)). In  the remainder of this page, a child whose state has changed and which has not yet been waited upon by one of these system calls is termed **waitable**.</td>
  </tr>
  <tr>
    <td>Retval</td>
    <td>On  success,  returns  the process ID of the child whose state has changed; if WNOHANG was specified and one or more child(ren) specified by pid exist, but have not  yet changed state, then 0 is returned. On error, -1 is returned. Sets errno.</td>
  </tr>
  <tr>
    <td>Declaration</td>
    <td>pid_t waitpid(pid_t pid, int *wstatus, int options);</td>
  </tr>
  <tr>
    <td>Example</td>
    <td>int status; <br> pid_t wpid = waitpid(pid, &status, 0); // wait for child to finish before exiting</td>
  </tr>
</table>

</details>
_________________________________________________





## Errors of Shell piping to replicate

| Error | Cause | Where in code to handle it |
| :---  | :---  | :---      |
| 'zsh: no such file or directory: words3.txt' | - | in parsing? |
| 'mv: cannot stat 'words3.txt': No such file or directory' | - | ?? Print this? Or will Shell do it?? |
| sth piped to cmd1 or cmd2 ignored | cmd1 or cmd2 takes no input | in piping |
| cmd2 gets no stdin (wc -w will print 0) | nothing to pipe to cmd2 | in piping |
| mv: missing file operand <br> Try 'mv --help' for more information. | - | Shell should handle this? |

