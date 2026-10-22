/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgrandj <crgrandj@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 14:29:09 by crgrandj          #+#    #+#             */
/*   Updated: 2026/10/07 17:37:34 by crgrandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst)
		return ;
	del(lst->content);
	free(lst);
}

// void	del(void *content)
// {
// 	free(content);
// }

// int	main(void)
// {
// 	t_list	*lst;
// 	t_list	*temp;
// 	t_list	*start;

// 	lst = NULL;
// 	lst = ft_lstnew(ft_strdup("Hello"));
// 	temp = lst;
// 	start = lst;
// 	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("World")));
// 	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("is")));
// 	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("42")));
// 	printf("temp  :[=%s=]\n\n", (char *)temp->content);
// 	while (lst){
// 		printf("lst   :[=%s=]\n", (char *)lst->content);
// 		lst = lst->next;
// 	}
// 	printf("\n");
// 	temp = temp->next->next; /* is */
// 	start->next->next = temp->next; /* world -> del>[=is=]<del -> 42 */
// 	ft_lstdelone(temp, del);
// 	while (start){
// 		printf("start :[=%s=]\n", (char *)start->content);
// 		start = start->next;
// 	}
// 	return (0);
// }
