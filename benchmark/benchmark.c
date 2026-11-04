/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgrandj <crgrandj@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 15:26:32 by crgrandj          #+#    #+#             */
/*   Updated: 2026/11/04 19:35:03 by crgrandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap_functions/pushswap.h"

void	print_disorder_ini(t_bench *bench)
{
	float	value;
	int		complete;
	int		towrite;

	value = bench->ini_disorder;
	value *= 10000;
	complete = value;
	towrite = complete / 100;
	bench_print_integer(towrite, "[bench] disorder:  ");
	write(2, ".", 1);
	towrite = complete % 100;
	if (towrite < 10)
	{
		write(2, "0", 1);
	}
	bench_print_integer(towrite, "");
	write(2, "%", 1);
}
