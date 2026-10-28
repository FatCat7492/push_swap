/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgrandj <crgrandj@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 11:39:52 by crgrandj          #+#    #+#             */
/*   Updated: 2026/10/28 16:15:16 by crgrandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "../ft_printf/ft_printf.h"
# include <stdio.h>

typedef struct stack
{
	int				value;
	int				rank;
	struct stack	*next;
}	t_stack;

int			ft_md_atoi(const char *str, int *check);
int			ft_parsing(char *argument, t_stack **head);
void		ft_cleansplit(char **array);
void		ft_cleanstack(t_stack **head);
int			wrappercleansplit(char **temp);
int			add_node_back(t_stack **head, int value);
int			ft_checkstrat(int argc, char **argv, int *check);
int			help_cmp_flag(char *argv, char *flag);
int			ft_parsing_ultimate(int argc, int *check_bench, char **argv,
									t_stack **head);
t_stack		*ft_lstlast1(t_stack *lst);
void		sa(t_stack **pointer);
void		sb(t_stack **pointer);
void		ss(t_stack **pointer1, t_stack **pointer2);
void		pa(t_stack **pointer1, t_stack **pointer2);
void		pb(t_stack **pointer1, t_stack **pointer2);
void		ra(t_stack **pointer);
void		rb(t_stack **pointer);
void		rr(t_stack **pointer1, t_stack **pointer2);
void		rra(t_stack **pointer);
void		rrb(t_stack **pointer);
void		rrr(t_stack **pointer1, t_stack **pointer2);

#endif
