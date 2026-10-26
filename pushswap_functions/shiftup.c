/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shiftup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 12:35:58 by crgrandj          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/10/26 11:19:23 by luis             ###   ########.fr       */
=======
/*   Updated: 2026/10/26 11:19:20 by luis             ###   ########.fr       */
>>>>>>> d935f7725e7cac88caa2b3d46444d3b0c5b800ad
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack	*ft_lstlast(t_stack *lst);


void	shiftup(t_stack **pointer)
{
	t_stack	*head_temp;
	t_stack	*end_temp;
	
	if (!pointer || !*pointer || !(*pointer)->next)
		return ;
	head_temp = *pointer;
	*pointer = (*pointer)->next;
	end_temp = ft_lstlast(*pointer);
	end_temp->next = head_temp;
	head_temp->next = NULL;
}

void	ra(t_stack **pointer)
{
	shiftup(pointer);
	ft_printf("ra\n");
}

void	rb(t_stack **pointer)
{
	shiftup(pointer);
	ft_printf("rb\n");
}

void	rr(t_stack **pointer1, t_stack **pointer2)
{
	shiftup(pointer1);
	shiftup(pointer2);
	ft_printf("rr\n");
}

int main()
{
	t_stack node1;
	t_stack node2;
	t_stack node3;
	t_stack node4;

	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;
	node4.next = NULL;

	node1.value = 10;
	node2.value = 20;
	node3.value = 30;

	printf("Node1 value: %d\n", node1.value);
	printf("Node2 value: %d\n", node2.value);
	printf("Node3 value: %d\n\n", node3.value);

	printf("Node1 next: %p\n", node1.next);
	printf("Node2 next: %p\n", node2.next);
	printf("Node3 next: %p\n\n", node3.next);

	shiftup(&node1);
	printf("SHIFTUP\n\n");

	printf("Node1 value: %d\n", node1.value);
	printf("Node2 value: %d\n", node2.value);
	printf("Node3 value: %d\n\n", node3.value);

	printf("Node1 next: %p\n", node1.next);
	printf("Node2 next: %p\n", node2.next);
	printf("Node3 next: %p\n\n", node3.next);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	t_stack	*temp;

	if (!lst)
		return (NULL);
	temp = lst;
	while (temp->next)
		temp = temp->next;
	return (temp);
}
