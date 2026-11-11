/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgrandj <crgrandj@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 17:53:13 by crgrandj          #+#    #+#             */
/*   Updated: 2026/11/10 18:16:57 by crgrandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap_functions/pushswap.h"

int	check_sort_bonus(t_stack **head)
{
	t_stack	*temp;

	if (!head || !*head)
		return (-1);
	temp = *head;
	while (temp->next)
	{
		if (temp->value > temp->next->value)
			return (1);
		temp = temp->next;
	}
	return (0);
}
