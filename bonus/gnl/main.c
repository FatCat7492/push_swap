
// #include "get_next_line.h"
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <fcntl.h>
// #include <unistd.h>

// static int	g_pass = 0;
// static int	g_fail = 0;

// static void	check_line(int fd, const char *expected)
// {
// 	char	*line;
// 	int		ok;

// 	line = get_next_line(fd);
// 	if (!expected)
// 		ok = (line == NULL);
// 	else
// 		ok = (line && strcmp(line, expected) == 0);
// 	if (ok)
// 	{
// 		printf("  PASS\n");
// 		g_pass++;
// 	}
// 	else
// 	{
// 		printf("  FAIL | Expected: [%s] | Got: [%s]\n",
// 			expected ? expected : "NULL", line ? line : "NULL");
// 		g_fail++;
// 	}
// 	free(line);
// }

// static void	test_file(const char *name, const char *content,
// 	const char **expected, int count)
// {
// 	int	fd;
// 	int	i;

// 	printf("\n=== %s ===\n", name);
// 	fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0600);
// 	if (fd < 0)
// 	{
// 		perror("open write");
// 		exit(1);
// 	}
// 	if (write(fd, content, strlen(content)) != (ssize_t)strlen(content))
// 	{
// 		perror("write");
// 		close(fd);
// 		exit(1);
// 	}
// 	close(fd);
// 	fd = open(name, O_RDONLY);
// 	if (fd < 0)
// 	{
// 		perror("open read");
// 		exit(1);
// 	}
// 	i = 0;
// 	while (i < count)
// 	{
// 		printf("  Line %d:", i + 1);
// 		check_line(fd, expected[i]);
// 		i++;
// 	}
// 	printf("  EOF:");
// 	check_line(fd, NULL);
// 	close(fd);
// 	unlink(name);
// }

// static void	test_invalid_fd(void)
// {
// 	int	fd;

// 	printf("\n=== INVALID FD (-1) ===\n");
// 	check_line(-1, NULL);
// 	printf("\n=== CLOSED FD ===\n");
// 	fd = open("gnl_closed.tmp", O_WRONLY | O_CREAT | O_TRUNC, 0600);
// 	if (fd < 0)
// 		exit(1);
// 	close(fd);
// 	check_line(fd, NULL);
// 	unlink("gnl_closed.tmp");
// }

// static void	test_stdin(void)
// {
// 	int	pipefd[2];

// 	printf("\n=== STANDARD INPUT (fd 0) ===\n");
// 	if (pipe(pipefd) == -1)
// 		exit(1);
// 	if (write(pipefd[1], "stdin test\n", 11) != 11)
// 		exit(1);
// 	close(pipefd[1]);
// 	if (dup2(pipefd[0], STDIN_FILENO) == -1)
// 		exit(1);
// 	close(pipefd[0]);
// 	check_line(STDIN_FILENO, "stdin test\n");
// 	check_line(STDIN_FILENO, NULL);
// }

// int	main(void)
// {
// 	const char	*normal[] = {"Hello\n", "World\n", "42"};
// 	const char	*newlines[] = {"\n", "\n", "Hello\n", "\n"};
// 	const char	*single[] = {"A"};
// 	const char	*only_newline[] = {"\n"};
// 	const char	*long_lines[] = {
// 		"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789\n",
// 		"End"
// 	};

// 	printf("GET_NEXT_LINE TESTS | BUFFER_SIZE=%d\n", BUFFER_SIZE);
// 	test_file("gnl_empty.tmp", "", NULL, 0);
// 	test_file("gnl_normal.tmp", "Hello\nWorld\n42", normal, 3);
// 	test_file("gnl_newlines.tmp", "\n\nHello\n\n", newlines, 4);
// 	test_file("gnl_single.tmp", "A", single, 1);
// 	test_file("gnl_only_newline.tmp", "\n", only_newline, 1);
// 	test_file("gnl_long.tmp",
// 		"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789\nEnd",
// 		long_lines, 2);
// 	test_invalid_fd();
// 	test_stdin();
// 	printf("\n========================\n");
// 	printf("PASSED: %d | FAILED: %d\n", g_pass, g_fail);
// 	return (g_fail != 0);
// }
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	int		fd;
//	int		i;
	char	*line;

	fd = open("test1.txt", O_RDONLY);
	if (fd == -1)
		return (perror("open"), 1);
	//i = 1;
	line = get_next_line(fd);
	//while (line)
	//{
		printf("%s", line);
	//	printf("Line %d: [%s]\n", i, line);
		free(line);
		//i++;
		//line = get_next_line(fd);
//	}
	close(fd);
	return (0);
}

// for size in 1 2 4 42 10000; do
//     echo "========== BUFFER_SIZE=$size =========="
//     cc -Wall -Wextra -Werror -g -fsanitize=address \
//         -D BUFFER_SIZE=$size \
//         main.c get_next_line.c get_next_line_utils.c \
//         && ./a.out
// 	done