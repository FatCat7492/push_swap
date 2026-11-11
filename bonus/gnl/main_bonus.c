
#include "get_next_line_bonus.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

static int	g_pass = 0;
static int	g_fail = 0;

static void	check(int fd, const char *expected, const char *name)
{
	char	*line;
	int		ok;

	line = get_next_line(fd);
	if (!expected)
		ok = (line == NULL);
	else
		ok = (line && strcmp(line, expected) == 0);
	if (ok)
	{
		printf("  PASS | %s\n", name);
		g_pass++;
	}
	else
	{
		printf("  FAIL | %s\n", name);
		printf("       Expected: [%s]\n",
			expected ? expected : "NULL");
		printf("       Got:      [%s]\n",
			line ? line : "NULL");
		g_fail++;
	}
	free(line);
}

static void	make_file(const char *name, const char *content)
{
	int		fd;
	size_t	len;
	ssize_t	written;

	fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (fd == -1)
	{
		perror("open");
		exit(1);
	}
	len = strlen(content);
	written = write(fd, content, len);
	if (written < 0 || (size_t)written != len)
	{
		perror("write");
		close(fd);
		exit(1);
	}
	close(fd);
}

static int	open_file(const char *name)
{
	int	fd;

	fd = open(name, O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		exit(1);
	}
	return (fd);
}

static void	test_alternating(void)
{
	int	fd1;
	int	fd2;
	int	fd3;

	printf("\n=== TEST 1: THREE FDs ALTERNATING ===\n");
	make_file("bonus1.tmp", "A1\nA2\nA3");
	make_file("bonus2.tmp", "B1\nB2\nB3");
	make_file("bonus3.tmp", "C1\nC2\nC3");
	fd1 = open_file("bonus1.tmp");
	fd2 = open_file("bonus2.tmp");
	fd3 = open_file("bonus3.tmp");
	check(fd1, "A1\n", "FD1 line 1");
	check(fd2, "B1\n", "FD2 line 1");
	check(fd3, "C1\n", "FD3 line 1");
	check(fd2, "B2\n", "FD2 line 2");
	check(fd1, "A2\n", "FD1 line 2");
	check(fd3, "C2\n", "FD3 line 2");
	check(fd3, "C3", "FD3 last line");
	check(fd1, "A3", "FD1 last line");
	check(fd2, "B3", "FD2 last line");
	check(fd1, NULL, "FD1 EOF");
	check(fd2, NULL, "FD2 EOF");
	check(fd3, NULL, "FD3 EOF");
	close(fd1);
	close(fd2);
	close(fd3);
	unlink("bonus1.tmp");
	unlink("bonus2.tmp");
	unlink("bonus3.tmp");
}

static void	test_empty_and_newlines(void)
{
	int	fd1;
	int	fd2;
	int	fd3;

	printf("\n=== TEST 2: EMPTY AND NEWLINES ===\n");
	make_file("bonus_empty.tmp", "");
	make_file("bonus_nl.tmp", "\n\n\n");
	make_file("bonus_text.tmp", "Hello\nWorld\n");
	fd1 = open_file("bonus_empty.tmp");
	fd2 = open_file("bonus_nl.tmp");
	fd3 = open_file("bonus_text.tmp");
	check(fd2, "\n", "Newline 1");
	check(fd3, "Hello\n", "Text line 1");
	check(fd1, NULL, "Empty file EOF");
	check(fd2, "\n", "Newline 2");
	check(fd3, "World\n", "Text line 2");
	check(fd2, "\n", "Newline 3");
	check(fd3, NULL, "Text EOF");
	check(fd2, NULL, "Newline EOF");
	check(fd1, NULL, "Empty EOF again");
	close(fd1);
	close(fd2);
	close(fd3);
	unlink("bonus_empty.tmp");
	unlink("bonus_nl.tmp");
	unlink("bonus_text.tmp");
}

static void	test_long_lines(void)
{
	int	fd1;
	int	fd2;

	printf("\n=== TEST 3: LONG LINES ===\n");
	make_file("bonus_long.tmp",
		"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789\n"
		"END");
	make_file("bonus_short.tmp", "X\nY");
	fd1 = open_file("bonus_long.tmp");
	fd2 = open_file("bonus_short.tmp");
	check(fd2, "X\n", "Short line 1");
	check(fd1,
		"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789\n",
		"Long line");
	check(fd2, "Y", "Short last line");
	check(fd1, "END", "Long file last line");
	check(fd2, NULL, "Short EOF");
	check(fd1, NULL, "Long EOF");
	close(fd1);
	close(fd2);
	unlink("bonus_long.tmp");
	unlink("bonus_short.tmp");
}

static void	test_invalid(void)
{
	int	fd;

	printf("\n=== TEST 4: INVALID FDs ===\n");
	check(-1, NULL, "Negative FD");
	fd = open_file("get_next_line_bonus.c");
	close(fd);
	check(fd, NULL, "Closed FD");
}

static void	test_many_fds(void)
{
	int		fd[20];
	int		i;
	char	name[40];
	char	content[40];

	printf("\n=== TEST 5: 20 SIMULTANEOUS FDs ===\n");
	i = 0;
	while (i < 20)
	{
		snprintf(name, sizeof(name), "bonus_many_%d.tmp", i);
		snprintf(content, sizeof(content), "FD%d line1\nFD%d line2\n",
			i, i);
		make_file(name, content);
		fd[i] = open_file(name);
		i++;
	}
	i = 19;
	while (i >= 0)
	{
		snprintf(content, sizeof(content), "FD%d line1\n", i);
		check(fd[i], content, "First line, reverse order");
		i--;
	}
	i = 0;
	while (i < 20)
	{
		snprintf(content, sizeof(content), "FD%d line2\n", i);
		check(fd[i], content, "Second line, forward order");
		check(fd[i], NULL, "EOF");
		close(fd[i]);
		snprintf(name, sizeof(name), "bonus_many_%d.tmp", i);
		unlink(name);
		i++;
	}
}

int	main(void)
{
	printf("====================================\n");
	printf(" GET_NEXT_LINE BONUS TEST SUITE\n");
	printf(" BUFFER_SIZE = %d\n", BUFFER_SIZE);
	printf("====================================\n");
	test_alternating();
	test_empty_and_newlines();
	test_long_lines();
	test_invalid();
	test_many_fds();
	printf("\n====================================\n");
	printf(" PASSED: %d\n", g_pass);
	printf(" FAILED: %d\n", g_fail);
	printf("====================================\n");
	return (g_fail != 0);
}



// #include "get_next_line_bonus.h"
// #include <stdio.h>
// #include <stdlib.h>
// #include <fcntl.h>
// #include <unistd.h>

// int	main(void)
// {
// 	char	*files[] = {
// 		"test1.txt",
// 		"test2.txt",
// 		"test3.txt",
// 		NULL
// 	};
// 	int		fd[1024];
// 	int		finished[1024] = {0};
// 	int		total;
// 	int		i;
// 	int		active;
// 	char	*line;

// 	total = 0;
// 	while (files[total])
// 		total++;
// 	if (total > 1024)
// 		return (printf("trop de fichier\n"), 1);

// 	i = 0;
// 	while (i < total)
// 	{
// 		fd[i] = open(files[i], O_RDONLY);
// 		if (fd[i] == -1)
// 		{
// 			perror(files[i]);
// 			finished[i] = 1;
// 		}
// 		else
// 			printf("Ouvert: %s (fd = %d)\n", files[i], fd[i]);
// 		i++;
// 	}

// 	printf("\n== START Lecture ==\n");

// 	active = 1;
// 	while (active)
// 	{
// 		active = 0;
// 		i = 0;
// 		while (i < total)
// 		{
// 			if (!finished[i])
// 			{
// 				line = get_next_line(fd[i]);
// 				if (line)
// 				{
// 					printf("\n[%s | FD %d]\n", files[i], fd[i]);
// 					printf("Ligne: [%s]\n", line);
// 					free(line);
// 					active = 1;
// 				}
// 				else
// 				{
// 					printf("\n[%s] EOF\n", files[i]);
// 					finished[i] = 1;
// 					close(fd[i]);
// 				}
// 			}
// 			i++;
// 		}
// 	}

// 	printf("\n== FINI ==\n");
// 	return (0);
// }
