/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgrandj <crgrandj@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 15:36:57 by crgrandj          #+#    #+#             */
/*   Updated: 2026/10/12 23:39:15 by crgrandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_arrcount(char const *s, char c);
static int	ft_strcount(char const *s, char c);
static char	**ft_free(char **array, size_t i);
static char	**ft_split2(char const *s, char c, char **array, size_t indexarr);

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	indexarr;

	if (!s)
		return ((void *)0);
	indexarr = ft_arrcount(s, c);
	array = malloc(sizeof(char *) * (indexarr + 1));
	if (array == NULL)
		return (NULL);
	return (ft_split2(s, c, array, indexarr));
}
// *s++ lit la valeur et incr || s++ ne lit pas la valeur et incr

static char	**ft_split2(char const *s, char c, char **array, size_t indexarr)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < indexarr)
	{
		while (*s && *s == c)
			s++;
		array[i] = malloc(sizeof(char) * (ft_strcount(s, c) + 1));
		if (array[i] == NULL)
			return (ft_free(array, i));
		j = 0;
		while (*s && *s != c)
			array[i][j++] = *s++;
		array[i][j] = '\0';
		i++;
	}
	array[i] = 0;
	return (array);
}

static char	**ft_free(char **array, size_t i)
{
	while (i > 0)
	{
		i--;
		free(array[i]);
	}
	free(array);
	return (NULL);
}

static int	ft_arrcount(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			count++;
		s++;
	}
	return (count);
}

static int	ft_strcount(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (s[count] && s[count] != c)
		count++;
	return (count);
}

//========================================================

// #include <stdio.h>
// #include <stdlib.h>

// char	**ft_split(char const *s, char c);

// #define GREEN "\033[32m"
// #define RED "\033[31m"
// #define RESET "\033[0m"

// static int	count_words(char **split)
// {
// 	int	i;

// 	i = 0;
// 	while (split && split[i])
// 		i++;
// 	return (i);
// }

// static void	free_split(char **split)
// {
// 	int	i;

// 	if (!split)
// 		return ;
// 	i = 0;
// 	while (split[i])
// 	{
// 		free(split[i]);
// 		i++;
// 	}
// 	free(split);
// }

// static int	test_split(char *str, char c, int expected)
// {
// 	char	**result;
// 	int		count;

// 	result = ft_split(str, c);
// 	count = count_words(result);

// 	if (count == expected)
// 	{
// 		printf(GREEN "✓ PASS" RESET " | \"%s\" | delimiter: '%c' | count: %d\n",
// 			str, c, count);
// 		free_split(result);
// 		return (1);
// 	}

// 	printf(RED "✗ FAIL" RESET " | \"%s\" | deli: '%c' | expec: %d, got: %d\n",
// 		str, c, expected, count);
// 	free_split(result);
// 	return (0);
// }

// int	main(void)
// {
// 	int	passed;
// 	int	total;

// 	passed = 0;
// 	total = 0;

// 	printf("\n========== FT_SPLIT TESTER ==========\n\n");

// 	total++;
// 	passed += test_split("hello world", ' ', 2);

// 	total++;
// 	passed += test_split("hello world this is split", ' ', 5);

// 	total++;
// 	passed += test_split("hello", ' ', 1);

// 	total++;
// 	passed += test_split("", ' ', 0);

// 	total++;
// 	passed += test_split("   hello   world   ", ' ', 2);

// 	total++;
// 	passed += test_split("hello,,world,,test", ',', 3);

// 	total++;
// 	passed += test_split(",,,,hello,,,,", ',', 1);

// 	total++;
// 	passed += test_split("one:two:three:four", ':', 4);

// 	total++;
// 	passed += test_split("no-delimiter", ' ', 1);

// 	total++;
// 	passed += test_split("a b c d e f g", ' ', 7);

// 	printf("\n=====================================\n");
// 	if (passed == total)
// 		printf(GREEN "ALL TESTS PASSED: %d/%d" RESET "\n", passed, total);
// 	else
// 		printf(RED "TESTS PASSED: %d/%d" RESET "\n", passed, total);
// 	printf("=====================================\n\n");

// 	return (0);
// }

//====================================================================

// int main (void)
// {
// 	char **array;
// 	char const *s = "hello this split is awefull";
// 	char c = ' ';
// 	int i = 0;
// 	int j;

// 	array = ft_split (s, c);
// 	while (array[i])
// 	{
// 		j = 0;
// 		while (array[i][j])
// 		{
// 			write (1, &array[i][j], 1);
// 			j++;
// 		}
// 		write(1, "\n", 1);
// 		i++;
// 	}
// 	ft_free(array, i);
// 	return (0);
// }