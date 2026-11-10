/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 11:39:52 by crgrandj          #+#    #+#             */
/*   Updated: 2026/11/10 16:06:10 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "../ft_printf/libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include <stdio.h>
/* Struct general */
typedef struct stack
{
	int				value;
size_t				rank;
	struct stack	*next;
}	t_stack;
/* Struct Bench */
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

//Helpers
unsigned int	lstsize(t_stack *lst);
int				*fill_array(t_stack *stack_a, int list_size);
void			sort_array(int *array, int listsize);
int				fill_rank(t_stack *stack_a, int *array, int list_size);

// Main helpers
int	error_handling(t_bench *bench, t_stack **head);
int	freeme(t_bench *bench, t_stack **head);


/* Parsing */
int				ft_md_atoi(const char *str, int *check);
int				ft_parsing(char *argument, t_stack **head);
void			ft_cleansplit(char **array);
void			ft_cleanstack(t_stack **head);
int				wrappercleansplit(char **temp);
int				add_node_back(t_stack **head, int value);
int				ft_checkstrat(int argc, char **argv, int *check);
int				help_cmp_flag(char *argv, char *flag);
int				ft_parsing_ultimate(int argc, int *check_bench, char **argv,
					t_stack **head);
/* Algos */
int				binary_radix_sort(t_stack **head_a, t_bench *bench);
int				check_sort(t_stack **head);
t_stack			*ft_lstlast1(t_stack *lst);
unsigned int	lstsize(t_stack *lst);
int				selection_sort(t_stack **stack_a, t_bench *bench);
int				chunk_based(t_stack **stack_a, t_bench *bench);
int				adaptive(t_bench *bench, t_stack **stack_a);
/* Benchmark */
void		bench_print_integer(int value, const char *label);
int			benchmark_total_count(t_bench *bench);
void		benchmark_initaliser(t_bench *bench);
int			set_disorder_value(t_stack **head, t_bench *bench);
void		bench_print_op(t_bench *bench);

/* Operations */
void			sa(t_stack **pointer, t_bench *bench);
void			sb(t_stack **pointer, t_bench *bench);
void			ss(t_stack **pointer1, t_stack **pointer2, t_bench *bench);
void			pa(t_stack **pointer1, t_stack **pointer2, t_bench *bench);
void			pb(t_stack **pointer1, t_stack **pointer2, t_bench *bench);
void			ra(t_stack **pointer, t_bench *bench);
void			rb(t_stack **pointer, t_bench *bench);
void			rr(t_stack **pointer1, t_stack **pointer2, t_bench *bench);
void			rra(t_stack **pointer, t_bench *bench);
void			rrb(t_stack **pointer, t_bench *bench);
void			rrr(t_stack **pointer1, t_stack **pointer2, t_bench *bench);

#endif
