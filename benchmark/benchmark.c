/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgrandj <crgrandj@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 19:50:48 by crgrandj          #+#    #+#             */
/*   Updated: 2026/11/03 20:04:00 by crgrandj         ###   ########.fr       */
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
