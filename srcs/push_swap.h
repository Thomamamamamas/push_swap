/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <tcasale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:06:30 by tcasale           #+#    #+#             */
/*   Updated: 2022/08/01 17:08:00 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libftprintf/ft_printf.h"
# include "libftprintf/libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

typedef struct s_stk
{
	int	*stk;
	int	len;
	int	top;
	int	bottom;
	int	smallest;
	int	largest;
}		t_stk;

//push_swap_utils
void		init_stack(t_stk *stk_a, t_stk *stk_b);
int			stack_is_sort(t_stk *stk);
int			is_not_duplicate(t_stk *stk);
int			get_maximum_number(t_stk *stk);
int			get_smallest_step_medium(t_stk *stk);

//push_swap_utils2
int			get_number_index(t_stk *stk, int nb);

//push_swap_parsing
void		parse_stack(int argc, char **argv, t_stk *stk_a);
int			arg_is_valid(char *argv);
int			arg_is_string_of_int(char *argv);
int			*parse_string(char *argv);
void		handle_parsing_error(t_stk *stk_a);

//push_swap_parsing2
int			number_of_int_in_string(char *str);
void		update_stk_parsing(t_stk *stk, int *numbers, int len);
void		update_int_parsing(t_stk *stk);
int			check_if_negative_int_is_valid(char *str);

//push_swap_sort
void		sort_three_number(t_stk *stk_a, t_stk *stk_b);
void		sort_mini_stack(t_stk *stk_a, t_stk *stk_b);
void		sort_medium_stack(t_stk *stk_a, t_stk *stk_b);
void		sort_large_stack(t_stk *stk_a, t_stk *stk_b);

//push_swap_sort_utils
void		mini_stack_empty_b(t_stk *stk_a, t_stk *stk_b);
void		smart_fill_stack_b(t_stk *stk_a, t_stk *stk_b);
int		keep_in_stack_a(t_stk *stk_a);

//push_swap_stack_utils
void		stack_swap(t_stk *stk_a, t_stk *stk_b, int mode);
void		stack_push(t_stk *stk_a, t_stk *stk_b, int mode);
void		stack_rotate(t_stk *stk_a, t_stk *stk_b, int mode);
void		stack_reverse_rotate(t_stk *stk_a, t_stk *stk_b, int mode);

//push_swap_stack_utils2
void		rotate(t_stk *stk);
void		reverse_rotate(t_stk *stk);
int			get_smallest(t_stk *stk);
int			get_largest(t_stk *stk);
void		update_stack_data(t_stk *stk_a, t_stk *stk_b);

//push_swap_debug
void		print_stacks(t_stk *stk_a, t_stk *stk_b);

#endif
