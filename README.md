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

	

The get_next_line function in C serves the fundamental purpose of reading and processing a text file or input stream line by line. It's particularly useful for scenarios where you need to extract information or perform operations on each line of a file without loading the entire file into memory at once.

We need to handle the following situations:

    If the read buffer doesn't have a '\n', we concatenate with the previous buffer and call read again.
    If the read buffer has a '\n', we concatenate with the previous buffer up to '\n'.
    If we reach the end of the file (read() == 0), we concatenate with the previous buffer.
    We finally point line to an allocated string that contains the entire line without the '\n'. Then we release the memory allocated in the intermediate strings and return 1 or 0 for '\n' and end_of_file respectively.
    If the parameters have any problems (BUFFER_SIZE <= 0), or if in any operation we were unable to allocate memory, we free whatever memory was allocated and return -1.


## 🛠️ Usage

### Requirements

The function is written in C language, compiles with **`gcc`**, and uses some standard **C libraries** to run.

### Instructions

**1. Using it in your code**

To use the function in your code, simply include its header:

```C
#include "get_next_line.h"
```

While compiling, add the source files and required flags:

```shell
get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=<size>
```

## 📋 Test

You only have to edit the get_next_line.c file and uncomment the main function and headers inside it.
You can edit test.txt files to put another text if you wish to test othe cases.
Then simply run this command (change "xx" with desired buffer size) :

```shell
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=xx get_next_line.c get_next_line_utils.c && ./a.out
```

Or you can also use this third party tester to fully test the project

* [Tripouille/gnlTester](https://github.com/Tripouille/gnlTester)