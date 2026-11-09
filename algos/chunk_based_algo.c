

#include "../pushswap_functions/pushswap.h"

static int	get_max_pos(t_stack *stack_b)
{
	int	max_rank;
	int	max_pos;
	int	pos;

	max_rank = stack_b->rank;
	max_pos = 0;
	pos = 0;
	while (stack_b)
	{
		if (stack_b->rank > max_rank)
		{
			max_rank = stack_b->rank;
			max_pos = pos;
		}
		stack_b = stack_b->next;
		pos++;
	}
	return (max_pos);
}

static void	push_max(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	int	max_pos;
	int	size;

	max_pos = get_max_pos(*stack_b);
	size = lstsize(*stack_b);
	if (max_pos <= size / 2)
	{
		while (max_pos-- > 0)
			rb(stack_b, bench);
	}
	else
	{
		while (max_pos++ < size)
			rrb(stack_b, bench);
	}
	pa(stack_a, stack_b, bench);
}

int	chunking(t_stack **stack_a, int list_size, t_bench *bench)
{
	t_stack	*stack_b;

	stack_b = NULL;
	push_chunks(stack_a, &stack_b, list_size, bench);
	while (stack_b)
		push_max(stack_a, &stack_b, bench);
	return (0);
}

static void	push_chunks(t_stack **stack_a, t_stack **stack_b,
		int list_size, t_bench *bench)
{
	int	chunk_size;
	int	pushed;

	chunk_size = list_size / 10;
	if (chunk_size < 1)
		chunk_size = 1;
	pushed = 0;
	while (*stack_a)
	{
		if ((*stack_a)->rank <= pushed)
		{
			pb(stack_a, stack_b, bench);
			rb(stack_a, bench);
			pushed++;
		}
		else if ((*stack_a)->rank < pushed + chunk_size)
		{
			pb(stack_a, stack_b, bench);
			pushed++;
		}
		else
			ra(stack_a, bench);
	}
}


int	chunk_based(t_stack **stack_a, t_bench *bench)
{
	int		list_size;
	int		*array;

	if (!stack_a || !(*stack_a))
		return (1);
	list_size = lstsize(*stack_a);
	array = fill_array(*stack_a, list_size);
	if (!array)
		return (1);
	sort_array(array, list_size);
	if (fill_rank(*stack_a, array, list_size))
	{
		free(array);
		return (1);
	}
	free(array);
	return (chunking(stack_a, list_size, bench));
}


