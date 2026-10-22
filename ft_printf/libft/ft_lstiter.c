/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgrandj <crgrandj@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 12:48:29 by crgrandj          #+#    #+#             */
/*   Updated: 2026/10/09 16:52:41 by crgrandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*temp;

	temp = lst;
	while (temp)
	{
		f(temp->content);
		temp = temp->next;
	}
}

//===========================================================

// #define GREEN "\033[32m"
// #define RED "\033[31m"
// #define RESET "\033[0m"

// static int	g_tests = 0;
// static int	g_passed = 0;

// static void	test_result(char *name, int condition)
// {
// 	g_tests++;
// 	if (condition)
// 	{
// 		g_passed++;
// 		printf(GREEN "[OK]   %s" RESET "\n", name);
// 	}
// 	else
// 		printf(RED "[FAIL] %s" RESET "\n", name);
// }

// /* Fonction appliquée à chaque élément */
// static void	add_one(void *content)
// {
// 	int	*number;

// 	number = (int *)content;
// 	(*number)++;
// }

// static t_list	*create_list(void)
// {
// 	t_list	*list;
// 	int		*a;
// 	int		*b;
// 	int		*c;

// 	list = NULL;

// 	a = malloc(sizeof(int));
// 	b = malloc(sizeof(int));
// 	c = malloc(sizeof(int));

// 	if (!a || !b || !c)
// 		exit(EXIT_FAILURE);

// 	*a = 1;
// 	*b = 2;
// 	*c = 3;

// 	ft_lstadd_back(&list, ft_lstnew(a));
// 	ft_lstadd_back(&list, ft_lstnew(b));
// 	ft_lstadd_back(&list, ft_lstnew(c));

// 	return (list);
// }

// int	main(void)
// {
// 	t_list	*list;

// 	printf("\n===== ft_lstiter TESTS =====\n\n");

// 	/* Test 1 : appliquer +1 à tous les elements */
// 	list = create_list();

// 	ft_lstiter(list, add_one);

// 	test_result("Premier element devient 2",
// 		*(int *)list->content == 2);

// 	test_result("Deuxieme element devient 3",
// 		*(int *)list->next->content == 3);

// 	test_result("Troisieme element devient 4",
// 		*(int *)list->next->next->content == 4);

// 	ft_lstclear(&list, free);

// 	/* Test 2 : liste vide */
// 	list = NULL;

// 	ft_lstiter(list, add_one);

// 	test_result("Liste vide : aucune erreur", list == NULL);

// 	printf("\n-----------------------------\n");
// 	printf("Tests   : %d\n", g_tests);
// 	printf(GREEN "Passed  : %d" RESET "\n", g_passed);
// 	printf(RED "Failed  : %d" RESET "\n", g_tests - g_passed);
// 	printf("-----------------------------\n\n");

// 	return (0);
// }
