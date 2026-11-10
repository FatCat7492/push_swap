#include "../ft_printf/libft/libft.h"
#include "../pushswap_functions/pushswap.h"

void	adaptive(t_stack **stack_a, t_bench *bench)
{
	if (bench->ini_disorder < 0.2)
	{
		bench->selected_strat = 1;
		return (selection_sort(stack_a));
	}
	else if (bench->ini_disorder < 0.5)
	{
		bench->selected_strat = 2;
		return (chunk_based(stack_a));
	}
	else
	{
		bench->selected_strat = 3;
		return (binary_radix_sort(stack_a));
	}
}