/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 16:37:28 by luis              #+#    #+#             */
/*   Updated: 2026/10/22 11:19:37 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "pushswap.h"

int main(int argc, char *argv[])
{
	int				i;
    t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	i = 0;
	while (i < argc)
	{
		a->value = 
		a = ft_lstnew((void *)ft_atoi(argv[i]));
		ft_lstadd_back(&a, a);
		i++;
	}
	
}