#include "libft.h"
#include "pr_printf.h"
#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h> // Pour close()

void test_libft(void)
{
	printf("\n========== Testing libft ==========\n");

	// Test ft_strlen
	char *str = "Hello, 42!";
	printf("ft_strlen(\"%s\") = %zu\n", str, ft_strlen(str));

	// Test ft_atoi
	char *num = "12345";
	printf("ft_atoi(\"%s\") = %d\n", num, ft_atoi(num));

	// Test ft_strdup
	char *dup = ft_strdup(str);
	printf("ft_strdup(\"%s\") = \"%s\"\n", str, dup);
	free(dup);

	// Test ft_split
	char **split = ft_split("Hello,World,42", ',');
	printf("ft_split(\"Hello,World,42\", ','):\n");
	for (int i = 0; split[i]; i++)
	{
		printf("  [%d]: %s\n", i, split[i]);
		free(split[i]);
	}
	free(split);

	// Test ft_itoa
	int num_val = -42;
	char *itoa_result = ft_itoa(num_val);
	printf("ft_itoa(%d) = \"%s\"\n", num_val, itoa_result);
	free(itoa_result);
}

void test_printf(void)
{
	printf("\n========== Testing ft_printf ==========\n");

	// Basic printing
	ft_printf("ft_printf: Hello, 42!\n");

	// Printing integers
	ft_printf("ft_printf: Integer: %d\n", 42);
	ft_printf("ft_printf: Negative Integer: %d\n", -42);

	// Printing hexadecimal
	ft_printf("ft_printf: Hexadecimal: %x\n", 255);

	// Printing strings
	ft_printf("ft_printf: String: %s\n", "Hello, ft_printf!");

	// Printing pointers
	int value = 42;
	ft_printf("ft_printf: Pointer: %p\n", &value);
}

void test_gnl(void)
{
	printf("\n========== Testing get_next_line ==========\n");

	const char *test_file = "test_file.txt";

	// Create the file if it doesn't exist
	FILE *file = fopen(test_file, "r");
	if (!file)
	{
		file = fopen(test_file, "w");
		if (!file)
		{
			perror("Error creating test file");
			return;
		}
		for (int i = 0; i < 10; i++)
		{
			fprintf(file, "This is line number %d\n", i + 1);
		}
		fclose(file);
		printf("Test file '%s' created successfully.\n", test_file);
	}
	else
		fclose(file);

	// Open file descriptor for testing
	int fd = open(test_file, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening test file");
		return;
	}

	// Read lines with get_next_line
	char *line;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("get_next_line: \"%s\"\n", line);
		free(line);
	}
	close(fd);

	// Cleanup: remove the test file
	if (remove(test_file) == 0)
		printf("Test file '%s' removed successfully.\n", test_file);
	else
		perror("Error removing test file");
}

int main(void)
{
	test_libft();
	test_printf();
	test_gnl();
	return 0;
}
