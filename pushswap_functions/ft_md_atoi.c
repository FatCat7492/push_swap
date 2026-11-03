/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgrandj <crgrandj@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 21:45:16 by crgrandj          #+#    #+#             */
/*   Updated: 2026/11/03 17:07:45 by crgrandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	ft_fail(int *check)
{
	*check = 1;
	return (0);
}

int	ft_md_atoi(const char *str, int *check)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	if (!check)
		return (0);
	if (!str)
		return (ft_fail(check));
	*check = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i++] - '0') * sign;
		if (res > INT_MAX || res < INT_MIN)
			return (ft_fail(check));
	}
	return (res);
}
