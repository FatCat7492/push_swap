/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgrandj <crgrandj@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 15:24:39 by crgrandj          #+#    #+#             */
/*   Updated: 2026/10/27 22:29:16 by crgrandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_cleansplit(char **array)
{
	size_t	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
		i++;
	while (i > 0)
		free(array[--i]);
	free(array);
}

void	ft_cleanstack(t_stack **head)
{
	t_stack	*temp;

	if (!head || !*head)
		return ;
	temp = *head;
	while (temp)
	{
		temp = temp->next;
		free(*head);
		*head = temp;
	}
}

int	wrappercleansplit(char **temp)
{
	ft_cleansplit(temp);
	return (1);
}

static int	while_add_back_dup(t_stack *current, t_stack *temp, int value)
{
	if (!current)
	{
		free(temp);
		return (1);
	}
	while (current)
	{
		if (value == current->value)
		{
			free(temp);
			return (1);
		}
		if (current->next == NULL)
		{
			current->next = temp;
			return (0);
		}
		current = current->next;
	}
	return (0);
}

int	add_node_back(t_stack **head, int value)
{
	t_stack	*temp;
	t_stack	*current;

	if (!head)
		return (1);
	temp = malloc(sizeof(t_stack));
	if (!temp)
		return (1);
	temp->value = value;
	temp->next = NULL;
	if (!*head)
	{
		*head = temp;
		return (0);
	}
	current = *head;
	return (while_add_back_dup(current, temp, value));
}
