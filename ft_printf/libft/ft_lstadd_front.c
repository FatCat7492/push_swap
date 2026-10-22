/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgrandj <crgrandj@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 12:12:42 by crgrandj          #+#    #+#             */
/*   Updated: 2026/10/09 16:52:56 by crgrandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new || !lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
}

// int	main(void)
// {
// 	t_list	*lst;

// 	lst = NULL;

// 	ft_lstadd_front(&lst, ft_lstnew("Hello"));
// 	ft_lstadd_front(&lst, ft_lstnew("World"));
// 	ft_lstadd_front(&lst, ft_lstnew("42"));

// 	while (lst)
// 	{
// 		printf("%s\n", (char *)lst->content);
// 		lst = lst->next;
// 	}
// 	return (0);
// }
