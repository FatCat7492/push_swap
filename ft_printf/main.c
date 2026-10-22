/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgrandj <crgrandj@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 16:06:02 by crgrandj          #+#    #+#             */
/*   Updated: 2026/10/16 21:57:45 by crgrandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* je sais ya pas besoin de tout ca mais flem ctrl+c ctrl+v */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdint.h>

// cc -Wall -Wextra -Werror main.c libftprintf.a && ./a.out

int	main ()
{
	int				i;
	int				n;
	char			*s;
	unsigned int	uin;

printf("\n//========================================================\n");
	printf("\n  TEST N.1   : TAILLE\n");
	i = printf("Hello");
		printf(" ==    printf taille :[%d]  \n", i);
	i = ft_printf("Hello");
		ft_printf(" == ft_printf taille :[%d]\n", i);

	// printf("\nTEST N.1.1   : TAILLE\n"); /* fonctionne seulement avec bonus (normalement) */
	// i =    printf("%% % %% % %% %% ");
	// 	printf("printf taille :[%d]\n", i);
	// i = ft_printf("%% % %% % %% %% ");
	// 	ft_printf("ft_printf taille :[%d]\n", i);
	
printf("\n//========================================================\n");
//========================================================

	printf("\n  TEST N.2   : CHAR C ET TAILLE\n");
	char c = 'a';
		printf("   printf %%c : [");
	i = printf("%c", c);
		printf("] ==    printf taille :[%d]\n", i);
		ft_printf("ft_printf %%c : [");
	i = ft_printf("%c", c);
		ft_printf("] == ft_printf taille :[%d]\n", i);

	printf("\n  TEST N.2.1 : CHAR C ESPACE ET TAILLE\n");
	c = ' ';
		printf("   printf %%c : [");
	i = printf("%c", c);
		printf("] ==    printf taille :[%d]\n", i);
		ft_printf("ft_printf %%c : [");
	i = ft_printf("%c", c);
		ft_printf("] == ft_printf taille :[%d]\n", i);

	printf("\n  TEST N.2.2 : CHAR C \\0 ET TAILLE\n");
	c = '\0';
		printf("   printf %%c : [");
	i = printf("%c", c);
		printf("] ==    printf taille :[%d]\n", i);
		ft_printf("ft_printf %%c : [");
	i = ft_printf("%c", c);
		ft_printf("] == ft_printf taille :[%d]\n", i);
printf("\n//========================================================\n");	
//========================================================

	printf("\n  TEST N.3   : STRING S ET TAILLE\n");
	s = "test sur le ft_printf %s";
		printf("   printf %%s : [");
	i = printf("%s", s);
		printf("] ==    printf taille :[%d]\n", i);
		ft_printf("ft_printf %%s : [");
	i = ft_printf("%s", s);
		ft_printf("] == ft_printf taille :[%d]\n", i);

	printf("\n  TEST N.3.1 : EMPTY STRING S ET TAILLE\n");
	s = "";
		printf("   printf %%s : [");
	i = printf("%s", s);
		printf("] ==    printf taille :[%d]\n", i);
			ft_printf("ft_printf %%s : [");
		i = ft_printf("%s", s);
		ft_printf("] == ft_printf taille :[%d]\n", i);

	printf("\n  TEST N.3.2 : STRING NULL ET TAILLE\n");
	s = NULL;
		printf("   printf %%s : [");
	i = printf("%s", s);
		printf("] ==    printf taille :[%d]\n", i);
		ft_printf("ft_printf %%s : [");
	i = ft_printf("%s", s);
		ft_printf("] == ft_printf taille :[%d]\n", i);

	printf("\n  TEST N.3.3 : STRING SPACE ET TAILLE\n");
	s = " ";
		printf("   printf %%s : [");
	i = printf("%s", s);
		printf("] ==    printf taille :[%d]\n", i);
		ft_printf("ft_printf %%s : [");
	i = ft_printf("%s", s);
		ft_printf("] == ft_printf taille :[%d]\n", i);

	printf("\n  TEST N.3.4 : STRING hello\\0world ET TAILLE\n");
	s = "hello\0world";
		printf("   printf %%s : [");
	i = printf("%s", s);
		printf("] ==    printf taille :[%d]\n", i);
		ft_printf("ft_printf %%s : [");
	i = ft_printf("%s", s);
		ft_printf("] == ft_printf taille :[%d]\n", i);

	printf("\n  TEST N.3.5 : STRING hello\\nworld ET TAILLE\n");
	s = "hello\nworld";
		printf("   printf %%s : [");
	i = printf("%s", s);
		printf("] ==    printf taille :[%d]\n", i);
		ft_printf("ft_printf %%s : [");
	i = ft_printf("%s", s);
		ft_printf("] == ft_printf taille :[%d]\n", i);
printf("\n//========================================================\n");
//========================================================

	printf("\n  TEST N.4   : POINTER P ET TAILLE\n");
	n = 42;
	int *ptr = &n;
		printf("   printf %%p : [");
	i = printf("%p", ptr);
		printf("] ==    printf taille :[%d]\n", i);
		ft_printf("ft_printf %%p : [");
	i = ft_printf("%p", ptr);
		ft_printf("] == ft_printf taille :[%d]\n", i);

	printf("\n  TEST N.4.1 : P == NULL ET TAILLE\n! affiche [0x0] sur mac os et [(nil)] sur linux (normal) !\n");
	ptr = NULL;
		printf("   printf %%p : [");
	i = printf("%p", ptr);							/* affiche 0x0 sur mac os et (nil) sur linux (normal) */
		printf("] ==    printf taille :[%d]\n", i);
		ft_printf("ft_printf %%p : [");
	i = ft_printf("%p", ptr);
		ft_printf("] == ft_printf taille :[%d]\n", i);

	printf("\n  TEST N.4.2 : P == INT_MIN ET TAILLE\n");
	n = INT_MIN;
	ptr = &n;
		printf("   printf %%p : [");
	i = printf("%p", ptr);
		printf("] ==    printf taille :[%d]\n", i);
		ft_printf("ft_printf %%p : [");
	i = ft_printf("%p", ptr);
		ft_printf("] == ft_printf taille :[%d]\n", i);

	printf("\n  TEST N.4.3 : P == INT_MAX ET TAILLE\n");
	n = INT_MAX;
	ptr = &n;
		printf("   printf %%p : [");
	i = printf("%p", ptr);
		printf("] ==    printf taille :[%d]\n", i);
		ft_printf("ft_printf %%p : [");
	i = ft_printf("%p", ptr);
		ft_printf("] == ft_printf taille :[%d]\n", i);

	printf("\n  TEST N.4.4 : P == (void *)&n == 42 ET TAILLE\n");
	n = 42;
		printf("   printf %%p : [");
	i = printf("%p", (void *)&n);
		printf("] ==    printf taille :[%d]\n", i);
		ft_printf("ft_printf %%p : [");
	i = ft_printf("%p", (void *)&n);
		ft_printf("] == ft_printf taille :[%d]\n", i);

	printf("\n  TEST N.4.5 : P == (void *)NULL ET TAILLE\n! affiche [0x0] sur mac os et [(nil)] sur linux (normal) !\n");
		printf("   printf %%p : [");
	i = printf("%p", (void *)NULL);					/* affiche 0x0 sur mac os et (nil) sur linux (normal) */ 
		printf("] ==    printf taille :[%d]\n", i);
		ft_printf("ft_printf %%p : [");
	i = ft_printf("%p", (void *)NULL);
		ft_printf("] == ft_printf taille :[%d]\n", i);

	printf("\n  TEST N.4.6 : P == (void *)\"Hello\" ET TAILLE\n");
	n = 42;
		printf("   printf %%p : [");
	i = printf("%p", (void *)"Hello");
		printf("] ==    printf taille :[%d]\n", i);
		ft_printf("ft_printf %%p : [");
	i = ft_printf("%p", (void *)"Hello");
		ft_printf("] == ft_printf taille :[%d]\n", i);
printf("\n//========================================================\n");
//========================================================

	printf("\n  TEST N.5   : DECIMAL 0 ET TAILLE\n");
	n = 0;
		printf("   printf %%d : [");
	i = printf("%d", n);
		printf("] ==    printf taille :[%d]\n", i);
		ft_printf("ft_printf %%d : [");
	i = ft_printf("%d", n);
		ft_printf("] == ft_printf taille :[%d]\n", i);

	printf("\n  TEST N.5.1 : DECIMAL 42 ET TAILLE\n");
	n = 42;
		printf("   printf %%d : [");
	i = printf("%d", n);
		printf("] ==    printf taille :[%d]\n", i);
		ft_printf("ft_printf %%d : [");
	i = ft_printf("%d", n);
		ft_printf("] == ft_printf taille :[%d]\n", i);

	printf("\n  TEST N.5.2 : NEGATIVE DECIMAL -42 ET TAILLE\n");
	n = -42;
		printf("   printf %%d : [");
	i = printf("%d", n);
		printf("] ==    printf taille :[%d]\n", i);
		ft_printf("ft_printf %%d : [");
	i = ft_printf("%d", n);
		ft_printf("] == ft_printf taille :[%d]\n", i);

	printf("\n  TEST N.5.3 : INT MIN ET TAILLE\n");
	n = INT_MIN;
		printf("   printf %%d : [");
	i = printf("%d", n);
		printf("] ==    printf taille :[%d]\n", i);
		ft_printf("ft_printf %%d : [");
	i = ft_printf("%d", n);
		ft_printf("] == ft_printf taille :[%d]\n", i);

	printf("\n  TEST N.5.4 : INT MAX ET TAILLE\n");
	n = INT_MAX;
		printf("   printf %%d : [");
	i = printf("%d", n);
		printf("] ==    printf taille :[%d]\n", i);
		ft_printf("ft_printf %%d : [");
	i = ft_printf("%d", n);
		ft_printf("] == ft_printf taille :[%d]\n", i);
printf("\n//========================================================\n");
//========================================================

	printf("\n  TEST N.6   : INTEGER 0 ET TAILLE\n");
	n = 0;
			printf("   printf %%i : [");
		i = printf("%i", n);
			printf("] ==    printf taille :[%d]\n", i);
			ft_printf("ft_printf %%i : [");
		i = ft_printf("%i", n);
			ft_printf("] == ft_printf taille :[%d]\n", i);

	printf("\n  TEST N.6.1 : INTEGER 42 ET TAILLE\n");
	n = 42;
		printf("   printf %%i : [");
	i = printf("%i", n);
		printf("] ==    printf taille :[%d]\n", i);
		ft_printf("ft_printf %%i : [");
	i = ft_printf("%i", n);
		ft_printf("] == ft_printf taille :[%d]\n", i);

	printf("\n  TEST N.6.2 : NEGATIVE INTEGER -42 ET TAILLE\n");
	n = -42;
		printf("   printf %%i : [");
	i = printf("%i", n);
		printf("] ==    printf taille :[%d]\n", i);
		ft_printf("ft_printf %%i : [");
	i = ft_printf("%i", n);
		ft_printf("] == ft_printf taille :[%d]\n", i);

	printf("\n  TEST N.6.3 : INT MIN ET TAILLE\n");
	n = INT_MIN;
		printf("   printf %%i : [");
	i = printf("%i", n);
		printf("] ==    printf taille :[%d]\n", i);
		ft_printf("ft_printf %%i : [");
	i = ft_printf("%i", n);
		ft_printf("] == ft_printf taille :[%d]\n", i);

	printf("\n  TEST N.6.4 : INT MAX ET TAILLE\n");
	n = INT_MAX;
		printf("   printf %%i : [");
	i = printf("%i", n);
		printf("] ==    printf taille :[%d]\n", i);
		ft_printf("ft_printf %%i : [");
	i = ft_printf("%i", n);
		ft_printf("] == ft_printf taille :[%d]\n", i);
printf("\n//========================================================\n");
//========================================================

	printf("\n  TEST N.7   : UNSIGNED INT 0 ET TAILLE\n");
	uin = 0;
			printf("   printf %%u : [");
		i = printf("%u", uin);
			printf("] ==    printf taille :[%d]\n", i);
			ft_printf("ft_printf %%u : [");
		i = ft_printf("%u", uin);
			ft_printf("] == ft_printf taille :[%d]\n", i);

	printf("\n  TEST N.7.1 : UNSIGNED INT 42 ET TAILLE\n");
	uin = 42;
		printf("   printf %%u : [");
	i = printf("%u", uin);
		printf("] ==    printf taille :[%d]\n", i);
		ft_printf("ft_printf %%u : [");
	i = ft_printf("%u", uin);
		ft_printf("] == ft_printf taille :[%d]\n", i);

	printf("\n  TEST N.7.2 : UNSIGNED INT_MAX ET TAILLE\n");
	uin = UINT_MAX;
		printf("   printf %%u : [");
	i = printf("%u", uin);
		printf("] ==    printf taille :[%d]\n", i);
		ft_printf("ft_printf %%u : [");
	i = ft_printf("%u", uin);
		ft_printf("] == ft_printf taille :[%d]\n", i);

	printf("\n  TEST N.7.3 : UNSIGNED INT -1 ET TAILLE\n");
	uin = -1;
		printf("   printf %%u : [");
	i = printf("%u", uin);
		printf("] ==    printf taille :[%d]\n", i);
		ft_printf("ft_printf %%u : [");
	i = ft_printf("%u", uin);
		ft_printf("] == ft_printf taille :[%d]\n", i);
printf("\n//========================================================\n");
//========================================================

	printf("\n  TEST N.8   : HEXA 'x' ET TAILLE\n");
	uin = 42;
		printf("   printf %%x : [");
	i = printf("%x", uin);
		printf("] ==    printf taille :[%d]\n", i);
		ft_printf("ft_printf %%x : [");
	i = ft_printf("%x", uin);
		ft_printf("] == ft_printf taille :[%d]\n", i);

	printf("\n  TEST N.8.1 : HEXA 'x' == INT_MIN ET TAILLE\n");
	uin = INT_MIN;
		printf("   printf %%x : [");
		i = printf("%x", uin);
		printf("] ==    printf taille :[%d]\n", i);
		ft_printf("ft_printf %%x : [");
	i = ft_printf("%x", uin);
		ft_printf("] == ft_printf taille :[%d]\n", i);

	printf("\n  TEST N.8.2 : HEXA 'x' == UINT_MAX ET TAILLE\n");
	uin = UINT_MAX;
		printf("   printf %%x : [");
	i = printf("%x", uin);
		printf("] ==    printf taille :[%d]\n", i);
		ft_printf("ft_printf %%x : [");
	i = ft_printf("%x", uin);
		ft_printf("] == ft_printf taille :[%d]\n", i);

	printf("\n  TEST N.8.3 : HEXA 'x' == 0 ET TAILLE\n");
		uin = 0;
			printf("   printf %%x : [");
		i = printf("%x", uin);
			printf("] ==    printf taille :[%d]\n", i);
			ft_printf("ft_printf %%x : [");
		i = ft_printf("%x", uin);
			ft_printf("] == ft_printf taille :[%d]\n", i);
printf("\n//========================================================\n");
//========================================================

	printf("\n  TEST N.9   : HEXA 'X' ET TAILLE\n");
	uin = 42;
		printf("   printf %%X : [");
	i = printf("%X", uin);
		printf("] ==    printf taille :[%d]\n", i);
		ft_printf("ft_printf %%X : [");
	i = ft_printf("%X", uin);
		ft_printf("] == ft_printf taille :[%d]\n", i);

	printf("\n  TEST N.9.1 : HEXA 'X' == INT_MIN ET TAILLE\n");
	uin = INT_MIN;
		printf("   printf %%X : [");
		i = printf("%X", uin);
		printf("] ==    printf taille :[%d]\n", i);
		ft_printf("ft_printf %%X : [");
	i = ft_printf("%X", uin);
		ft_printf("] == ft_printf taille :[%d]\n", i);

	printf("\n  TEST N.9.2 : HEXA 'X' == UINT_MAX ET TAILLE\n");
	uin = UINT_MAX;
		printf("   printf %%X : [");
	i = printf("%X", uin);
		printf("] ==    printf taille :[%d]\n", i);
		ft_printf("ft_printf %%X : [");
	i = ft_printf("%X", uin);
		ft_printf("] == ft_printf taille :[%d]\n", i);

	printf("\n  TEST N.9.3 : HEXA 'X' == 0 ET TAILLE\n");
	uin = 0;
		printf("   printf %%X : [");
	i = printf("%X", uin);
		printf("] ==    printf taille :[%d]\n", i);
		ft_printf("ft_printf %%X : [");
	i = ft_printf("%X", uin);
		ft_printf("] == ft_printf taille :[%d]\n", i);
printf("\n//========================================================\n");
//========================================================

	printf("\n  TEST N.10  : %%%% TAILLE\n");
		i = printf("%%");
			printf(" ==    printf taille :[%d]  \n", i);
		i = ft_printf("%%");
			ft_printf(" == ft_printf taille :[%d]\n", i);

	printf("\n  TEST N.10.1: MULTIPLE %%d %%i %%d ET TAILLE\n");
		printf("   printf %%d %%i %%d : [");
	i = printf("%d %i %d", 42, -42, 0);
		printf("] ==    printf taille :[%d]\n", i);
		ft_printf("ft_printf %%d %%i %%d : [");
	i = ft_printf("%d %i %d", 42, -42, 0);
		ft_printf("] == ft_printf taille :[%d]\n", i);

	printf("\n  TEST N.10.2: MULTIPLE %%x %%X ET TAILLE\n");
		printf("   printf %%x %%X : [");
	i = printf("%x %X", 255, 255);
		printf("] ==    printf taille :[%d]\n", i);
		ft_printf("ft_printf %%x %%X : [");
	i = ft_printf("%x %X", 255, 255);
		ft_printf("] == ft_printf taille :[%d]\n", i);

	printf("\n  TEST N.10.3: MULTIPLE ???? ET TAILLE\n");
		printf("   printf ???? : [");
	i = printf("%c %s %p %d %i %u %x %X %%",
    'A', "hello", (void *)&n, -42, 42, 42u, 42, 42);
		printf("] ==    printf taille :[%d]\n", i);
		ft_printf("ft_printf ???? : [");
	i = ft_printf("%c %s %p %d %i %u %x %X %%",
    'A', "hello", (void *)&n, -42, 42, 42u, 42, 42);
		ft_printf("] == ft_printf taille :[%d]\n", i);	

	printf("\n  TEST N.10.4: EMPTY\n");
		printf("   printf : [");
	i = printf("");
		printf("] ==    printf taille :[%d]\n", i);
		ft_printf("ft_printf : [");
	i = ft_printf("");
		ft_printf("] == ft_printf taille :[%d]\n\n", i);	

	// 	printf("\n  TEST N.10.4: %v\n"); /* a teste sans flag */ 
	// 	printf("   printf : [");
	// i = printf("%v");
	// 	printf("] ==    printf taille :[%d]\n", i);
	// 	ft_printf("ft_printf : [");
	// i = ft_printf("%v");
	// 	ft_printf("] == ft_printf taille :[%d]", i);
}
// cc -Wall -Wextra -Werror main.c libftprintf.a && ./a.out