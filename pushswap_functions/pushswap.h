/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgrandj <crgrandj@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 11:39:52 by crgrandj          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/10/26 11:19:24 by luis             ###   ########.fr       */
=======
/*   Updated: 2026/10/25 15:40:09 by crgrandj         ###   ########.fr       */
>>>>>>> d935f7725e7cac88caa2b3d46444d3b0c5b800ad
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "../ft_printf/ft_printf.h"
# include <stdio.h>

typedef struct stack
{
	int				value;
	struct stack	*next;
}	t_stack;

int		ft_md_atoi(const char *str, int *check);
int		ft_fail(int *check);
int		ft_checknumber(char *s);
int		while_parsing(t_stack **head, char **temp);
int		ft_parsing(char *argument, t_stack **head);
void	ft_cleansplit(char **array);
void	ft_cleanstack(t_stack **head);
int		wrappercleansplit(char **temp);
int		while_add_back_dup(t_stack *current, t_stack *temp, int value);
int		add_node_back(t_stack **head, int value);

#endif
