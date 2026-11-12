/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_algos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgrandj <crgrandj@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 17:33:32 by crgrandj          #+#    #+#             */
/*   Updated: 2026/11/12 14:50:01 by crgrandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap_functions/pushswap.h"

int	check_sort(t_stack **head)
{
	t_stack	*temp;

	if (!head || !*head)
		return (-1);
	temp = *head;
	while (temp->next)
	{
		if (temp->rank > temp->next->rank)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	look_for_smallest_rank(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*smallest;
	int		count;
	int		position;

	count = 0;
	position = 0;
	temp = *stack_a;
	smallest = *stack_a;
	while (temp)
	{
		if (smallest->rank > temp->rank)
		{
			smallest = temp;
			position = count;
		}
		count++;
		temp = temp->next;
	}
	return (position);
}

int	rank_sort(t_stack **head)
{
	t_stack	*current;
	t_stack	*compare;

	if (!head || !*head)
		return (-1);
	current = *head;
	while (current)
	{
		current->rank = 0;
		compare = *head;
		while (compare)
		{
			if (compare->value < current->value)
				current->rank += 1;
			compare = compare->next;
		}
		current = current->next;
	}
	return (0);
}

int	chunking(t_stack **stack_a, int list_size, t_bench *bench)
{
	t_stack	*stack_b;

	stack_b = NULL;
	push_chunks(stack_a, &stack_b, list_size, bench);
	while (stack_b)
		push_max(stack_a, &stack_b, bench);
	return (0);
}
