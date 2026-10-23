/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 16:37:28 by luis              #+#    #+#             */
/*   Updated: 2026/10/22 17:16:45 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "pushswap.h"

int main(int argc, char *argv[])
{
	int		i;
	int		*array;
	char	**numbers;
	
    t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2 || !argv[1][0])
		return (1);
	
	write(2, "ERROR", 5);
	array = malloc ((argc - 1) * sizeof(int));
	if (!array)
		return (1);
	if (argc == 2)
	{
		numbers = ft_split(argv[1], ' ');
		i = 0;
		while (numbers[i])
		{
			array[i] = ft_atoi(numbers[i]);
			i++;
		}
	}
	if (argc > 2)
	{
		i = 1;
		while (i < argc)
		{
			array[i - 1] = argv[i];
			i++;
		}
	}
	int	j = 0;
	while (j < i)
	{
		ft_lstnew((void *)array[j]);
		ft_lstadd_back(&a, a);
		j++;
	}
}

