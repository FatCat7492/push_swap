#include "../ft_printf/libft/libft.h"
#include "../pushswap_functions/pushswap.h"

//Finds the smallest element in A
// Determines if its cheaper to send from the top or the bottom
// Rotate it to the top of A
// Sends it to stack B with pb
// Repeat until A is empty
// Resends everything to stack_a 

// assumes lists of >= 5 elements

size_t	size_list(t_stack *lst);


static int	find_min_position(t_stack *stack_a)
{
	int	index;
	int position;
	int value;

	index = 0;
	position = 0;
	value = (*stack_a).value;
	while ((*stack_a).next != NULL)
	{
		if (value > (stack_a->next->value))
		{
			value = (stack_a->next->value);
			position = index + 1;
		}
		stack_a = stack_a->next;
		index++; 
	}
	return (position);
}
void	push_minima_to_b(t_stack **stack_a, t_stack **stack_b, size_t stack_size)
{
	int	position;

	while (*stack_a)
	{
		position = find_min_position(*stack_a);
		if (position < (stack_size / 2))
		{
			while (position != 0)
			{
				position--;
				ra(stack_a);
			}
		}
		else
		{
			while (position < stack_size)
			{
				rra(stack_a);
				position++;
			}
		}
		pb(stack_a, stack_b);
		stack_size--;
	}
}

void	selection_sort(t_stack **stack_a)
{
	size_t	stack_size;
	t_stack *stack_b;

	stack_b = NULL;
	stack_size = size_list(*stack_a);
	push_minima_to_b(stack_a, &stack_b, stack_size);
	while (stack_b)
		pa(stack_a, &stack_b);
}

size_t	size_list(t_stack *lst)
{
	size_t	count;

	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

// int main()
// {
// 	t_stack *node1;
// 	t_stack *node2;
// 	t_stack *node3;
// 	t_stack *node4;
// 	t_stack	*node5;

// 	node1 = malloc(sizeof(t_stack));
// 	node2 = malloc(sizeof(t_stack));
// 	node3 = malloc(sizeof(t_stack));
// 	node4 = malloc(sizeof(t_stack));
// 	node5 = malloc(sizeof(t_stack));

// 	node1->next = node2;
// 	node2->next = node3;
// 	node3->next = node4;
// 	node4->next = node5;
// 	node5->next = NULL;

// 	node1->value = 4;
// 	node2->value = 2;
// 	node3->value = 3;
// 	node4->value = 1;
// 	node5->value = 6;

// 	printf("Node1 value: %d\n", node1->value);
// 	printf("Node2 value: %d\n", node2->value);
// 	printf("Node3 value: %d\n", node3->value);
// 	printf("Node4 value: %d\n", node4->value);
// 	printf("Node5 value: %d\n\n", node5->value);

// 	selection_sort(&node1);

// 	printf("\n\n");

// 	printf("Node1 value: %d\n", node1->value);
// 	printf("Node2 value: %d\n", node2->value);
// 	printf("Node3 value: %d\n", node3->value);
// 	printf("Node4 value: %d\n", node4->value);
// 	printf("Node5 value: %d\n\n", node5->value);

// 	printf("Node1 next: %p\n", node1->next);
// 	printf("Node2 next: %p\n", node2->next);
// 	printf("Node3 next: %p\n", node3->next);
// 	printf("Node4 next: %p\n", node4->next);
// 	printf("Node5 next: %p\n\n", node5->next);


// 	return (0);
// }

