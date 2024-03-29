<h1 align="center">
	📖 get_next_line  
</h1>

<h3 align="center">
	<a href="#%EF%B8%8F-about">About</a>
	<span> · </span>
	<a href="#%EF%B8%8F-use">Use</a>
	<span> · </span>
	<a href="#-test">Test</a>
</h3>

---

## 💡 About the project

The get_next_line function in C serves the fundamental purpose of reading and processing a text file or other input stream, line by line. It's particularly useful for scenarios where you need to extract information or perform operations on each line of a file without loading the entire file into memory at once.

We have to handle the following situations:

    1. Reading and Concatenating Buffers: If the current read buffer from the file doesn't have a newline character
    ('\n'), you concatenate its contents with the previous buffer content. This step ensures that a line that spans
    multiple buffers is correctly handled.
    2. Processing Lines: If the read buffer contains a newline character ('\n'), you concatenate the buffer content
    up to the newline character with the previous buffer content. This creates a complete line that can be returned.
    3. End of File Handling: When you reach the end of the file (i.e., the read() function returns 0), you concatenate
    the buffer content with the previous buffer content. This is important to capture any remaining data that didn't
    end with a newline character.
    4. Allocating and Returning Line: After processing and concatenating the buffers, you allocate memory for a new
    string that contains the entire line without a newline character. This is the string that the function will return.
    5. Memory Management: You mentioned that you release the memory allocated for intermediate buffers and return values
    accordingly:1 if a newline was found, 0 for end of file, and -1 for any error or invalid parameter conditions.
    6. Error Handling: You've also noted that if there are issues with parameters (like BUFFER_SIZE being <= 0) or if
    memory allocation fails at any point, you free the allocated memory and return -1 to indicate an error.

Helper functions used:

1. ft_strlen: Determine the length of a null treminated string.
2. ft_strchr: Searches for a '\n' character in a string.
3. ft_strjoin: Concatenates two strings.
4. ft_get_line: Extracts a line from the 'rest'.
5. ft_new_rest: Creates a new 'rest' after extracting a line.
6. *ft_read_to_rest: Reads data from a file descriptor and appends it to the 'rest' buffer, which holds any leftover data from previous reads. This is a specific to 'get_next-line' logic helper function that located in get_next_line.c but not in get_next_line_utils.c.

## 🛠️ Use

### Requirements

The function is written in C language, compiles with **`gcc`**, and uses some standard **C libraries** to run.

### Instructions

**1. Implementation**

To use the function with your code, simply include its header:

```C
#include "get_next_line.h"
```

While compiling, add the source files and required flags:

```shell
get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=<size>
```

## 📋 Test

Just uncomment the main function with its headers inside the get_next_line.c file.
You can edit the text in the test.txt files to test other cases.
Then run the command below (change "xx" with desired buffer size):

```shell
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=xx get_next_line.c get_next_line_utils.c && ./a.out
```

You can also use third party tester to fully test project
Clone the tester directory(/get_next_line/gnlTester %)
Than run 'make' (/gnlTester % make)

* [Tripouille/gnlTester](https://github.com/Tripouille/gnlTester)
