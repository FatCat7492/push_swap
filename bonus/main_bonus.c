/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgrandj <crgrandj@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 14:49:25 by crgrandj          #+#    #+#             */
/*   Updated: 2026/11/11 17:04:14 by crgrandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap_functions/pushswap.h"

static int	validation2(char *line, t_stack **pointer1, t_stack **pointer2)
{
	if (ft_strncmp(line, "ra\n", 4) == 0)
		return (shiftup(pointer1), 0);
	else if (ft_strncmp(line, "rb\n", 4) == 0)
		return (shiftup(pointer2), 0);
	else if (ft_strncmp(line, "rr\n", 4) == 0)
	{
		shiftup(pointer1);
		shiftup(pointer2);
		return (0);
	}
	else if (ft_strncmp(line, "rra\n", 5) == 0)
		return (shiftdown(pointer1), 0);
	else if (ft_strncmp(line, "rrb\n", 5) == 0)
		return (shiftdown(pointer2), 0);
	else if (ft_strncmp(line, "rrr\n", 5) == 0)
	{
		shiftdown(pointer1);
		shiftdown(pointer2);
		return (0);
	}
	else
		return (-1);
}

static int	validation(char *line, t_stack **pointer1, t_stack **pointer2)
{
	if (ft_strncmp(line, "sa\n", 4) == 0)
		return (swaptop(pointer1), 0);
	else if (ft_strncmp(line, "sb\n", 4) == 0)
		return (swaptop(pointer2), 0);
	else if (ft_strncmp(line, "ss\n", 4) == 0)
	{
		swaptop(pointer1);
		swaptop(pointer2);
		return (0);
	}
	else if (ft_strncmp(line, "pa\n", 4) == 0)
		return (pushtop(pointer2, pointer1), 0);
	else if (ft_strncmp(line, "pb\n", 4) == 0)
		return (pushtop(pointer1, pointer2), 0);
	return (validation2(line, pointer1, pointer2));
}

static int	final_check(t_stack **stack_a, t_stack **stack_b)
{
	if (check_sort_bonus(stack_a) != 0 || *stack_b != NULL)
	{
		write(1, "KO\n", 3);
		ft_cleanstack(stack_a);
		ft_cleanstack(stack_b);
		return (0);
	}
	write(1, "OK\n", 3);
	ft_cleanstack(stack_a);
	ft_cleanstack(stack_b);
	return (0);
}

static int	while_gnl_bonus(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (validation(line, stack_a, stack_b) == -1)
		{
			free(line);
			ft_cleanstack(stack_a);
			ft_cleanstack(stack_b);
			write(2, "Error\n", 6);
			return (1);
		}
		free(line);
		line = get_next_line(0);
	}
	free(line);
	return (final_check(stack_a, stack_b));
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		checkparsing;
	int		i;

	stack_a = NULL;
	stack_b = NULL;
	i = 0;
	if (argc == 1)
		return (0);
	while (++i < argc)
	{
		checkparsing = ft_parsing(argv[i], &stack_a);
		if (checkparsing == 1)
		{
			ft_cleanstack(&stack_a);
			write(2, "Error\n", 6);
			return (1);
		}
	}
	return (while_gnl_bonus(&stack_a, &stack_b));
}
