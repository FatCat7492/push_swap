/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgrandj <crgrandj@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 23:25:38 by crgrandj          #+#    #+#             */
/*   Updated: 2026/11/12 04:01:12 by crgrandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap_functions/pushswap.h"

static void	sort3(t_stack **stack_a, t_bench *bench)
{
	int	top;
	int	middle;
	int	bottom;

	top = (*stack_a)->rank;
	middle = (*stack_a)->next->rank;
	bottom = (*stack_a)->next->next->rank;
	if (top > middle && middle < bottom && top < bottom)
		sa(stack_a, bench);
	else if (top > middle && middle < bottom && top > bottom)
		ra(stack_a, bench);
	else if (top < middle && middle > bottom && top > bottom)
		rra(stack_a, bench);
	else if (top > middle && middle > bottom && top > bottom)
	{
		sa(stack_a, bench);
		rra(stack_a, bench);
	}
	else if (top < middle && middle > bottom && top < bottom)
	{
		sa(stack_a, bench);
		ra(stack_a, bench);
	}
}

static void	sort4(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	int	position_0;

	position_0 = look_for_smallest_rank(stack_a);
	if (position_0 == 0)
	{
		pb(stack_a, stack_b, bench);
		sort3(stack_a, bench);
	}
	else if (position_0 <= 2)
	{
		while (position_0 > 0)
		{
			ra(stack_a, bench);
			position_0--;
		}
		pb(stack_a, stack_b, bench);
		sort3(stack_a, bench);
	}
	else
	{
		rra(stack_a, bench);
		pb(stack_a, stack_b, bench);
		sort3(stack_a, bench);
	}
	pa(stack_a, stack_b, bench);
}

static void	sort5(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	int	position_0;

	position_0 = look_for_smallest_rank(stack_a);
	if (position_0 <= 2)
	{
		while (position_0 > 0)
		{
			ra(stack_a, bench);
			position_0--;
		}
	}
	else
	{
		while (position_0 <= 4)
		{
			rra(stack_a, bench);
			position_0++;
		}
	}
	pb(stack_a, stack_b, bench);
	sort4(stack_a, stack_b, bench);
	pa(stack_a, stack_b, bench);
}

int	small_sort(t_stack **stack_a, t_bench *bench)
{
	t_stack	*stack_b;
	int		check_size;

	stack_b = NULL;
	check_size = lstsize(*stack_a);
	rank_sort(stack_a);
	if (check_sort(stack_a) == 1)
		return (0);
	if (check_size == 2)
		sa(stack_a, bench);
	if (check_size == 3)
		sort3(stack_a, bench);
	if (check_size == 4)
		sort4(stack_a, &stack_b, bench);
	if (check_size == 5)
		sort5(stack_a, &stack_b, bench);
	return (0);
}
