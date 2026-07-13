#include "push_swap.h"

int complex_radix_lsd(t_node **stack_a)
{
	int     div;
	int     is_sorted;
	t_node  *stack_top;
	t_node  *stack_saved;

	is_sorted = 0;
	div = 1;
	stack_top = (*stack_a);
	stack_saved = NULL;
	while (compute_disorder(stack_a) > 0)
	{
		printf("div = %d\n", div);
		while ((*stack_a)->next != NULL)
		{
			if (((*stack_a)->value / div) % 10 > (((*stack_a)->next)->value / div) % 10)
			{
				stack_saved = (*stack_a)->previous;
				while ((*stack_a) != NULL && ((*stack_a)->value / div) % 10 > (((*stack_a)->next)->value / div) % 10)
				{
					printf("stack_a = %d > stack_a->next = %d\n", (*stack_a)->value, ((*stack_a)->next)->value);
					operation_swap((*stack_a));
					(*stack_a) = (*stack_a)->previous;
					stack_debug(stack_top);
				}
				(*stack_a) = stack_saved;
			}
			(*stack_a) = (*stack_a)->next;
		}
		(*stack_a) = stack_top;
		div *= 10;
		stack_debug((*stack_a));
	}
	return (1);
}