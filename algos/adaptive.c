
#include "../pushswap_functions/pushswap.h"

int	adaptive(t_bench *bench, t_stack **stack_a)
{
	if (bench->ini_disorder < 0.2)
	{
		bench->selected_strat = 1;
		return (selection_sort(stack_a, bench));
	}
	else if (bench->ini_disorder < 0.5)
	{
		bench->selected_strat = 2;
		return (chunk_based(stack_a, bench));
	}
	else
	{
		bench->selected_strat = 3;
		return (binary_radix_sort(stack_a, bench));
	}
}
