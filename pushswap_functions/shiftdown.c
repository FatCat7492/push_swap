/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shiftdown.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgrandj <crgrandj@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 12:36:02 by crgrandj          #+#    #+#             */
/*   Updated: 2026/11/03 16:52:11 by crgrandj         ###   ########.fr       */
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
	last_node = ft_lstlast1(*pointer);
	penultimate_node = ft_lst_penultimate(*pointer);
	last_node->next = *pointer;
	*pointer = last_node;
	penultimate_node->next = NULL;
}

// A tester dans le cas d'une liste a 1 elem.
static t_stack	*ft_lst_penultimate(t_stack *lst)
{
	t_stack	*temp;

	if (!lst)
		return (NULL);
	temp = lst;
	while (temp->next->next)
		temp = temp->next;
	return (temp);
}

void	rra(t_stack **pointer, t_bench *bench)
{
	shiftdown(pointer);
	bench->count_rra += 1;
	ft_printf("rra\n");
}

void	rrb(t_stack **pointer, t_bench *bench)
{
	shiftdown(pointer);
	bench->count_rrb += 1;
	ft_printf("rrb\n");
}

void	rrr(t_stack **pointer1, t_stack **pointer2, t_bench *bench)
{
	shiftdown(pointer1);
	shiftdown(pointer2);
	bench->count_rrr += 1;
	ft_printf("rrr\n");
}
