/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shiftdown.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 12:36:02 by crgrandj          #+#    #+#             */
/*   Updated: 2026/10/26 11:19:21 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// A tester

void	shiftdown(t_stack **pointer)
{
	t_stack	*last_node;
	t_stack	*penultimate_node;
	
	if (!pointer || !*pointer || !(*pointer)->next)
		return ;
	last_node = ft_lstlast(*pointer);
	penultimate_node = ft_lst_penultimate(*pointer);
	last_node->next = *pointer;
	*pointer = last_node;
	penultimate_node->next = NULL;
}
// A tester dans le cas d'une liste a 1 elem.
static t_list	*ft_lst_penultimate(t_list *lst)
{
	t_list	*temp;

	if (!lst)
		return (NULL);
	temp = lst;
	while (temp->next->next)
		temp = temp->next;
	return (temp);
}

void	rra(t_stack **pointer)
{
	shiftdown(pointer);
	ft_printf("rra\n");
}

void	rrb(t_stack **pointer)
{
	shiftdown(pointer);
	ft_printf("rrb\n");
}

void	rrr(t_stack **pointer1, t_stack **pointer2)
{
	shiftdown(pointer1);
	shiftdown(pointer2);
	ft_printf("rrr\n");
}
