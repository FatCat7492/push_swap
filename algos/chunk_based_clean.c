#include "../ft_printf/libft/libft.h"
#include "../pushswap_functions/pushswap.h"

unsigned int	lstsize(t_stack *lst);


int	*fill_array(t_stack *stack_a, int list_size)
{
	int	i;
	int	*array;

	array = malloc(list_size * sizeof(int));
	if (!array)
		return (NULL);
	i = 0;
	while (stack_a)
	{
		array[i++] = stack_a->value;
		stack_a = stack_a->next;
	}
	return (array);
}

void	sort_array(int *array, int listsize)
{
	int	i;
	int	j;
	int	temp;

	j = 0;
	while (j < listsize)
	{
		i = 0;
		while (i < listsize - j -1)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
			}
			i++;
		}
		j++;
	}
}

int	fill_rank(t_stack *stack_a, int *array, int list_size)
{
	int	i;

	while (stack_a)
	{
		i = 0;
		while (i < list_size && stack_a->value != array[i])
			i++;
		if (i == list_size)
			return (1);
		else
		{
			stack_a->rank = i;
			stack_a = stack_a->next;
		}
	}
	return (0);
}

int main()
{
	t_stack *node1;
	t_stack *node2;
	t_stack *node3;
	t_stack *node4;
	t_stack	*node5;

	node1 = malloc(sizeof(t_stack));
	node2 = malloc(sizeof(t_stack));
	node3 = malloc(sizeof(t_stack));
	node4 = malloc(sizeof(t_stack));
	node5 = malloc(sizeof(t_stack));

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = NULL;

	node1->value = 4;
	node2->value = 2;
	node3->value = 3;
	node4->value = 1;
	node5->value = 6;

	chunk_based(&node1);

	printf("Node1 value: %d\n", node1->value);
	printf("Node2 value: %d\n", node2->value);
	printf("Node3 value: %d\n", node3->value);
	printf("Node4 value: %d\n", node4->value);
	printf("Node5 value: %d\n\n", node5->value);

	printf("Node1 next: %p\n", node1->next);
	printf("Node2 next: %p\n", node2->next);
	printf("Node3 next: %p\n", node3->next);
	printf("Node4 next: %p\n", node4->next);
	printf("Node5 next: %p\n\n", node5->next);

	printf("Node1 rank: %d\n", node1->rank);
	printf("Node2 rank: %d\n", node2->rank);
	printf("Node3 rank: %d\n", node3->rank);
	printf("Node4 rank: %d\n", node4->rank);
	printf("Node5 rank: %d\n", node5->rank);

	return (0);
}

unsigned int	lstsize(t_stack *lst)
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