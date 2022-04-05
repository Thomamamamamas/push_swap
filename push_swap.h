/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <tcasale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:06:30 by tcasale           #+#    #+#             */
/*   Updated: 2022/04/05 18:07:05 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libftprintf/ft_printf.h"
# include "libftprintf/libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

typedef struct s_stack
{
	int	*stack;
	int	len;
}		t_stack;

//push_swap_utils
void		init_stack(t_stack *stack_a, t_stack *stack_b);
int			stack_is_sort(t_stack *stack);

//push_swap_parsing
void		parse_stack(int argc, char **argv, t_stack *stack_a);
int			arg_is_valid(char *argv);

//push_swap_sort
void		sort_three_number(t_stack *stack_a, t_stack *stack_b);
void		sort_mini_stack(t_stack *stack_a, t_stack *stack_b);
void		sort_medium_stack(t_stack *stack_a, t_stack *stack_b);
void		sort_large_stack(t_stack *stack_a, t_stack *stack_b);

//push_swap_stack_utils
void		stack_swap(t_stack *stack_a, t_stack *stack_b, int mode);
void		stack_push(t_stack *stack_a, t_stack *stack_b, int mode);
void		stack_rotate(t_stack *stack_a, t_stack *stack_b, int mode);
void		stack_reverse_rotate(t_stack *stack_a, t_stack *stack_b, int mode);

//push_swap_stack_utils2
void		rotate(t_stack *stack);
void		reverse_rotate(t_stack *stack);
int			is_smallest(int nb, t_stack *stack);
int			is_largest(int nb, t_stack *stack);

//push_swap_debug
void		print_stacks(t_stack *stack_a, t_stack *stack_b);

#endif
