#include "../ft_printf/libft/libft.h"
#include "../pushswap_functions/pushswap.h"

void	adaptive(float disorder, t_stack **stack_a)
{
	if (disorder < 0.2)
		return (selection_sort(stack_a));
	else if (disorder < 0.5)
		return (chunk_based(stack_a));
	else
		return (binary_radix_sort(stack_a));
}