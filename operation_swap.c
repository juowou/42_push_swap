#include "push_swap.h"

int	operation_swap(t_node **stack)
{
	int tmp;
	t_node  *next_node;

	if ((*stack) == NULL || (*stack)->next == NULL)
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

int	sa(t_node **stack_a)
{
	if (operation_swap(stack_a))
	{
		printf("sa\n");
		return (1);
	}
	return (0);
}

int	sb(t_node **stack_b)
{
	if (operation_swap(stack_b))
	{
		printf("sb\n");
		return (1);
	}
	return (0);
}