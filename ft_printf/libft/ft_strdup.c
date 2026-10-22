/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgrandj <crgrandj@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 15:36:03 by crgrandj          #+#    #+#             */
/*   Updated: 2026/09/18 16:14:33 by crgrandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dup;

	dup = malloc(sizeof(char) * (ft_strlen((char *)s1) + 1));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

// #define GREEN "\033[0;32m"
// #define RED   "\033[0;31m"
// #define RESET "\033[0m"

// static void	test_strdup(const char *test_name, const char *str)
// {
// 	char	*ft_result;
// 	char	*real_result;
// 	int		passed;

// 	ft_result = ft_strdup(str);
// 	real_result = strdup(str);

// 	if (ft_result == NULL && real_result == NULL)
// 		passed = 1;
// 	else if (ft_result != NULL && real_result != NULL
// 		&& strcmp(ft_result, real_result) == 0)
// 		passed = 1;
// 	else
// 		passed = 0;

// 	if (passed)
// 		printf(GREEN "[PASS]" RESET " %s\n", test_name);
// 	else
// 		printf(RED "[FAIL]" RESET " %s\n", test_name);

// 	if (!passed)
// 	{
// 		printf("  Original : \"%s\"\n", str);
// 		printf("  ft_strdup: %s\n",
// 			ft_result ? ft_result : "NULL");
// 		printf("  strdup   : %s\n",
// 			real_result ? real_result : "NULL");
// 	}

// 	free(ft_result);
// 	free(real_result);
// }

// int	main(void)
// {
// 	printf("========== ft_strdup tests ==========\n\n");

// 	test_strdup("normal string", "Hello World");
// 	test_strdup("empty string", "");
// 	test_strdup("one character", "A");
// 	test_strdup("numbers", "1234567890");
// 	test_strdup("spaces", "Hello    World");
// 	test_strdup("special characters", "!@#$%^&*()_+-=");
// 	test_strdup("mixed string", "Hello 123 !@#");
// 	test_strdup("long string",
// 		"This is a much longer string used to test ft_strdup.");

// 	printf("\n========== Tests finished ==========\n");

// 	return (0);
// }

// cc -Wall -Wextra -Werror ft_strdup.c ft_strlen.c && ./a.out
