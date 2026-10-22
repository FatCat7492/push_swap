/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgrandj <crgrandj@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 17:22:12 by crgrandj          #+#    #+#             */
/*   Updated: 2026/09/19 12:28:35 by crgrandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*a1;
	const unsigned char	*a2;

	a1 = (const unsigned char *)s1;
	a2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (a1[i] != a2[i])
			return (a1[i] - a2[i]);
		i++;
	}
	return (0);
}

// #define GREEN "\033[32m"
// #define RED   "\033[31m"
// #define RESET "\033[0m"

// static int	test_memcmp(const void *s1, const void *s2, size_t n,
// 		const char *name)
// {
// 	int expected;
// 	int result;

// 	expected = memcmp(s1, s2, n);
// 	result = ft_memcmp(s1, s2, n);

// 	/*
// 	 * memcmp ne garantit pas une valeur précise autre que :
// 	 * < 0, == 0 ou > 0.
// 	 * On compare donc le signe du résultat.
// 	 */
// 	if ((expected == 0 && result == 0)
// 		|| (expected < 0 && result < 0)
// 		|| (expected > 0 && result > 0))
// 	{
// 		printf(GREEN "✓ PASS" RESET "  %s\n", name);
// 		return (1);
// 	}

// 	printf(RED "✗ FAIL" RESET "  %s\n", name);
// 	printf("    memcmp   = %d\n", expected);
// 	printf("    ft_memcmp = %d\n", result);
// 	return (0);
// }

// int	main(void)
// {
// 	int passed;
// 	int total;

// 	passed = 0;
// 	total = 0;

// 	printf("\n===== FT_MEMCMP TESTS =====\n\n");

// 	/* Strings identiques */
// 	total++;
// 	passed += test_memcmp("hello", "hello", 5,
// 		"Strings identiques");

// 	/* Strings différentes */
// 	total++;
// 	passed += test_memcmp("hello", "hallo", 5,
// 		"Différence au milieu");

// 	/* Première différence */
// 	total++;
// 	passed += test_memcmp("abc", "xbc", 3,
// 		"Différence au premier caractère");

// 	/* Dernière différence */
// 	total++;
// 	passed += test_memcmp("abc", "abd", 3,
// 		"Différence au dernier caractère");

// 	/* n = 0 */
// 	total++;
// 	passed += test_memcmp("hello", "world", 0,
// 		"n = 0");

// 	/* Comparaison partielle */
// 	total++;
// 	passed += test_memcmp("hello", "heyyy", 2,
// 		"Comparaison partielle identique");

// 	/* Différence après n */
// 	total++;
// 	passed += test_memcmp("hello", "heyyy", 2,
// 		"Différence située après n");

// 	/* Chaînes vides */
// 	total++;
// 	passed += test_memcmp("", "", 0,
// 		"Chaînes vides");

// 	/* Buffer binaire */
// 	{
// 		unsigned char a[] = {0x00, 0x01, 0x02, 0xFF};
// 		unsigned char b[] = {0x00, 0x01, 0x02, 0xFF};

// 		total++;
// 		passed += test_memcmp(a, b, sizeof(a),
// 			"Buffers binaires identiques");
// 	}

// 	/* Buffer binaire différent */
// 	{
// 		unsigned char a[] = {0x00, 0x01, 0x02, 0xFF};
// 		unsigned char b[] = {0x00, 0x01, 0x03, 0xFF};

// 		total++;
// 		passed += test_memcmp(a, b, sizeof(a),
// 			"Buffers binaires différents");
// 	}

// 	/* Test avec des caractères signés/non signés */
// 	{
// 		unsigned char a[] = {0xFF};
// 		unsigned char b[] = {0x01};

// 		total++;
// 		passed += test_memcmp(a, b, 1,
// 			"Comparaison 0xFF vs 0x01");
// 	}

// 	printf("\n===========================\n");
// 	printf("Résultat : %d/%d tests réussis\n", passed, total);

// 	if (passed == total)
// 		printf(GREEN "Tous les tests passent ! ✓\n" RESET);
// 	else
// 		printf(RED "Certains tests échouent ! ✗\n" RESET);

// 	return (0);
// }
