/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_ultimate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgrandj <crgrandj@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 22:31:40 by crgrandj          #+#    #+#             */
/*   Updated: 2026/10/28 00:13:54 by crgrandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	flag_helper(char *s)
{
	if (!s)
		return (-1);
	if (s[0] == '-' && s[1] == '-')
	{
		if (help_cmp_flag(s, "--simple") == 0)
			return (0);
		else if (help_cmp_flag(s, "--medium") == 0)
			return (0);
		else if (help_cmp_flag(s, "--complex") == 0)
			return (0);
		else if (help_cmp_flag(s, "--adaptive") == 0)
			return (0);
		else if (help_cmp_flag(s, "--bench") == 0)
			return (0);
	}
	return (-1);
}

int	ft_parsing_ultimate(int argc, int *check_bench, char **argv, t_stack **head)
{
	int	i;
	int	check_algo;
	int	check_parsing;

	i = 0;
	if (!argv || !*argv || !head || !check_bench)
		return (-1);
	check_algo = ft_checkstrat(argc, argv, check_bench);
	if (check_algo == -1)
		return (-1);
	while (++i < argc)
	{
		if (flag_helper(argv[i]) == 0)
			continue ;
		check_parsing = ft_parsing(argv[i], head);
		if (check_parsing == 1)
		{
			ft_cleanstack(head);
			return (-1);
		}
	}
	return (check_algo);
}
