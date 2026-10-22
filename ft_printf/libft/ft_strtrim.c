/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgrandj <crgrandj@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 14:56:58 by crgrandj          #+#    #+#             */
/*   Updated: 2026/10/12 13:26:48 by crgrandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	setstart(char const *s1, char const *set);
static size_t	setend(char const *s1, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*s3;
	size_t		i;
	size_t		count;
	size_t		j;
	size_t		k;

	j = 0;
	if (!s1 || !set)
		return (NULL);
	i = setstart(s1, set);
	k = i + setend(s1, set);
	count = ft_strlen((char *)s1);
	if ((count * 2) == k)
		k = k / 2;
	s3 = malloc(sizeof(char) * (count - k + 1));
	if (!s3)
		return (NULL);
	while (j < (count - k))
	{
		s3[j] = s1[i];
		i++;
		j++;
	}
	s3[j] = '\0';
	return (s3);
}

static size_t	setstart(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	count;
	size_t	bol;

	i = 0;
	count = 0;
	while (s1[i])
	{
		j = -1;
		bol = 0;
		while (set[++j])
		{
			if (set[j] == s1[i])
			{
				count += 1;
				bol = 1;
				break ;
			}
		}
		if (bol == 0)
			return (count);
		i++;
	}
	return (count);
}

static size_t	setend(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	count;
	size_t	bol;

	i = ft_strlen((char *)s1);
	count = 0;
	while (i > 0)
	{
		j = -1;
		bol = 0;
		while (set[++j])
		{
			if (set[j] == s1[i - 1])
			{
				count += 1;
				bol = 1;
				break ;
			}
		}
		if (bol == 0)
			return (count);
		i--;
	}
	return (count);
}

/*==================================================================*/

// static void	test(char *name, char *s1, char *set, char *expected)
// {
// 	char	*result;

// 	result = ft_strtrim(s1, set);
// 	if (strcmp(result, expected) == 0)
// 		printf("\033[32m[OK]\033[0m %s\n", name);
// 	else
// 	{
// 		printf("\033[31m[KO]\033[0m %s\n", name);
// 		printf("    expected: \"%s\"\n", expected);
// 		printf("    got:      \"%s\"\n", result);
// 	}
// 	free(result);
// }

// int	main(void)
// {
// 	int	total;
// 	int	passed;

// 	total = 0;
// 	passed = 0;

// 	printf("\n--- ft_strtrim tests ---\n\n");

// 	test("no trim", "hello", " ", "hello");
// 	total++;
// 	passed++;

// 	test("trim x left", "xxxhello", "x", "hello");
// 	total++;
// 	passed++;

// 	test("trim x right", "helloxxx", "x", "hello");
// 	total++;
// 	passed++;

// 	test("trim x both", "xxxhelloxxx", "x", "hello");
// 	total++;
// 	passed++;

// 	test("no matching chars", "hello", "xyz", "hello");
// 	total++;
// 	passed++;

// 	test("more than one set char", "xyxhelloxyx", "xyx", "hello");
// 	total++;
// 	passed++;

// 	test("abcabc", "abcabc", "abc", "");
// 	total++;
// 	passed++;

// 	printf("\n----------------------\n");
// 	printf("Passed: %d/%d\n", passed, total);
// 	printf("----------------------\n\n");

// 	return (0);
// }
