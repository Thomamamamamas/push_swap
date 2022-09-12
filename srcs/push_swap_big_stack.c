#include "../headers/push_swap.h"

void	empty_stack_a(t_stk *a, t_stk *b)
{
	while (a->len != 1)
	{
		if (a->top == get_largest(a))
			stack_rotate(a, b, 'a');
		else
			stack_push(a, b, 'b');
	}
}

int	get_smartest_move(t_stk *a, t_stk *b)
{
	int	nb1;
	int	nb2;
	int	target1;
	int	target2;
	int	total_move1;
	int	total_move2;
	
	nb1 = get_biggest_in_partition(b, 0);
	nb2 = get_biggest_in_partition(b, 1);
	target1 = get_position_wanted(a, nb1);
	target2 = get_position_wanted(a, nb2);
	total_move1 = get_total_move_stack(b, nb1) + get_total_move_stack(a, target1);
	total_move2 = get_total_move_stack(b, nb2) + get_total_move_stack(a, target2);
	ft_printf("__________________________\n");
	ft_printf("nb1 = %d\n", nb1);
	ft_printf("nb2 = %d\n", nb2);
	ft_printf("target1 = %d\n", target1);
	ft_printf("target2 = %d\n", target2);
	ft_printf("total_move1 = %d\n", total_move1);
	ft_printf("total_move2 = %d\n", total_move2);
	ft_printf("__________________________\n");
	if (total_move1 <= total_move2)
		return nb1;
	return nb2;
}

void	stacks_smart_rotate(t_stk *a, t_stk *b, int nb, int target)
{
	while (nb != b->top)
	{
		if (get_position(b, nb) >= b->len / 2)
		{
			if (check_for_double_r(a, b, nb, target))
				stack_rotate(a, b, 'r');
			else
				stack_rotate(a, b, 'b');
		}
		else
		{
			if (check_for_double_r(a, b, nb, target))
				stack_reverse_rotate(a, b, 'r');
			else
				stack_reverse_rotate(a, b, 'b');
		}
	}
}

void	put_target_on_top_a(t_stk *a, t_stk *b, int target)
{
	while (target != a->top)
	{
		if (get_position(a, target) >= a->len / 2)
			stack_rotate(a, b, 'a');
		else
			stack_reverse_rotate(a, b, 'a');
	}
}

void	sort_a(t_stk *a, t_stk *b)
{
	while (get_smallest(a) != a->top)
	{
		if (get_position(a, get_smallest(a)) >= a->len / 2)
			stack_rotate(a, b, 'a');
		else
			stack_reverse_rotate(a, b, 'a');
	}
}

