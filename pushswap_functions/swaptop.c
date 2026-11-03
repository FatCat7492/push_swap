/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaptop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgrandj <crgrandj@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 16:21:40 by crgrandj          #+#    #+#             */
/*   Updated: 2026/10/27 22:30:01 by crgrandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	swaptop(t_stack **pointer)
{
	t_stack	*temp;

	if (!pointer || !*pointer || !(*pointer)->next)
		return ;
	temp = (*pointer)->next;
	(*pointer)->next = temp->next;
	temp->next = (*pointer);
	*pointer = temp;
}

void	sa(t_stack **pointer)
{
	swaptop(pointer);
	ft_printf("sa\n");
}

void	sb(t_stack **pointer)
{
	swaptop(pointer);
	ft_printf("sb\n");
}

void	ss(t_stack **pointer1, t_stack **pointer2)
{
	swaptop(pointer1);
	swaptop(pointer2);
	ft_printf("ss\n");
}

// int main()
// {
// 	t_stack	node1;
// 	t_stack	node2;
// 	t_stack	node3;
// 	t_stack	*head;
// 	t_stack	*temp;

// 	temp = NULL;
// 	head = NULL;
// 	head = &node1;
// 	temp = head;
// 	node1.value = 42;
// 	node1.next = &node2;

// 	node2.value = 21;
// 	node2.next = &node3;

// 	node3.value = 10;
// 	node3.next = NULL;
// 	temp = head;
// 	printf("test 1\n");
// 	while (temp)
// 	{
// 		printf("%d, ", temp->value);
// 		temp = temp->next;
// 	}
// 	printf("\n");
// 	swaptop(&head);
// 	temp = head;
// 	while (temp)
// 	{
// 		printf("%d, ", temp->value);
// 		temp = temp->next;
// 	}
// 	printf("\n");
// 	swaptop(&head);
// 	node2.next = NULL;
// 	printf("test 2\n");
// 	temp = head;
// 	while (temp)
// 	{
// 		printf("%d, ", temp->value);
// 		temp = temp->next;
// 	}
// 	printf("\n");
// 	swaptop(&head);
// 	temp = head;
// 	while (temp)
// 	{
// 		printf("%d, ", temp->value);
// 		temp = temp->next;
// 	}
// 	printf("\n");
// 	swaptop(&head);
// 	printf("test 3\n");
// 	temp = head;
// 	node1.next = NULL;
// 	while (temp)
// 	{
// 		printf("%d, ", temp->value);
// 		temp = temp->next;
// 	}
// 	printf("\n");
// 	swaptop(&head);
// 	temp = head;
// 	while (temp)
// 	{
// 		printf("%d, ", temp->value);
// 		temp = temp->next;
// 	}
// 	printf("\n");
// 	printf("test 4\n");
// 	head = NULL;
// 	swaptop(&head);
// 	temp = head;
// 	while (temp)
// 	{
// 		printf("%d, ", temp->value);
// 		temp = temp->next;
// 	}
// 	return (0);
// }

// int main()
// {
// 	int i = 1;
// 	t_stack	*head_a;
// 	t_stack	*head_b;
// 	t_stack	node1a;
// 	t_stack	node1b;
// 	t_stack	node2a;
// 	t_stack	node2b;
// 	t_stack	*temp_a;
// 	t_stack	*temp_b;

// 	head_a = NULL;
// 	head_b = NULL;
// 	temp_a = NULL;
// 	temp_b = NULL;
// 	head_a = &node1a;
// 	head_b = &node1b;
// 	temp_a = head_a;
// 	temp_b = head_b;

// 	node1a.value = 42;
//  	node1a.next = &node2a;
// 	node1b.value = 10;
//  	node1b.next = &node2b;

// 	node2a.value = 21;
//  	node2a.next = NULL;
// 	node2b.value = 5;
//  	node2b.next = NULL;

// 	temp_a = head_a;
// 	temp_b = head_b;
// 	while (temp_a)
// 	{
// 		printf("STACK%ia: %d\n", i, temp_a->value);
// 		printf("STACK%ib: %d\n", i, temp_b->value);
// 		temp_a = temp_a->next;
// 		temp_b = temp_b->next;
// 		i++;
// 	}
// 	ss(&head_a, &head_b);
// 	temp_a = head_a;
// 	temp_b = head_b;
// 	i = 1;
// 	while (temp_a)
// 	{
// 		printf("STACK%ia: %d\n", i, temp_a->value);
// 		printf("STACK%ib: %d\n", i, temp_b->value);
// 		temp_a = temp_a->next;
// 		temp_b = temp_b->next;
// 		i++;
// 	}

// }