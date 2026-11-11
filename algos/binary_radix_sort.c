/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_radix_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgrandj <crgrandj@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 15:17:12 by crgrandj          #+#    #+#             */
/*   Updated: 2026/11/10 17:22:53 by crgrandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap_functions/pushswap.h"

static int	rank_sort(t_stack **head)
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

static int	radix_skip_check(t_stack **head, int i)
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

static int	count_list(t_stack **head)
{
	t_stack	*temp;
	int		i;

	i = 0;
	if (!head || !*head)
		return (0);
	temp = *head;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

static void	help_sort_radix(t_stack **head_a, t_stack *head_b,
		int i, t_bench *bench)
{
	int	j;
	int	nodes_left;

	j = 0;
	nodes_left = count_list(head_a);
	while (j < nodes_left)
	{
		if (((*head_a)->rank >> i & 1) == 0)
			pb(head_a, &head_b, bench);
		else
			ra(head_a, bench);
		j++;
	}
	while (head_b)
		pa(head_a, &head_b, bench);
}

int	binary_radix_sort(t_stack **head_a, t_bench *bench)
{
	t_stack	*head_b;
	int		i;
	int		max_rank;
	int		check;

	i = -1;
	head_b = NULL;
	if (!head_a || !*head_a)
		return (1);
	max_rank = count_list(head_a) - 1;
	if (rank_sort(head_a) == -1)
		return (1);
	if (check_sort(head_a) == 1)
		return (0);
	while (i < 31 && max_rank >> ++i)
	{
		check = radix_skip_check(head_a, i);
		if (check == -1)
			return (1);
		if (check == 1)
			continue ;
		if (check == 0)
			help_sort_radix(head_a, head_b, i, bench);
	}
	return (0);
}
