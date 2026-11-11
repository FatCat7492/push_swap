/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 16:37:28 by crgrandj          #+#    #+#             */
/*   Updated: 2026/11/11 16:49:31 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	strat_part1(int check_algo, t_bench *bench, t_stack **stack_a)
{
	if (check_algo == 1)
	{
		bench->strat = 1;
		bench->selected_strat = 1;
		if (selection_sort(stack_a, bench) == 1)
			return (1);
	}
	if (check_algo == 2)
	{
		bench->strat = 2;
		bench->selected_strat = 2;
		if (chunk_based(stack_a, bench) == 1)
			return (1);
	}
	return (0);
}

static int	strat_part2(int check_algo, t_bench *bench, t_stack **stack_a)
{
	if (check_algo == 3)
	{
		bench->strat = 3;
		bench->selected_strat = 3;
		if (binary_radix_sort(stack_a, bench) == 1)
			return (1);
	}
	if (check_algo == 4)
	{
		bench->strat = 4;
		bench->selected_strat = 4;
		if (adaptive(bench, stack_a) == 1)
			return (1);
	}
	return (0);
}

static int	choosing_strat(int check_algo, int check_bench, t_bench *bench,
		t_stack **stack_a)
{
	if (set_disorder_value(stack_a, bench) == 1)
		return (1);
	if (strat_part1(check_algo, bench, stack_a) == 1)
		return (1);
	if (strat_part2(check_algo, bench, stack_a) == 1)
		return (1);
	if (check_bench == 1)
		bench_print_op(bench);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_bench	*bench;
	int		check_bench;
	int		check_algo;

	check_bench = 0;
	stack_a = NULL;
	if (argc == 1)
		return (0);
	if (argc == 2 && ft_strncmp(argv[1], "--bench", 8) == 0)
		return (error_handling(NULL, NULL));
	bench = malloc(sizeof(t_bench));
	if (!bench)
		return (1);
	benchmark_initaliser(bench);
	check_algo = ft_parsing_ultimate(argc, &check_bench, argv, &stack_a);
	if (argc < 6)
		check_algo = 1; 
	if (check_algo == -1)
		return (error_handling(bench, NULL));
	if (choosing_strat(check_algo, check_bench, bench, &stack_a) == 1)
		return (error_handling(bench, &stack_a));
	freeme(bench, &stack_a);
	return (0);
}
