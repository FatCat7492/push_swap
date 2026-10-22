/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgrandj <crgrandj@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 17:36:32 by crgrandj          #+#    #+#             */
/*   Updated: 2026/10/10 18:17:03 by crgrandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*newobj;

	newlist = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		newobj = ft_lstnew(f(lst->content));
		if (!newobj)
		{
			ft_lstclear(&newlist, del);
			return (NULL);
		}
		ft_lstadd_back(&newlist, newobj);
		lst = lst->next;
	}
	return (newlist);
}

//============================================================

// #include "libft.h"
// #include <stdio.h>
// #include <stdlib.h>

// #define GREEN  "\033[0;32m"
// #define RED    "\033[0;31m"
// #define RESET  "\033[0m"
// #define CYAN   "\033[0;36m"

// static int g_total = 0;
// static int g_pass = 0;
// static int g_fail = 0;

// /* Fonction appliquee a chaque element : multiplie par 2 */
// static void *double_content(void *content)
// {
// 	int *result;

// 	if (!content)
// 		return (NULL);
// 	result = malloc(sizeof(int));
// 	if (!result)
// 		return (NULL);
// 	*result = (*(int *)content) * 2;
// 	return (result);
// }

// /* Fonction de liberation du contenu */
// static void del_content(void *content)
// {
// 	free(content);
// }

// /* Affiche un resultat et met a jour les compteurs */
// static void check(char *name, int condition)
// {
// 	g_total++;
// 	if (condition)
// 	{
// 		g_pass++;
// 		printf(GREEN "[OK]   " RESET "%s\n", name);
// 	}
// 	else
// 	{
// 		g_fail++;
// 		printf(RED "[FAIL] " RESET "%s\n", name);
// 	}
// }

// /* Cree une liste contenant les valeurs 1, 2, 3 */
// static t_list *create_list(void)
// {
// 	t_list *list;
// 	int *value;
// 	int i;

// 	list = NULL;
// 	i = 1;
// 	while (i <= 3)
// 	{
// 		value = malloc(sizeof(int));
// 		if (!value)
// 		{
// 			ft_lstclear(&list, del_content);
// 			return (NULL);
// 		}
// 		*value = i;
// 		ft_lstadd_back(&list, ft_lstnew(value));
// 		i++;
// 	}
// 	return (list);
// }

// static void test_basic(void)
// {
// 	t_list *lst;
// 	t_list *mapped;

// 	printf(CYAN "\n--- TEST 1 : Mapping basique ---\n" RESET);

// 	lst = create_list();
// 	check("Creation de la liste", lst != NULL);
// 	if (!lst)
// 		return ;

// 	mapped = ft_lstmap(lst, double_content, del_content);

// 	check("ft_lstmap retourne une liste", mapped != NULL);
// 	check("La taille reste identique",
// 		ft_lstsize(mapped) == ft_lstsize(lst));

// 	if (mapped)
// 	{
// 		check("Premier element : 2",
// 			*(int *)mapped->content == 2);
// 		check("Deuxieme element : 4",
// 			*(int *)mapped->next->content == 4);
// 		check("Troisieme element : 6",
// 			*(int *)mapped->next->next->content == 6);
// 		check("Les contenus sont independants",
// 			mapped->content != lst->content);
// 	}

// 	ft_lstclear(&lst, del_content);
// 	ft_lstclear(&mapped, del_content);
// }

// static void test_empty_list(void)
// {
// 	t_list *mapped;

// 	printf(CYAN "\n--- TEST 2 : Liste vide ---\n" RESET);

// 	mapped = ft_lstmap(NULL, double_content, del_content);
// 	check("Une liste vide retourne NULL", mapped == NULL);
// 	ft_lstclear(&mapped, del_content);
// }

// static void test_single_element(void)
// {
// 	t_list *lst;
// 	t_list *mapped;
// 	int *value;

// 	printf(CYAN "\n--- TEST 3 : Un seul element ---\n" RESET);

// 	value = malloc(sizeof(int));
// 	if (!value)
// 	{
// 		check("Allocation du contenu", 0);
// 		return ;
// 	}
// 	*value = 42;
// 	lst = ft_lstnew(value);
// 	if (!lst)
// 	{
// 		free(value);
// 		check("Creation du noeud", 0);
// 		return ;
// 	}

// 	mapped = ft_lstmap(lst, double_content, del_content);

// 	check("Mapping d'un element",
// 		mapped && *(int *)mapped->content == 84);
// 	check("La liste source reste intacte",
// 		*(int *)lst->content == 42);

// 	ft_lstclear(&lst, del_content);
// 	ft_lstclear(&mapped, del_content);
// }

// static void print_summary(void)
// {
// 	printf(CYAN "\n========== RESULTATS ==========\n" RESET);
// 	printf("Total  : %d\n", g_total);
// 	printf(GREEN "Reussis : %d\n" RESET, g_pass);
// 	printf(RED "Echoues : %d\n" RESET, g_fail);
// 	if (g_fail == 0)
// 		printf(GREEN "\nTOUS LES TESTS SONT PASSES !\n" RESET);
// 	else
// 		printf(RED "\nCERTAINS TESTS ONT ECHOUE.\n" RESET);
// 	printf(CYAN "===============================\n" RESET);
// }

// int main(void)
// {
// 	printf(CYAN "===============================\n");
// 	printf("       TEST FT_LSTMAP\n");
// 	printf("===============================\n" RESET);

// 	test_basic();
// 	test_empty_list();
// 	test_single_element();
// 	print_summary();
// 	return (g_fail != 0);
// }