<p align="center">
	<img alt="PIPEX BADGE" src="https://github.com/tesla33io/pipex/blob/main/badge.png?raw=true" width="200">
</p>

## Purpose

- To gain deeper understanding of how pipes and system calls work in Unix-like systems.

- To practice C programming skills like memory management, process handling, and I/O operations.


## What it does:

- Takes input from a file.

- Executes two or more commands in sequence, where the output of one command becomes the input for the next.

## My implementation

### 1. Check input

First of all, we need to make sure that the program receives the correct input data.

This can be done by checking the number of arguments our program received, if everything is as it should be (4 arguments without bonuses), and by checking that the input file exists and has the necessary rights (i.e., our program can read it).

> [!NOTE]
> If the input file does not exist, or the file does not have the 
> required permissions (`R_OK`), the program should notify the user that there is a problem with 
> the input file (by displaying an error in the terminal), but all commands (if 
> there are no problems with them) should be executed anyway.
>
> This is how `Bash` behaves in this case.

If the program receives the wrong number of arguments (`!=4`), in my implementation it 
will end its execution (by displaying a suitable message to the terminal) at this point.

```bash
[Stop programm execution.]
Error (check_input): invalid input.

Usage:	./pipex `INFILE` "CMD 1" "CMD 2" `OUTFILE`

	`INFILE`	- Input file for the program.
	`OUTFILE`	- Output file for the program.
	`CMD 1`		- First command to be executed.
	`CMD 2`		- Second command to be executed.
```

### 2. Open provided files

The second step is to open the files that the user has specified.

I did this as follows: first, I tried to open the output file, because I decided that 
if my program cannot use the provided output file, the execution will end
(In this case, you can also try to output the result to the terminal).

If the output file is okay, then I tried to open the input file. When opening the input 
file, we need to remember that if there are any problems with this file, the program 
should still continue execution, as `Bash` does.

> [!TIP]
> `/dev/null`

### 3. Parse commands with arguments

The next step is to get a list of commands from the arguments.

There are many different ways to get these commands. I decided to keep the command list 
in the structure I had.

After we have a list of commands, we need to get a list of arguments that the user can 
specify for these commands.

I did this quite simply, by spliting the string with the command and its arguments 
using `ft_split` and stored the resulting array in another array (`char ***`).

### 4. Pipe and execute

_coming soon.._


---
> [!NOTE]
> - if a command doesn't exist program **still continue to execute other cmds**.
> - if all commands don't exist program **just create an outfile**.
> - if infile doesn't exist, program **still execute all the commands and write to outfile**.