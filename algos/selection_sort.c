#include "../ft_printf/libft/libft.h"
#include "../pushswap_functions/pushswap.h"

static int	find_smallest(t_stack *list_a)
{
	int	index;
	int position;
	int value;

	value = (*list_a).value;
	while ((*list_a).next != NULL)
	{
		if (value > (list_a->next-value))
		{
			value = (list_a->next-value);
			position = index;
		}
		index++;
	}
	return (position);
}

void	selection_sort(t_stack **stack_a, t_stack **stack_b)
{
	size_t	stack_size;
	int position;

	stack_size = ft_lstsize(*stack_a);
	while (*stack_a)
	{
		position = find_smallest(*stack_a);
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
	}
	while (*stack_b)
		pa(stack_a, stack_b);
}
