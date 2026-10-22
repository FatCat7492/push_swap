/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shiftdown.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgrandj <crgrandj@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 12:36:02 by crgrandj          #+#    #+#             */
/*   Updated: 2026/10/22 12:47:57 by crgrandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	shiftdown(t_stack **pointer)
{
	t_stack	*temp;
	
	if (!pointer || !*pointer || !(*pointer)->next)
		return ;
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