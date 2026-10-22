/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushtop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgrandj <crgrandj@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 10:22:56 by crgrandj          #+#    #+#             */
/*   Updated: 2026/10/22 12:30:04 by crgrandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	pushtop(t_stack **pointer1, t_stack **pointer2)
{
	t_stack	*temp;

	if (!pointer1 || !pointer2 || !*pointer1)
		return ;
	temp = *pointer1;
	*pointer1 = (*pointer1)->next;
	temp->next = *pointer2;
	*pointer2 = temp;
}

void	pa(t_stack **pointer1, t_stack **pointer2)
{
	pushtop(pointer2, pointer1);
	ft_printf("pa\n");
}

void	pb(t_stack **pointer1, t_stack **pointer2)
{
	pushtop(pointer1, pointer2);
	ft_printf("pb\n");
}

// int main ()
// {
// 	int i;
// 	t_stack	*head_a = NULL;
// 	t_stack	*head_b = NULL;
// 	t_stack	*temp_a;
// 	t_stack	*temp_b;
// 	t_stack	node1a;
// 	t_stack	node1b;
// 	t_stack	node2a;
// 	t_stack	node2b;

// 	i = 1;

// 	head_a = &node1a;
// 	head_b = &node1b;
// 	temp_a = head_a;
// 	temp_b = head_b;

// 	node1a.value = 42;
// 	node1a.next = &node2a;
// 	node1b.value = 21;
// 	node1b.next = &node2b;

// 	node2a.value = 10;
// 	node2a.next = NULL;
// 	node2b.value = 5;
// 	node2b.next = NULL;
	
// 	printf("test1\n");
// 	printf("avant a\n");
// 	while (temp_a)
// 	{
// 		printf("stack%ia: %d\n", i, temp_a->value);
// 		printf("stack%ib: %d\n", i, temp_b->value);
// 		temp_a = temp_a->next;
// 		temp_b = temp_b->next;
// 		i++;
// 	}
// 	pa(&head_a, &head_b);
// 	temp_a = head_a;
// 	temp_b = head_b;
// 	i = 1;
// 	printf("apres a\n");
// 	while (temp_a)
// 	{
// 		printf("stack%ia: %d\n", i, temp_a->value);
// 		temp_a = temp_a->next;
// 		i++;
// 	}
// 	pb(&head_a, &head_b);
// 	i = 1;
// 	temp_a = head_a;
// 	temp_b = head_b;
// 	printf("test2\n");
// 	printf("avant b\n");
// 	while (temp_b)
// 	{
// 		printf("stack%ia: %d\n", i, temp_a->value);
// 		printf("stack%ib: %d\n", i, temp_b->value);
// 		temp_a = temp_a->next;
// 		temp_b = temp_b->next;
// 		i++;
// 	}
// 	pb(&head_a, &head_b);
// 	temp_a = head_a;
// 	temp_b = head_b;
// 	i = 1;
// 	printf("apres b\n");
// 	while (temp_b)
// 	{
// 		printf("stack%ib: %d\n", i, temp_b->value);
// 		temp_b = temp_b->next;
// 		i++;
// 	}
// 	i = 1;
// 	printf("apres b\n");
// 	while (temp_a)
// 	{
// 		printf("stack%ia: %d\n", i, temp_a->value);
// 		temp_a = temp_a->next;
// 		i++;
// 	}
// 	return (0);
// }
