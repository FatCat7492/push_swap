/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgrandj <crgrandj@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 15:26:32 by crgrandj          #+#    #+#             */
/*   Updated: 2026/11/10 16:26:43 by crgrandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap_functions/pushswap.h"

static void	print_disorder_ini(t_bench *bench)
{
	float	value;
	int		complete;
	int		towrite;

	value = bench->ini_disorder;
	value *= 10000;
	complete = value;
	towrite = complete / 100;
	bench_print_integer(towrite, "[bench]   disorder:  ");
	write(2, ".", 1);
	towrite = complete % 100;
	if (towrite < 10)
	{
		write(2, "0", 1);
	}
	bench_print_integer(towrite, "");
	write(2, "%", 1);
}

static void	bench_print_strategy(t_bench *bench)
{
	if (bench->strat == 4)
	{
		write(2, "adaptive -> ", 12);
		if (bench->selected_strat == 1)
			write(2, "simple -> O(n²)", 16);
		if (bench->selected_strat == 2)
			write(2, "medium -> O(n√n)", 18);
		if (bench->selected_strat == 3)
			write(2, "complex -> O(n log n)", 21);
	}
	else
	{
		if (bench->strat == 1)
			write(2, "simple -> O(n²)", 16);
		if (bench->strat == 2)
			write(2, "medium -> O(n√n)", 18);
		if (bench->strat == 3)
			write(2, "complex -> O(n log n)", 21);
	}
}

static void	bench_print_op2(t_bench *bench)
{
	benchmark_total_count(bench);
	bench_print_integer(bench->total_count, " total_ops:  ");
	write(2, "\n", 1);
	write(2, "[bench] ", 8);
	bench_print_integer(bench->count_sa, "sa:  ");
	bench_print_integer(bench->count_sb, "  sb:  ");
	bench_print_integer(bench->count_ss, "  ss:  ");
	bench_print_integer(bench->count_pa, "  pa:  ");
	bench_print_integer(bench->count_pb, "  pb:  ");
	write(2, "\n", 1);
	write(2, "[bench] ", 8);
	bench_print_integer(bench->count_ra, "ra:  ");
	bench_print_integer(bench->count_rb, "  rb:  ");
	bench_print_integer(bench->count_rr, "  rr:  ");
	bench_print_integer(bench->count_rra, "  rra:  ");
	bench_print_integer(bench->count_rrb, "  rrb:  ");
	bench_print_integer(bench->count_rrr, "  rrr:  ");
	write(2, "\n", 1);
}

void	bench_print_op(t_bench *bench)
{
	print_disorder_ini(bench);
	write(2, "\n", 1);
	write(2, "[bench] ", 8);
	write(2, "  strategy:  ", 13);
	bench_print_strategy(bench);
	write(2, "\n", 1);
	write(2, "[bench] ", 8);
	bench_print_op2(bench);
}
