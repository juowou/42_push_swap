#include "push_swap.h"

int operation_pb(t_node **stack_a, t_node **stack_b)
{
    t_node  *tmp;

    if (*stack_a == NULL)
        return (0);
    tmp = create_node((*stack_a)->value);
    if (!tmp)
        return (0);
    tmp->next = *stack_b;
    *stack_b = tmp;
    tmp = *stack_a;
    *stack_a = (*stack_a)->next;
    free(tmp);
    return (1);
}

int operation_pa(t_node **stack_a, t_node **stack_b)
{
    t_node  *tmp;

    if (*stack_b == NULL)
        return (0);
    tmp = create_node((*stack_b)->value);
    if (!tmp)
        return (0);
    tmp->next = *stack_a;
    *stack_a = tmp;
    tmp = *stack_b;
    *stack_b = (*stack_b)->next;
    free(tmp);
    return (1);
}