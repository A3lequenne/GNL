# get\_next\_line: Custom Implementation of Line Reading

## Overview

`get_next_line` is a custom implementation of a line-reading function in C that reads one line at a time from a file descriptor. It is similar in purpose to `fgets()`, but it reads from a file descriptor (`fd`) and allows the reading of very large files line by line, which can be useful for applications that need incremental processing.

## Functionality

The `get_next_line` function reads from a file descriptor and returns the next line each time it is called, until it reaches the end of the file. It handles input buffering using a static variable to remember any leftover characters after each line, allowing efficient reading.

### Key Components

- **`get_next_line()`**: The main function that reads a line from the file descriptor. It utilizes a static variable to store leftover content between function calls.
- **Helper Functions**:
  - **`read_line()`**: Reads content from the file descriptor and appends it to a buffer until a newline or EOF is reached.
  - **`take_line()`**: Extracts the current line from the buffer, up to and including the newline character.
  - **`take_next()`**: Stores the remaining characters after the newline for the next call.
  - **`ft_malloc()`**, **`ft_strlen()`**, **`ft_strchr()`**, **`ft_strjoin()`**: Utility functions for memory allocation, string manipulation, and joining strings.

### Example Usage

Below is an example of how to use the `get_next_line` function to read from a file descriptor, such as a file or standard input:

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("example.txt", O_RDONLY);
    char *line;

    if (fd < 0)
        return (1);

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

This example opens a file called `example.txt` and uses `get_next_line()` to read and print each line until the end of the file is reached.

## Compilation

To compile the code, use the provided `Makefile` to create the necessary object files and link them into your project. Make sure to define the `BUFFER_SIZE` during compilation to control the number of bytes read at each step.

```sh
make
```

This command will generate the necessary object files for `get_next_line`. You can link it with other C files to create your executable.

## Example Output

When reading a file that contains multiple lines, `get_next_line` will return each line separately, allowing easy processing.

```sh
Line 1: Hello, World!
Line 2: This is the second line.
...
```

## Limitations

The current implementation does not handle multi-line inputs efficiently when `BUFFER_SIZE` is too small, as it may require multiple iterations to read a complete line. Also, the performance may vary depending on the size of the buffer (`BUFFER_SIZE`). It is essential to choose a suitable value for `BUFFER_SIZE` based on the use case.

## Bonus Version

The bonus version of `get_next_line` extends the functionality to handle multiple file descriptors simultaneously. This allows reading from different files or inputs without losing track of each one's progress. The original version was designed with this functionality in mind, allowing seamless handling of multiple file descriptors.

## Conclusion

`get_next_line` is a useful utility for reading text data line by line in C. It demonstrates how to work with file descriptors, handle memory allocation dynamically, and manage static variables for continuous data processing across function calls. This implementation is useful for learning how to handle low-level I/O in C.