/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgrandj <crgrandj@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 14:41:53 by crgrandj          #+#    #+#             */
/*   Updated: 2026/10/25 18:01:39 by crgrandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_checknumber(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (1);
	if (s[i] == '\0')
		return (1);
	if (s[i] == '-' || s[i] == '+')
	{
		i++;
		if (ft_isdigit(s[i]) == 0)
			return (1);
	}
	while (s[i])
	{
		if ((ft_isdigit(s[i]) == 0))
			return (1);
		i++;
	}
	return (0);
}

int	while_parsing(t_stack **head, char **temp)
{
	int	i;
	int	number;
	int	check;

	i = 0;
	while (temp[i])
	{
		if (ft_checknumber(temp[i]) == 1)
			return (wrappercleansplit(temp));
		number = ft_md_atoi(temp[i], &check);
		if (check == 1)
			return (wrappercleansplit(temp));
		check = add_node_back(head, number);
		if (check == 1)
			return (wrappercleansplit(temp));
		i++;
	}
	ft_cleansplit(temp);
	return (0);
}

int	ft_parsing(char *argument, t_stack **head)
{
	char	**temp;

	if (!argument || !*argument || !head)
		return (1);
	temp = ft_split(argument, ' ');
	if (!temp)
		return (1);
	if (!temp[0])
	{
		ft_cleansplit(temp);
		return (1);
	}
	return (while_parsing(head, temp));
}
