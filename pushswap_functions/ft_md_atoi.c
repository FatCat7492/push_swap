/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgrandj <crgrandj@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 21:45:16 by crgrandj          #+#    #+#             */
/*   Updated: 2026/10/26 16:17:37 by crgrandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_md_atoi(const char *str, int *check)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	if (!check)
		return (0);
	if (!str)
		return (ft_fail(check));
	*check = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i++] - '0') * sign;
		if (res > INT_MAX || res < INT_MIN)
			return (ft_fail(check));
	}
	return (res);
}

int	ft_fail(int *check)
{
	*check = 1;
	return (0);
}

// #include <limits.h>

// #define GREEN "\033[32m"
// #define RED   "\033[31m"
// #define RESET "\033[0m"

// static int	g_tests = 0;
// static int	g_failed = 0;

// static void	test_atoi(const char *str)
// {
// 	int	expected;
// 	int	actual;

// 	g_tests++;
// 	expected = atoi(str);
// 	actual = ft_atoi(str);
// 	if (expected == actual)
// 		printf(GREEN "[OK]" RESET "  \"%s\" -> %d\n", str, actual);
// 	else
// 	{
// 		g_failed++;
// 		printf(RED "[KO]" RESET "  \"%s\"\n", str);
// 		printf("      expected: %d\n", expected);
// 		printf("      actual:   %d\n", actual);
// 	}
// }

// int	main(void)
// {
// 	printf("\n");
// 	printf("========================================\n");
// 	printf("           FT_ATOI TESTER\n");
// 	printf("========================================\n\n");

// 	/* Basic numbers */
// 	printf("---- BASIC NUMBERS ----\n");
// 	test_atoi("0");
// 	test_atoi("1");
// 	test_atoi("42");
// 	test_atoi("123");
// 	test_atoi("999");
// 	test_atoi("123456");
// 	test_atoi("2147483647");
// 	test_atoi("-1");
// 	test_atoi("-42");
// 	test_atoi("-123");
// 	test_atoi("-999");
// 	test_atoi("-2147483648");

// 	/* Positive / negative signs */
// 	printf("\n---- SIGNS ----\n");
// 	test_atoi("+1");
// 	test_atoi("+42");
// 	test_atoi("+123");
// 	test_atoi("-1");
// 	test_atoi("-42");
// 	test_atoi("-123");
// 	test_atoi("++42");
// 	test_atoi("--42");
// 	test_atoi("+-42");
// 	test_atoi("-+42");

// 	/* Whitespace */
// 	printf("\n---- WHITESPACE ----\n");
// 	test_atoi("42");
// 	test_atoi(" 42");
// 	test_atoi("   42");
// 	test_atoi("\t42");
// 	test_atoi("\n42");
// 	test_atoi("\v42");
// 	test_atoi("\f42");
// 	test_atoi("\r42");
// 	test_atoi(" \t\n\v\f\r42");
// 	test_atoi("  -42");
// 	test_atoi("\t-42");
// 	test_atoi("\n+42");

// 	/* Whitespace after number */
// 	printf("\n---- TRAILING CHARACTERS ----\n");
// 	test_atoi("42abc");
// 	test_atoi("42 abc");
// 	test_atoi("42!");
// 	test_atoi("42-42");
// 	test_atoi("42+42");
// 	test_atoi("-42abc");
// 	test_atoi("+42abc");
// 	test_atoi("123 456");

// 	/* Invalid input */
// 	printf("\n---- INVALID INPUT ----\n");
// 	test_atoi("");
// 	test_atoi(" ");
// 	test_atoi("\t");
// 	test_atoi("abc");
// 	test_atoi("ABC");
// 	test_atoi("hello");
// 	test_atoi("!");
// 	test_atoi("@");
// 	test_atoi("a42");
// 	test_atoi("abc42");
// 	test_atoi("42abc123");
// 	test_atoi("++");
// 	test_atoi("--");
// 	test_atoi("+-");
// 	test_atoi("-+");
// 	test_atoi("+");
// 	test_atoi("-");

// 	/* Numbers surrounded by garbage */
// 	printf("\n---- GARBAGE AROUND NUMBER ----\n");
// 	test_atoi("abc42");
// 	test_atoi("abc-42");
// 	test_atoi("abc+42");
// 	test_atoi("42abc");
// 	test_atoi("-42abc");
// 	test_atoi("+42abc");
// 	test_atoi("abc 42");
// 	test_atoi(" 42abc");
// 	test_atoi("  -42abc");
// 	test_atoi("  +42abc");

// 	/* Leading zeroes */
// 	printf("\n---- LEADING ZEROES ----\n");
// 	test_atoi("00");
// 	test_atoi("000");
// 	test_atoi("00042");
// 	test_atoi("000042");
// 	test_atoi("-00042");
// 	test_atoi("+00042");
// 	test_atoi("00000000000000042");

// 	/* INT boundaries */
// 	printf("\n---- INT BOUNDARIES ----\n");
// 	test_atoi("2147483647");
// 	test_atoi("-2147483648");
// 	test_atoi("2147483646");
// 	test_atoi("-2147483647");

// 	printf("\n========================================\n");

// 	if (g_failed == 0)
// 	{
// 		printf(GREEN "ALL TESTS PASSED! %d tests completed successfully.\n"
// 			RESET, g_tests);
// 	}
// 	else
// 	{
// 		printf(RED "%d TEST(S) FAILED! %d tests completed.\n"
// 			RESET, g_failed, g_tests);
// 	}

// 	printf("========================================\n\n");

// 	return (g_failed != 0);
// }
