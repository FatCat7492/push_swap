/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkstat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgrandj <crgrandj@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 15:17:13 by crgrandj          #+#    #+#             */
/*   Updated: 2026/10/27 20:22:57 by crgrandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	get_strat(int c, int *strat)
{
	if (!strat)
		return (-1);
	if (*strat != 0)
		return (-1);
	*strat = c;
	return (1);
}

static int	help_cmp_flag(char *argv, char *flag)
{
	if (!argv || !flag)
		return (-1);
	if (ft_strncmp(argv, flag, ft_strlen(flag)) == 0
		&& ft_strlen(argv) == ft_strlen(flag))
		return (0);
	return (-1);
}

static int	strat_helper(char *s, int *strat)
{
	if (!s || !strat)
		return (-1);
	if (s[0] == '-' && s[1] == '-')
	{
		if (help_cmp_flag(s, "--simple") == 0)
			return (get_strat(1, strat));
		else if (help_cmp_flag(s, "--medium") == 0)
			return (get_strat(2, strat));
		else if (help_cmp_flag(s, "--complex") == 0)
			return (get_strat(3, strat));
		else if (help_cmp_flag(s, "--adaptive") == 0)
			return (get_strat(4, strat));
	}
	return (0);
}

static int	banana(char *s, int *strat)
{
	int	c;

	c = strat_helper(s, strat);
	if (c == -1)
		return (c);
	else if (s[0] == '-' && s[1] == '-' && c == 0)
		return (-1);
	return (0);
}

int	checkstrat(int argc, char **argv, int *check)
{
	int	i;
	int	strat;

	i = 1;
	strat = 0;
	if (!argv || !*argv || !check)
		return (-1);
	*check = 0;
	while (i < argc)
	{
		if (help_cmp_flag(argv[i], "--bench") == 0)
		{
			*check += 1;
			if (*check > 1)
				return (-1);
		}
		else if (banana (argv[i], &strat) == -1)
			return (-1);
		i++;
	}
	if (strat == 0)
		strat = 4;
	return (strat);
}
