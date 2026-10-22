/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgrandj <crgrandj@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 20:53:57 by crgrandj          #+#    #+#             */
/*   Updated: 2026/09/19 12:41:27 by crgrandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	temp;
	int	bol;

	i = 0;
	bol = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			temp = i;
			bol = 1;
		}
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	if (bol == 1)
		return ((char *)&s[temp]);
	return (NULL);
}

// #define GREEN "\033[32m"
// #define RED "\033[31m"
// #define RESET "\033[0m"

// static void	test_strrchr(const char *s, int c)
// {
// 	char	*expected;
// 	char	*result;
// 	int		expected_pos;
// 	int		result_pos;

// 	expected = strrchr(s, c);
// 	result = ft_strrchr(s, c);

// 	expected_pos = expected ? (int)(expected - s) : -1;
// 	result_pos = result ? (int)(result - s) : -1;

// 	if (expected_pos == result_pos)
// 	{
// 		printf(GREEN "✓ PASS" RESET " | strrchr(\"%s\", '%c')\n",
// 			s, c == '\0' ? '\\' : c);
// 	}
// 	else
// 	{
// 		printf(RED "✗ FAIL" RESET " | strrchr(\"%s\", '%c')\n",
// 			s, c == '\0' ? '\\' : c);
// 		printf("    expected position: %d\n", expected_pos);
// 		printf("         got position: %d\n", result_pos);
// 	}
// }

// int	main(void)
// {
// 	printf("\n=== ft_strrchr tests ===\n\n");

// 	test_strrchr("Hello World", 'H');
// 	test_strrchr("Hello World", 'o');
// 	test_strrchr("Hello World", 'W');
// 	test_strrchr("Hello World", 'd');
// 	test_strrchr("Hello World", 'x');

// 	test_strrchr("aaaaa", 'a');
// 	test_strrchr("abcabcabc", 'a');
// 	test_strrchr("abcabcabc", 'b');
// 	test_strrchr("abcabcabc", 'c');

// 	test_strrchr("", 'x');
// 	test_strrchr("", '\0');
// 	test_strrchr("Hello", '\0');

// 	test_strrchr("42 School", '4');
// 	test_strrchr("42 School", '2');
// 	test_strrchr("42 School", ' ');

// 	printf("\n");
// 	return (0);
// }
