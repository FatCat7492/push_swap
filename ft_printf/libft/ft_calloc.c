/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgrandj <crgrandj@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 22:25:44 by crgrandj          #+#    #+#             */
/*   Updated: 2026/09/19 12:42:42 by crgrandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;

	if (count != 0 && size > SIZE_MAX / count)
		return (NULL);
	ptr = malloc(size * count);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, size * count);
	return (ptr);
}

// #include <stdint.h>

// #define GREEN "\033[0;32m"
// #define RED   "\033[0;31m"
// #define RESET "\033[0m"

// static void print_result(const char *test, int passed)
// {
// 	if (passed)
// 		printf(GREEN "[PASS]" RESET " %s\n", test);
// 	else
// 		printf(RED "[FAIL]" RESET " %s\n", test);
// }

// static int compare_memory(void *a, void *b, size_t size)
// {
// 	return (memcmp(a, b, size) == 0);
// }

// int	main(void)
// {
// 	void	*mine;
// 	void	*real;
// 	size_t	max;

// 	printf("========== ft_calloc tests ==========\n\n");

// 	/*
// 	 * Test 1: basic allocation
// 	 */
// 	mine = ft_calloc(10, sizeof(int));
// 	real = calloc(10, sizeof(int));

// 	print_result("10 ints are allocated and zeroed",
// 		mine != NULL && real != NULL &&
// 		compare_memory(mine, real, 10 * sizeof(int)));

// 	free(mine);
// 	free(real);

// 	/*
// 	 * Test 2: char allocation
// 	 */
// 	mine = ft_calloc(100, sizeof(char));
// 	real = calloc(100, sizeof(char));

// 	print_result("100 chars are zeroed",
// 		mine != NULL && real != NULL &&
// 		compare_memory(mine, real, 100));

// 	free(mine);
// 	free(real);

// 	/*
// 	 * Test 3: larger elements
// 	 */
// 	mine = ft_calloc(50, sizeof(double));
// 	real = calloc(50, sizeof(double));

// 	print_result("50 doubles are zeroed",
// 		mine != NULL && real != NULL &&
// 		compare_memory(mine, real, 50 * sizeof(double)));

// 	free(mine);
// 	free(real);

// 	/*
// 	 * Test 4: count == 0
// 	 */
// 	mine = ft_calloc(0, 10);
// 	real = calloc(0, 10);

// 	print_result("count == 0 behaves like calloc",
// 		(mine == NULL && real == NULL) ||
// 		(mine != NULL && real != NULL));

// 	free(mine);
// 	free(real);

// 	/*
// 	 * Test 5: size == 0
// 	 */
// 	mine = ft_calloc(10, 0);
// 	real = calloc(10, 0);

// 	print_result("size == 0 behaves like calloc",
// 		(mine == NULL && real == NULL) ||
// 		(mine != NULL && real != NULL));

// 	free(mine);
// 	free(real);

// 	/*
// 	 * Test 6: both zero
// 	 */
// 	mine = ft_calloc(0, 0);
// 	real = calloc(0, 0);

// 	print_result("count == 0 and size == 0",
// 		(mine == NULL && real == NULL) ||
// 		(mine != NULL && real != NULL));

// 	free(mine);
// 	free(real);

// 	/*
// 	 * Test 7: verify every byte is zero
// 	 */
// 	mine = ft_calloc(1024, 1);

// 	int	all_zero = 1;
// 	if (mine != NULL)
// 	{
// 		unsigned char *p = mine;

// 		for (size_t i = 0; i < 1024; i++)
// 		{
// 			if (p[i] != 0)
// 			{
// 				all_zero = 0;
// 				break;
// 			}
// 		}
// 	}

// 	print_result("every allocated byte is zero", mine != NULL && all_zero);

// 	free(mine);

// 	/*
// 	 * Test 8: larger allocation
// 	 */
// 	mine = ft_calloc(10000, sizeof(int));
// 	real = calloc(10000, sizeof(int));

// 	print_result("large allocation is zeroed",
// 		mine != NULL && real != NULL &&
// 		compare_memory(mine, real, 10000 * sizeof(int)));

// 	free(mine);
// 	free(real);

// 	/*
// 	 * Test 9: overflow
// 	 *
// 	 * SIZE_MAX is the largest value size_t can hold.
// 	 * SIZE_MAX / 2 + 1 multiplied by 2 must overflow.
// 	 */
// 	max = SIZE_MAX;

// 	mine = ft_calloc(max / 2 + 1, 2);

// 	print_result("multiplication overflow returns NULL", mine == NULL);

// 	free(mine);

// 	/*
// 	 * Test 10: another overflow
// 	 */
// 	mine = ft_calloc(max, 2);

// 	print_result("SIZE_MAX * 2 returns NULL", mine == NULL);

// 	free(mine);

// 	printf("\n========== Tests finished ==========\n");

// 	return (0);
// }
