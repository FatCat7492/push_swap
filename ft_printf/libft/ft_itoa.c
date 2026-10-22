/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgrandj <crgrandj@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 10:47:31 by crgrandj          #+#    #+#             */
/*   Updated: 2026/10/14 12:23:57 by crgrandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_while(char *s, long t, int i, int sign);
static int	ft_check(int i, long t);

char	*ft_itoa(int n)
{
	char	*s;
	int		i;
	long	t;
	int		sign;

	t = n;
	sign = 1;
	i = 0;
	if (t < 0)
	{
		t = -t;
		sign -= 1;
		i++;
	}
	i = ft_check(i, t);
	s = malloc(sizeof(char) * (i + 2));
	if (s == NULL)
		return (NULL);
	ft_while(s, t, i, sign);
	s[i + 1] = '\0';
	return (s);
}

static int	ft_check(int i, long t)
{
	while (t >= 10)
	{
		t = t / 10;
		i++;
	}
	return (i);
}

static void	ft_while(char *s, long t, int i, int sign)
{
	if (sign == 0)
	{
		s[0] = '-';
		while (i >= 1)
		{
			s[i] = (t % 10) + '0';
			t = t / 10;
			i--;
		}
	}
	else
	{
		while (i >= 0)
		{
			s[i] = (t % 10) + '0';
			t = t / 10;
			i--;
		}
	}
}

//=========================================================

// #define GREEN "\033[32m"
// #define RED "\033[31m"
// #define RESET "\033[0m"

// static int	test_itoa(int n, const char *expected)
// {
// 	char	*result;
// 	int		ok;

// 	result = ft_itoa(n);
// 	ok = (result != NULL && strcmp(result, expected) == 0);

// 	if (ok)
// 		printf(GREEN "✓ PASS" RESET " | ft_itoa(%d) -> \"%s\"\n",
// 			n, result);
// 	else
// 		printf(RED "✗ FAIL" RESET " | ft_itoa(%d) | ex: \"%s\", got: \"%s\"\n",
// 			n, expected, result ? result : "NULL");
// 	free(result);
// 	return (ok);
// }

// int	main(void)
// {
// 	int	passed;
// 	int	total;

// 	passed = 0;
// 	total = 0;

// 	printf("\n========== FT_ITOA TESTER ==========\n\n");

// 	total++;
// 	passed += test_itoa(0, "0");

// 	total++;
// 	passed += test_itoa(1, "1");

// 	total++;
// 	passed += test_itoa(-1, "-1");

// 	total++;
// 	passed += test_itoa(42, "42");

// 	total++;
// 	passed += test_itoa(-42, "-42");

// 	total++;
// 	passed += test_itoa(123456, "123456");

// 	total++;
// 	passed += test_itoa(-123456, "-123456");

// 	total++;
// 	passed += test_itoa(2147483647, "2147483647");

// 	total++;
// 	passed += test_itoa(-2147483648, "-2147483648");

// 	printf("\n====================================\n");
// 	if (passed == total)
// 		printf(GREEN "ALL TESTS PASSED: %d/%d" RESET "\n",
// 			passed, total);
// 	else
// 		printf(RED "TESTS PASSED: %d/%d" RESET "\n",
// 			passed, total);
// 	printf("====================================\n\n");

// 	return (0);
// }
