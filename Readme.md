# LIBFT Project

This repository contains a complete implementation of three foundational C libraries: `libft`, `printf`, and `gnl` (Get Next Line). Each library is designed to be modular and can be used independently for various projects. You can compile them separately using the commands `make libft`, `make printf`, and `make gnl`. Ensure you include the respective header files in your projects for proper functionality.

## Table of Contents

- [LIBFT](#libft)
- [PRINTF](#printf)
- [GNL (Get Next Line)](#gnl-get-next-line)
- [Usage](#usage)
- [Examples](#examples)
- [License](#license)

---

## LIBFT

`libft` is a personalized implementation of commonly used standard C library functions. It includes utilities for string manipulation, memory handling, linked lists, and more.

### Features
- Custom replacements for standard functions such as `strlen`, `memset`, and `strncpy`.
- Extended utilities like `ft_split` for splitting strings and `ft_itoa` for integer-to-string conversion.
- Basic linked list operations: create, add, remove, and iterate through list elements.

### Highlighted Functions
- `ft_strlen`: Calculate the length of a string.
- `ft_itoa`: Convert an integer to a string.
- `ft_split`: Split a string into an array using a delimiter.
- `ft_lstnew`: Create a new linked list node.

---

## PRINTF

`printf` is a simplified recreation of the standard `printf` function, supporting formatted output for various data types.

### Features
- **Format Specifiers:** `%d`, `%i`, `%u`, `%x`, `%X`, `%c`, `%s`, `%p`, and `%%`.
- **Modifiers:** Handles width, precision, and flags like `-`, `+`, `0`, `#`, and space.
- Easy-to-integrate solution for formatted output in embedded or custom systems.

### Example
```c
ft_printf("Hello, 42! This is an integer: %d and a hex: %x\n", 42, 255);
```

---

## GNL (Get Next Line)

`gnl` provides an efficient way to read lines from file descriptors, even for large files or when managing multiple files simultaneously.

### Features
- Reads one line at a time, making it memory-efficient for large files.
- Handles multiple file descriptors concurrently.
- Avoids memory leaks through robust buffer management.

---

## Usage

### Compiling the Libraries
To build the libraries:
```bash
make
```
This will create the `libft.a` archive containing all three libraries.

### Using Individual Libraries
You can compile each library independently:
```bash
make libft
make printf
make gnl
```

### Including in Your Projects
1. Add the header files:
   ```c
   #include "libft.h"
   #include "pr_printf.h"
   #include "get_next_line.h"
   ```
2. Link the compiled archive:
   ```bash
   cc -Wall -Wextra -Werror -Iincludes <your_file.c> libft.a -o <your_output>
   ```

---

## Examples

### Testing All Libraries
Here's a combined test program to showcase the capabilities of all three libraries:

```c
#include "libft.h"
#include "pr_printf.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	// Testing LIBFT
	printf("=== LIBFT ===\n");
	char *str = ft_strdup("Hello, Libft!");
	printf("Duplicated string: %s\n", str);
	free(str);

	// Testing PRINTF
	printf("\n=== PRINTF ===\n");
	ft_printf("Formatted output: Integer: %d, Hex: %x, String: %s\n", 42, 255, "Hello!");

	// Testing GNL
	printf("\n=== GET NEXT LINE ===\n");
	int fd = open("test_file.txt", O_RDONLY);
	if (fd < 0) {
		perror("Error opening file");
		return 1;
	}
	char *line;
	while ((line = get_next_line(fd)) != NULL) {
		printf("%s", line);
		free(line);
	}
	close(fd);

	return 0;
}
```

### Running the Test
To compile and run:
```bash
cc -Wall -Wextra -Werror -Iincludes test.c libft.a -o test_program
./test_program
```

---

## License

This project is released under the MIT License. For details, refer to the [LICENSE](LICENSE) file.
