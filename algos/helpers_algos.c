/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_algos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgrandj <crgrandj@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 17:33:32 by crgrandj          #+#    #+#             */
/*   Updated: 2026/11/01 17:52:19 by crgrandj         ###   ########.fr       */
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
