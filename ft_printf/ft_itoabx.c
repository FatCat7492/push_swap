/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgrandj <crgrandj@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 13:26:20 by crgrandj          #+#    #+#             */
/*   Updated: 2026/10/15 16:34:00 by crgrandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_while(char *s, unsigned long n, char *base);
static char	*ft_base(char c);

int	ft_itoabx(unsigned long n, char c)
{
	char	*s;
	int		count;
	char	*base;

	count = 0;
	if (c == 'p' && (void *)n == NULL)
	{
		write (1, "(nil)", 5);
		count = 5;
		return (count);
	}
	s = malloc(sizeof(unsigned long) * 2 + 1);
	if (!s)
		return (-1);
	base = (char *)ft_base(c);
	if (c == 'p')
	{
		write(1, "0x", 2);
		count = 2;
	}
	ft_while(s, n, base);
	count += ft_putstr_x(s);
	free(s);
	return (count);
}

static char	*ft_base(char c)
{
	char	*base;

	if (c == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	return (base);
}

static void	ft_while(char *s, unsigned long n, char	*base)
{
	int				i;
	unsigned long	temp;

	temp = n;
	i = 0;
	while (n >= 16)
	{
		n /= 16;
		i++;
	}
	s[i + 1] = '\0';
	n = temp;
	while (i >= 0)
	{
		s[i] = base[n % 16];
		n = n / 16;
		i--;
	}
}
