#include "push_swap.h"

t_node *operation_pa(t_node *stack_a, t_node *stack_b)
{
    t_node  *tmp_a;
    t_node  *tmp_b;

    tmp_a = NULL;
    tmp_b = NULL;
    if (stack_a == NULL)
    {
        printf("ERROR: stack_a == NULL\n");
        return (NULL);
    }
    if (stack_a->next == NULL)
    {
        printf("ERROR: stack_a has only one argument (can't push)\n");
        return (NULL);
    }
    if (stack_b == NULL)
        stack_b = create_node(stack_a->value);
    else if (stack_b != NULL)
    {
        tmp_b = create_node(stack_a->value);
        tmp_b->next = stack_b;
        stack_b = tmp_b;
    }
    while (stack_a->next != NULL)
    {
        tmp_a = stack_a->next;
        stack_a->value = tmp_a->value;
        if (tmp_a->next == NULL)
        {
            free(tmp_a);
            stack_a->next = NULL;
            return (stack_b);
        }
        stack_a = stack_a->next;
    }
    return (NULL);
}