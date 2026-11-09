/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 16:50:23 by crgrandj          #+#    #+#             */
/*   Updated: 2026/11/06 15:33:22 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap_functions/pushswap.h"

float	check_pairs_disorder(t_stack **head)
{
	t_stack	*current;
	t_stack	*compare;
	int		count_mis;
	int		total_count;

	count_mis = 0;
	total_count = 0;
	if (!head || !*head)
		return (-1);
	if (!(*head)->next)
		return ((float)count_mis);
	current = *head;
	while (current->next)
	{
		compare = current->next;
		while (compare)
		{
			if (current->value > compare->value)
				count_mis += 1;
			total_count += 1;
			compare = compare->next;
		}
		current = current->next;
	}
	return (((float)count_mis / total_count));
}
