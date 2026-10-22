/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgrandj <crgrandj@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 15:48:51 by crgrandj          #+#    #+#             */
/*   Updated: 2026/10/08 12:15:26 by crgrandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (!lst)
		return ;
	temp = *lst;
	while (*lst != NULL)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
}

//====================================================

// #define GREEN "\033[32m"
// #define RED "\033[31m"
// #define RESET "\033[0m"

// static int g_tests = 0;
// static int g_passed = 0;
// static int g_freed = 0;

// static void test_result(char *name, int condition)
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

// static void del_counter(void *content)
// {
// 	if (content)
// 	{
// 		g_freed++;
// 		free(content);
// 	}
// }

// static t_list *create_list(int size)
// {
// 	t_list	*list;
// 	t_list	*new_node;
// 	int		*number;
// 	int		i;

// 	list = NULL;
// 	i = 0;
// 	while (i < size)
// 	{
// 		number = malloc(sizeof(int));
// 		if (!number)
// 			exit(EXIT_FAILURE);

// 		*number = i + 1;
// 		new_node = ft_lstnew(number);
// 		if (!new_node)
// 		{
// 			free(number);
// 			exit(EXIT_FAILURE);
// 		}
// 		ft_lstadd_back(&list, new_node);
// 		i++;
// 	}
// 	return (list);
// }

// int main(void)
// {
// 	t_list	*list;

// 	printf("\n===== ft_lstclear TESTS =====\n\n");

// 	g_freed = 0;
// 	list = create_list(3);
// 	ft_lstclear(&list, del_counter);

// 	test_result("Liste de 3 elements : liste == NULL", list == NULL);
// 	test_result("Liste de 3 elements : 3 contenus liberes", g_freed == 3);

// 	g_freed = 0;
// 	list = create_list(1);
// 	ft_lstclear(&list, del_counter);

// 	test_result("Liste de 1 element : liste == NULL", list == NULL);
// 	test_result("Liste de 1 element : 1 contenu libere", g_freed == 1);

// 	g_freed = 0;
// 	list = NULL;
// 	ft_lstclear(&list, del_counter);

// 	test_result("Liste vide : liste == NULL", list == NULL);
// 	test_result("Liste vide : aucun contenu libere", g_freed == 0);

// 	printf("\n-----------------------------\n");
// 	printf("Tests   : %d\n", g_tests);
// 	printf(GREEN "Passed  : %d" RESET "\n", g_passed);
// 	printf(RED "Failed  : %d" RESET "\n", g_tests - g_passed);
// 	printf("-----------------------------\n\n");

// 	return (0);
// }
