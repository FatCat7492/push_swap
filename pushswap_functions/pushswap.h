/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgrandj <crgrandj@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 11:39:52 by crgrandj          #+#    #+#             */
/*   Updated: 2026/11/03 19:17:27 by crgrandj         ###   ########.fr       */
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

typedef struct bench
{
	int		count_sa;
	int		count_sb;
	int		count_ss;
	int		count_pa;
	int		count_pb;
	int		count_ra;
	int		count_rb;
	int		count_rr;
	int		count_rra;
	int		count_rrb;
	int		count_rrr;
	int		total_count;
	int		strat;
	int		selected_strat;
	float	ini_disorder;
}	t_bench;

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
int			binary_radix_sort(t_stack **head_a, t_bench *bench);
int			check_sort(t_stack **head);
t_stack		*ft_lstlast1(t_stack *lst);
void		sa(t_stack **pointer, t_bench *bench);
void		sb(t_stack **pointer, t_bench *bench);
void		ss(t_stack **pointer1, t_stack **pointer2, t_bench *bench);
void		pa(t_stack **pointer1, t_stack **pointer2, t_bench *bench);
void		pb(t_stack **pointer1, t_stack **pointer2, t_bench *bench);
void		ra(t_stack **pointer, t_bench *bench);
void		rb(t_stack **pointer, t_bench *bench);
void		rr(t_stack **pointer1, t_stack **pointer2, t_bench *bench);
void		rra(t_stack **pointer, t_bench *bench);
void		rrb(t_stack **pointer, t_bench *bench);
void		rrr(t_stack **pointer1, t_stack **pointer2, t_bench *bench);

#endif
