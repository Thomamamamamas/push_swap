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
	int	total_move1;
	int	total_move2;
	
	nb1 = get_biggest_in_partition(b, 0);
	nb2 = get_biggest_in_partition(b, 1);

	total_move1 = get_total_move_stack(b, nb1);
	total_move2 = get_total_move_stack(b, nb2);
	if (total_move1 <= total_move2)
		return nb1;
	return nb2;
}

int	check_for_double_r(t_stk *a, t_stk *b, int nb)
{
}
