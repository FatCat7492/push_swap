/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgrandj <crgrandj@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 19:04:21 by crgrandj          #+#    #+#             */
/*   Updated: 2026/10/16 17:37:45 by crgrandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printfcheck(va_list *args, char s)
{
	int	count;

	count = 0;
	if (s == 'c')
		count += ft_putchar_x(va_arg(*args, int));
	else if (s == 's')
		count += ft_putstr_x(va_arg(*args, char *));
	else if (s == 'p')
		count += ft_itoabx((unsigned long)va_arg(*args, void *), s);
	else if (s == 'd' || s == 'i')
		count += ft_putnbr_x(va_arg(*args, int));
	else if (s == 'u')
		count += ft_putnbr_xuin(va_arg(*args, unsigned int));
	else if (s == 'x' || s == 'X')
		count += ft_itoabx(va_arg(*args, unsigned int), s);
	else if (s == '%')
		count += ft_putchar_x('%');
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list		args;
	int			total_count;

	total_count = 0;
	if (!s)
		return (-1);
	va_start(args, s);
	while (*s)
	{
		if (*s == '%' && (*(s + 1) == 'c' || *(s + 1) == 's'
				|| *(s + 1) == 'p' || *(s + 1) == 'd' || *(s + 1) == 'i'
				|| *(s + 1) == 'u' || *(s + 1) == 'x' || *(s + 1) == 'X'
				|| *(s + 1) == '%'))
		{
			s++;
			total_count += ft_printfcheck(&args, *s);
		}
		else
			total_count += ft_putchar_x(*s);
		s++;
	}
	va_end(args);
	return (total_count);
}
