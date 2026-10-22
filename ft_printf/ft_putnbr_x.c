/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgrandj <crgrandj@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 11:57:58 by crgrandj          #+#    #+#             */
/*   Updated: 2026/10/15 16:07:35 by crgrandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_x(int n)
{
	long	nb;
	char	c;
	int		count;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
		count++;
	}
	if (nb >= 10)
		count += ft_putnbr_x((nb / 10));
	c = nb % 10 + '0';
	write(1, &c, 1);
	count++;
	return (count);
}

int	ft_putnbr_xuin(unsigned int n)
{
	unsigned long	nb;
	char			c;
	int				count;

	nb = n;
	count = 0;
	if (nb >= 10)
		count += ft_putnbr_xuin((nb / 10));
	c = nb % 10 + '0';
	write(1, &c, 1);
	count++;
	return (count);
}
