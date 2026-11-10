/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 11:55:16 by crgrandj          #+#    #+#             */
/*   Updated: 2026/11/10 16:05:04 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	freeme(t_bench *bench, t_stack **head)
{
	free(bench);
	ft_cleanstack(head);
	return (1);
}

int	error_handling(t_bench *bench, t_stack **head)
{
	write(2, "Error\n", 6);
	return (freeme(bench, head));
}
