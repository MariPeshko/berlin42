# Get Next Line
The `get_next_line` function is designed to return content of the file line by line.
## How it works?

```
.
├── get_next_line.c
├── get_next_line.h
└── get_next_line_utils.c
```

- `get_next_line.c` - is a basic file that contains a function declaration and performs the basic steps to perform a task, i.e., reading the contents of a file.
- `get_next_line_utils.c` - contains additional functions that are necessary for the main one (`get_next_line()`).
- `get_next_line.h` - is a header, its task is to link the two previous files together, as well as to provide the ability to use the main function in other files by importing this header file.

### `get_next_line.c`

This file contains 5 functions that perform the main task.

- `char *get_next_line(int fd);`
	
	This function aims to read a file descriptor (`fd`) line by line and return the next line from
	that file each time it's called.
	1. **Validation:** It first checks if the file descriptor `fd` is valid (not less than zero), if the buffer size is also valid (bigger than zero), and if reading from the file descriptor possible (`read(fd, 0, 0) < 0`, if this returns **-1**, it means that the file cannot be read).
	2. **Reading from File Descriptor:** It reads from the file descriptor using a function `read_file()` to fill or update a [static](https://www.geeksforgeeks.org/static-variables-in-c/) buffer.
	3. **Processing the Buffer:** It then processes the buffer to find and return the line of content using a function `get_line()`.
	4. **Updating the Buffer:** It updates the buffer by removing the portion of the buffer that will be returned (the part before `\n`) using `get_next()` function, preparing it for the next call.
	5. **Finally:** It returns the line that was read.
- `char *read_file(int fd, char *content);`
	
	This function is responsible for reading content from a file descriptor and appending it to an existing content buffer.
	1. **Initialization:** If the content buffer is empty, it initializes it with a single null byte using `ft_calloc()`.
	2. **Buffer Allocation:** It allocates memory for a temporary `read_buffer` of size `(BUFFER_SIZE + 1)` using `ft_calloc()`.
	3. **Reading from File Descriptor:** It reads from the file descriptor into the `read_buffer` maximum of `BUFFER_SIZE` bytes.
	4. **Buffer Manipulation:** It null-terminates the `read_buffer`. Then, it appends the content of `read_buffer` to the existing content using `append()`.
	5. **Check for New Line:** It checks if `\n` exists in the `read_buffer`. If found, it breaks out of the loop.
	6. **Loop:** The loop continues reading from the file until either an error occurs, a newline character is encountered, or until it reaches the end of the file.
	7. **Finish:** After the loop ends, it frees the memory allocated for the temporary buffer and returns the updated `content`.
- `char *get_line(char *buffer);`
	
	This function extracts a single line from the given `buffer`.
	1. **Line Extraction:** It iterates through the `buffer` until it finds `\n` or reaches the end of the string.
	2. **Memory Allocation:** It allocates memory for a new `line` buffer to hold the extracted line. The size allocated is `i + 2` (2, because `\n` and `\0`).
	3. **Copying Characters:** It copies characters from the `buffer` into the `line`.
	4. **Finish:** It returns the `line`.
- `char *get_next(char *buffer);`
	
	This function is designed to update the `buffer` by removing the first line and return the rest of the content.
	1. **Finding the New Line char:** It iterates through the `buffer` until it finds `\n`.
	2. **Check for Line End:** It checks if there is something after `\n` or if the `buffer` is not `NULL`. If not, it frees the `buffer` and return `NULL`.
	3. **Memory Allocation:** It allocates memory for `new_buffer` to hold the remaining content after `\n`.
	4. **Copying Remaining Content:** It copies the remaining content from the `buffer` into the `new_buffer`.
	5. **Memory Cleanup:** It frees the entire original `buffer`.
	6. **Finish:** It returns the `new_buffer`.

## How to use?
Some examples demonstrating how `get_next_line` function might be used.

### Example 1: Reading from a File Descriptor

```C
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main()
{
	int fd = open("example.txt", O_RDONLY); // Open a file for reading
	char *line;
	// Read lines from the file descriptor until the end of file (or error)
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Line: %s\n", line);
		free(line); // Free the line memory after use
	}
	close(fd); // Close the file descriptor
	return 0;
}
```

### Example 2: Reading from Standard Input (Terminal)

```C
#include <stdio.h>
#include "get_next_line.h"

int main() {
    char *line;
    // Read lines from standard input until user exits (Ctrl + D / Ctrl + Z)
    while ((line = get_next_line(0)) != NULL) {
        printf("You typed: %s\n", line);
        free(line); // Free the line memory after use
    }
    return 0;
}
```