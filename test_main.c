/* ************************************************************************** */
/*                                                                            */
/*   test_main.c - Temporary Binary Radix Sort test entry point               */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_functions/pushswap.h"

int	binary_radix_sort(t_stack **head);

int	main(int argc, char **argv)
{
	t_stack	*head;
	int		bench;
	int		strategy;

	if (argc == 1)
		return (0);
	head = NULL;
	bench = 0;
	strategy = ft_parsing_ultimate(argc, &bench, argv, &head);
	if (strategy == -1)
		return (write(2, "Error\\n", 6), 1);
	if (!head)
		return (0);
	if (binary_radix_sort(&head) == -1)
	{
		ft_cleanstack(&head);
		return (write(2, "Error\n\n", 6), 1);
	}
	ft_cleanstack(&head);
	return (0);
}
