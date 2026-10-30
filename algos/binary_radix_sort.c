/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_radix_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgrandj <crgrandj@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 15:17:12 by crgrandj          #+#    #+#             */
/*   Updated: 2026/10/30 18:11:57 by crgrandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap_functions/pushswap.h"

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

int	radix_skip_check(t_stack **head, int i)
{
	t_stack	*current;

	if (!head || !*head)
		return (-1);
	if (i < 0 || i >= 32)
		return (-1);
	current = *head;
	while (current->next)
	{
		if ((current->rank >> i & 1) && (current->next->rank >> i & 1) == 0)
			return (0);
		current = current->next;
	}
	return (1);
}
