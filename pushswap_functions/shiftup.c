/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shiftup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgrandj <crgrandj@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 12:35:58 by crgrandj          #+#    #+#             */
/*   Updated: 2026/10/22 12:48:01 by crgrandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	shiftup(t_stack **pointer)
{
	t_stack	*temp;
	
	if (!pointer || !*pointer || !(*pointer)->next)
		return ;
		
}

void	ra(t_stack **pointer)
{
	shiftup(pointer);
	ft_printf("ra\n");
}

void	rb(t_stack **pointer)
{
	shiftup(pointer);
	ft_printf("rb\n");
}

void	rr(t_stack **pointer1, t_stack **pointer2)
{
	shiftup(pointer1);
	shiftup(pointer2);
	ft_printf("rr\n");
}
