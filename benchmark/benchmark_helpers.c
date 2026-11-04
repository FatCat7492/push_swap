/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgrandj <crgrandj@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 19:50:48 by crgrandj          #+#    #+#             */
/*   Updated: 2026/11/04 19:39:11 by crgrandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap_functions/pushswap.h"

void	benchmark_initaliser(t_bench *bench)
{
	bench->count_sa = 0;
	bench->count_sb = 0;
	bench->count_ss = 0;
	bench->count_pa = 0;
	bench->count_pb = 0;
	bench->count_ra = 0;
	bench->count_rb = 0;
	bench->count_rr = 0;
	bench->count_rra = 0;
	bench->count_rrb = 0;
	bench->count_rrr = 0;
	bench->total_count = 0;
	bench->strat = 4;
	bench->selected_strat = 4;
	bench->ini_disorder = 0.0;
}

int	benchmark_total_count(t_bench *bench)
{
	bench->total_count = bench->count_sa + bench->count_sb + bench->count_ss
		+ bench->count_pa + bench->count_pb + bench->count_ra + bench->count_rb
		+ bench->count_rr + bench->count_rra + bench->count_rrb
		+ bench->count_rrr;
	return (bench->total_count);
}

void	bench_print_integer(int value, const char *label)
{
	char	*integer;
	char	*temp;

	integer = ft_itoa(value);
	if (!integer || !label)
	{
		free(integer);
		return ;
	}
	temp = integer;
	while (*label)
		write(2, label++, 1);
	while (*temp)
		write(2, temp++, 1);
	free(integer);
}

static void	bench_print_op2(t_bench *bench)
{
	benchmark_total_count(bench);
	bench_print_integer(bench->total_count, "total_ops:  ");
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
	write(2, "strategy:  ", 11);
	/* print adaptive -> simple ect.. */
	write(2, "\n", 1);
	write(2, "[bench] ", 8);
	bench_print_op2(bench);
}
