/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgrandj <crgrandj@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 14:14:36 by crgrandj          #+#    #+#             */
/*   Updated: 2026/10/07 14:24:19 by crgrandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_lstsize(t_list *lst)
{
	size_t	count;

	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

// int	main(void)
// {
// 	t_list	*lst;
// 	size_t	count;

// 	count = 0;
// 	lst = NULL;

// 	ft_lstadd_front(&lst, ft_lstnew("Hello"));
// 	ft_lstadd_front(&lst, ft_lstnew("World"));
// 	ft_lstadd_front(&lst, ft_lstnew("42"));

// 	count = ft_lstsize(lst);

// 	printf("[ count : %zu ]\n", count);
// 	return (0);
// }
