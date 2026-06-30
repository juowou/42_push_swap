#include "push_swap.h"

t_node	*operation_swap(t_node *stack)
{
	int tmp;
	t_node  *next_node;

	if (stack->next == NULL)
	{
		printf("ERROR: stack->next == NULL\n");
		return (NULL);
	}
	next_node = stack->next;
	tmp = stack->value;
	stack->value = next_node->value;
	next_node->value = tmp;
	return (stack);
}

