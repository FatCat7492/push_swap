
#include "pushswap.h"
#include <stdio.h>

typedef struct s_test
{
	char	*name;
	char	*args[4];
	int		expected[6];
	int		count;
	int		error;
}	t_test;

static int	check_stack(t_stack *head, const int *values, int count)
{
	int	i;

	i = 0;
	while (head && i < count)
	{
		if (head->value != values[i])
			return (0);
		head = head->next;
		i++;
	}
	return (i == count && head == NULL);
}

static int	run_test(const t_test *test)
{
	t_stack	*head;
	int		i;
	int		error;
	int		pass;

	head = NULL;
	i = 0;
	error = 0;
	while (test->args[i] && !error)
		error = ft_parsing(test->args[i++], &head);
	pass = (error == test->error);
	if (!test->error)
		pass = pass && check_stack(head, test->expected, test->count);
	printf("[%s] %s\n", pass ? "OK" : "FAIL", test->name);
	ft_cleanstack(&head);
	return (pass);
}

int	main(void)
{
	const t_test	tests[] = {
		{"Basic", {"42 10 -5"}, {42, 10, -5}, 3, 0},
		{"Separate args", {"42", "10", "-5"}, {42, 10, -5}, 3, 0},
		{"Mixed args", {"42 10", "5 -3"}, {42, 10, 5, -3}, 4, 0},
		{"INT limits", {"2147483647 -2147483648"},
			{2147483647, -2147483647 - 1}, 2, 0},
		{"Plus and zero", {"+42 -0 10"}, {42, 0, 10}, 3, 0},
		{"Duplicate", {"42 10 42"}, {0}, 0, 1},
		{"Cross-arg duplicate", {"42 10", "5 42"}, {0}, 0, 1},
		{"Overflow", {"2147483648"}, {0}, 0, 1},
		{"Underflow", {"-2147483649"}, {0}, 0, 1},
		{"Invalid letters", {"12abc"}, {0}, 0, 1},
		{"Sign only", {"+"}, {0}, 0, 1},
		{"Empty string", {""}, {0}, 0, 1},
		{"Spaces only", {"   "}, {0}, 0, 1},
		{"Duplicate zero", {"-0 +0"}, {0}, 0, 1},
		{"Invalid after nodes", {"  42 10 abc"}, {0}, 0, 1},
	};
	int	i;
	int	passed;
	int	total;

	i = 0;
	passed = 0;
	total = sizeof(tests) / sizeof(tests[0]);
	while (i < total)
	{
		passed += run_test(&tests[i]);
		i++;
	}
	printf("\nRESULT: %d/%d tests passed\n", passed, total);
	return (passed != total);
}
