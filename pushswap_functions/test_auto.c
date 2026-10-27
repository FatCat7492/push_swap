
// #include "pushswap.h"
// #include <stdio.h>

// typedef struct s_test
// {
// 	char	*name;
// 	char	*args[4];
// 	int		expected[6];
// 	int		count;
// 	int		error;
// }	t_test;

// static int	check_stack(t_stack *head, const int *values, int count)
// {
// 	int	i;

// 	i = 0;
// 	while (head && i < count)
// 	{
// 		if (head->value != values[i])
// 			return (0);
// 		head = head->next;
// 		i++;
// 	}
// 	return (i == count && head == NULL);
// }

// static int	run_test(const t_test *test)
// {
// 	t_stack	*head;
// 	int		i;
// 	int		error;
// 	int		pass;

// 	head = NULL;
// 	i = 0;
// 	error = 0;
// 	while (test->args[i] && !error)
// 		error = ft_parsing(test->args[i++], &head);
// 	pass = (error == test->error);
// 	if (!test->error)
// 		pass = pass && check_stack(head, test->expected, test->count);
// 	printf("[%s] %s\n", pass ? "OK" : "FAIL", test->name);
// 	ft_cleanstack(&head);
// 	return (pass);
// }

// int	main(void)
// {
// 	const t_test	tests[] = {
// 		{"Basic", {"42 10 -5"}, {42, 10, -5}, 3, 0},
// 		{"Separate args", {"42", "10", "-5"}, {42, 10, -5}, 3, 0},
// 		{"Mixed args", {"42 10", "5 -3"}, {42, 10, 5, -3}, 4, 0},
// 		{"INT limits", {"2147483647 -2147483648"},
// 			{2147483647, -2147483647 - 1}, 2, 0},
// 		{"Plus and zero", {"+42 -0 10"}, {42, 0, 10}, 3, 0},
// 		{"Duplicate", {"42 10 42"}, {0}, 0, 1},
// 		{"Cross-arg duplicate", {"42 10", "5 42"}, {0}, 0, 1},
// 		{"Overflow", {"2147483648"}, {0}, 0, 1},
// 		{"Underflow", {"-2147483649"}, {0}, 0, 1},
// 		{"Invalid letters", {"12abc"}, {0}, 0, 1},
// 		{"Sign only", {"+"}, {0}, 0, 1},
// 		{"Empty string", {""}, {0}, 0, 1},
// 		{"Spaces only", {"   "}, {0}, 0, 1},
// 		{"Duplicate zero", {"-0 +0"}, {0}, 0, 1},
// 		{"Invalid after nodes", {"  42 10 abc"}, {0}, 0, 1},
// 	};
// 	int	i;
// 	int	passed;
// 	int	total;

// 	i = 0;
// 	passed = 0;
// 	total = sizeof(tests) / sizeof(tests[0]);
// 	while (i < total)
// 	{
// 		passed += run_test(&tests[i]);
// 		i++;
// 	}
// 	printf("\nRESULT: %d/%d tests passed\n", passed, total);
// 	return (passed != total);
// }





#include "pushswap.h"
#include <stdio.h>

typedef struct s_test
{
	char	*name;
	char	*argv[10];
	int		values[8];
	int		count;
	int		strategy;
	int		bench;
}	t_test;

static int	stack_equals(t_stack *head, const int *values, int count)
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
	int		argc;
	int		bench;
	int		result;
	int		ok;

	head = NULL;
	argc = 0;
	bench = 0;
	while (test->argv[argc])
		argc++;
	result = ft_parsing_ultimate(argc, &bench,
			(char **)test->argv, &head);
	ok = (result == test->strategy);
	if (ok && result != -1)
		ok = (bench == test->bench
				&& stack_equals(head, test->values, test->count));
	printf("[%s] %s\n", ok ? "OK" : "KO", test->name);
	if (!ok)
		printf("  result=%d expected=%d bench=%d expected=%d\n",
			result, test->strategy, bench, test->bench);
	ft_cleanstack(&head);
	return (ok);
}

static const t_test	g_tests[] = {
	{"Default adaptive",
		{"./push_swap", "3", "1", "2", NULL},
		{3, 1, 2}, 3, 4, 0},
	{"Simple strategy",
		{"./push_swap", "--simple", "3", "2", "1", NULL},
		{3, 2, 1}, 3, 1, 0},
	{"Medium strategy",
		{"./push_swap", "--medium", "3", "1", "2", NULL},
		{3, 1, 2}, 3, 2, 0},
	{"Complex strategy",
		{"./push_swap", "--complex", "3", "1", "2", NULL},
		{3, 1, 2}, 3, 3, 0},
	{"Explicit adaptive",
		{"./push_swap", "--adaptive", "3", "1", "2", NULL},
		{3, 1, 2}, 3, 4, 0},
	{"Benchmark",
		{"./push_swap", "--bench", "3", "1", "2", NULL},
		{3, 1, 2}, 3, 4, 1},
	{"Benchmark and medium",
		{"./push_swap", "--bench", "--medium", "3", "2", NULL},
		{3, 2}, 2, 2, 1},
	{"Flags after numbers",
		{"./push_swap", "42", "-15", "--complex", "8", NULL},
		{42, -15, 8}, 3, 3, 0},
	{"Flags interleaved",
		{"./push_swap", "42", "--medium", "-15", "--bench", "8", NULL},
		{42, -15, 8}, 3, 2, 1},
	{"Quoted multiple numbers",
		{"./push_swap", "3 1 2", NULL},
		{3, 1, 2}, 3, 4, 0},
	{"Mixed quoted arguments",
		{"./push_swap", "--simple", "3 1", "2 -5", NULL},
		{3, 1, 2, -5}, 4, 1, 0},
	{"Negative numbers",
		{"./push_swap", "-42", "-1", "0", NULL},
		{-42, -1, 0}, 3, 4, 0},
	{"Integer boundaries",
		{"./push_swap", "-2147483648", "2147483647", NULL},
		{-2147483647 - 1, 2147483647}, 2, 4, 0},
	{"Positive sign",
		{"./push_swap", "+42", "-3", NULL},
		{42, -3}, 2, 4, 0},
	{"Single number",
		{"./push_swap", "42", NULL},
		{42}, 1, 4, 0},
	{"Repeated strategy",
		{"./push_swap", "--medium", "--medium", "42", NULL},
		{0}, 0, -1, 0},
	{"Conflicting strategies",
		{"./push_swap", "--simple", "--complex", "42", NULL},
		{0}, 0, -1, 0},
	{"Repeated benchmark",
		{"./push_swap", "--bench", "--bench", "42", NULL},
		{0}, 0, -1, 0},
	{"Unknown option",
		{"./push_swap", "--banana", "42", NULL},
		{0}, 0, -1, 0},
	{"Unknown option at end",
		{"./push_swap", "42", "--unknown", NULL},
		{0}, 0, -1, 0},
	{"Duplicate numbers",
		{"./push_swap", "42", "10", "42", NULL},
		{0}, 0, -1, 0},
	{"Duplicates across quoted arguments",
		{"./push_swap", "1 2", "3 2", NULL},
		{0}, 0, -1, 0},
	{"Positive overflow",
		{"./push_swap", "2147483648", NULL},
		{0}, 0, -1, 0},
	{"Negative overflow",
		{"./push_swap", "-2147483649", NULL},
		{0}, 0, -1, 0},
	{"Invalid alphabetic input",
		{"./push_swap", "12abc", NULL},
		{0}, 0, -1, 0},
	{"Empty argument",
		{"./push_swap", "", NULL},
		{0}, 0, -1, 0},
	{"Whitespace-only argument",
		{"./push_swap", "   ", NULL},
		{0}, 0, -1, 0},
	{"Sign without digits",
		{"./push_swap", "-", NULL},
		{0}, 0, -1, 0},
	{"Invalid double minus",
		{"./push_swap", "--42", NULL},
		{0}, 0, -1, 0},
	{"Invalid after valid numbers",
		{"./push_swap", "1", "2", "wrong", NULL},
		{0}, 0, -1, 0}
};

int	main(void)
{
	int	i;
	int	passed;
	int	total;

	i = 0;
	passed = 0;
	total = sizeof(g_tests) / sizeof(g_tests[0]);
	while (i < total)
	{
		passed += run_test(&g_tests[i]);
		i++;
	}
	printf("\n================================\n");
	printf("RESULT: %d / %d TESTS PASSED\n", passed, total);
	printf("================================\n");
	return (passed != total);
}
