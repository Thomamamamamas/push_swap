/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <tcasale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:06:30 by tcasale           #+#    #+#             */
/*   Updated: 2022/08/24 22:03:49 by tcasale          ###   ########.fr       */
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
}		t_stk;

typedef struct s_lst
{
	int	*lst;
	int	len;
}		t_lst;

typedef struct s_chunk
{
	t_lst	chunk;
	int		*position;
}			t_chunk;

//push_swap_utils
void		init_stack(t_stk *a, t_stk *b);
int			stack_is_sort(t_stk *stk);

//push_swap_utils2
int			get_number_index(t_stk *stk, int nb);
int			is_in_lst(int n, t_lst *lst);
int			get_index_of_larger_nb(int nb, t_lst *lst);
void		append_lst(int nb, t_lst *lst);

//push_swap_parsing
void		parse_stack(int argc, char **argv, t_stk *a);
int			arg_is_valid(char *argv);
int			arg_is_string_of_int(char *argv);
int			*parse_string(char *argv);
void		handle_parsing_error(t_stk *a);

//push_swap_parsing2
int			number_of_int_in_string(char *str);
void		update_stk_parsing(t_stk *stk, int *numbers, int len);
void		update_int_parsing(t_stk *stk);
int			check_if_negative_int_is_valid(char *str);
int			is_not_duplicate(t_stk *stk);

//push_swap_sort
void		sort_three_number(t_stk *a, t_stk *b);
void		sort_mini_stack(t_stk *a, t_stk *b);
void		sort_medium_stack(t_stk *a, t_stk *b);
void		sort_large_stack(t_stk *a, t_stk *b);

//push_swap_sort_utils
void		mini_stack_empty_b(t_stk *a, t_stk *b);
void		medium_stack_empty_a(t_stk *a, t_stk *b);
int			get_hold_position(t_stk *a, t_lst *hold, t_chunk *chunk);
int			valide_hold(int nb, t_lst *hold, t_chunk *chunk);

//push_swap_sort_utils2
t_chunk		get_chunk(t_stk *a, t_lst *hold);
void		smart_rotate(t_stk *a, t_stk *b, int position);

//push_swap_stack_utils
void		stack_swap(t_stk *a, t_stk *b, int mode);
void		stack_push(t_stk *a, t_stk *b, int mode);
void		stack_rotate(t_stk *a, t_stk *b, int mode);
void		stack_reverse_rotate(t_stk *a, t_stk *b, int mode);

//push_swap_stack_utils2
void		rotate(t_stk *stk);
void		reverse_rotate(t_stk *stk);
int			get_min(t_stk *stk);
int			get_max(t_stk *stk);
void		update_stack_data(t_stk *a, t_stk *b);

//push_swap_debug
void		print_stacks(t_stk *a, t_stk *b);
void		print_chunk(t_chunk *chunk);
void		print_hold(t_lst *hold);

#endif
