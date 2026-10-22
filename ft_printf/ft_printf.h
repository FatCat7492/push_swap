/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgrandj <crgrandj@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 12:00:05 by crgrandj          #+#    #+#             */
/*   Updated: 2026/10/16 16:02:54 by crgrandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* includes */
# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

/* Prototype */
int	ft_printf(const char *s, ...);
int	ft_putchar_x(int c);
int	ft_putnbr_x(int n);
int	ft_putnbr_xuin(unsigned int n);
int	ft_putstr_x(char *s);
int	ft_itoabx(unsigned long n, char c);

#endif