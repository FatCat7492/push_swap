/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_radix_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgrandj <crgrandj@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 15:17:12 by crgrandj          #+#    #+#             */
/*   Updated: 2026/10/29 15:31:20 by crgrandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap_functions/pushswap.h"

int	rank_sort(t_stack **head)
{
	t_stack *current;
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
