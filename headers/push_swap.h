/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <tcasale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:06:30 by tcasale           #+#    #+#             */
/*   Updated: 2022/09/22 12:43:18 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../srcs/libftprintf/ft_printf.h"
# include "../srcs/libftprintf/libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

typedef struct s_stk
{
	int	*stk;
	int	len;
	int	top;
	int	bottom;
	int	min;
	int	max;
	int	first;
	int	second;
	int	third;
}		t_stk;

typedef struct s_lst
{
	int	*lst;
	int	len;
}		t_lst;

//push_swap_utils
void		init_stack(t_stk *a, t_stk *b);
void		free_stacks(t_stk *a, t_stk *b);
int			stack_is_sort(t_stk *stk);
void		get_three_biggest_nb(t_stk *stk);

//push_swap_utils2
int			get_number_index(t_stk *stk, int nb);
int			is_in_lst(int n, t_lst *lst);
int			index_largest_nb(int nb, t_lst *lst);
void		append_lst(int nb, t_lst *lst);
int			is_not_duplicate(t_stk *stk);

//push_swap_parsing
void		parsing(int argc, char **argv, t_stk *a);
int			char_is_valid(char *str);
int			str_is_negative(char *str);
void		update_stk_parse(t_stk *stk, char *tmp);
void		handle_parse_error(t_stk *stk_a);

//push_swap_sort
void		sort_three_number(t_stk *a, t_stk *b);
void		sort_mini_stack(t_stk *a, t_stk *b);
void		sort_medium_stack(t_stk *a, t_stk *b);
void		sort_large_stack(t_stk *a, t_stk *b);

//push_swap_sort_utils
void		medium_stack_empty_a(t_stk *a, t_stk *b);
int			get_hold_position(t_stk *a, t_lst *hold, t_lst *chunk);
void		push_chunk_to_b(t_stk *a, t_stk *b, t_lst *hold);
int			valide_hold(int nb, t_lst *hold, t_lst *chunk);

//push_swap_sort_utils2
t_lst		get_chunk(t_stk *a, t_lst *hold);
void		smart_rotate(t_stk *a, t_stk *b, int position);
void		smart_push_to_b(t_stk *a, t_stk *b);

//push_swap_stack_utils
void		stack_swap(t_stk *a, t_stk *b, int mode);
void		stack_push(t_stk *a, t_stk *b, int mode);
void		stack_rotate(t_stk *a, t_stk *b, int mode);
void		stack_reverse_rotate(t_stk *a, t_stk *b, int mode);

//push_swap_stack_utils2
void		rotate(t_stk *stk);
void		reverse_rotate(t_stk *stk);
int			get_smallest(t_stk *stk);
int			get_largest(t_stk *stk);
int			get_position(t_stk *stk, int nb);

//push_swap_stack_utils3
void		update_stack_data(t_stk *a, t_stk *b);
int			get_smallest_target(t_stk *stk, int nb, int actual);
int			get_target(t_stk *stk, int nb);
void		push_to_a_sorted(t_stk *a, t_stk *b);

//push_swap_debug
void		print_stacks(t_stk *a, t_stk *b);
void		print_chunk(t_lst *chunk);
void		print_hold(t_lst *hold);

#endif
