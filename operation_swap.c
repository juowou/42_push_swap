#include "push_swap.h"

int	operation_swap(t_node **stack)
{
	int tmp;
	t_node  *next_node;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("ERROR: stack->next == NULL\n");
		return (1);
	}
	next_node = (*stack)->next;
	tmp = (*stack)->value;
	(*stack)->value = next_node->value;
	next_node->value = tmp;
	return (1);
}

