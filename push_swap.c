#include "push_swap.h"
#include <stdio.h> // substituir por ft_printf

void stack_debug(t_node *stack)
{
    t_node *temp = stack;
    int count = 0;
    printf("--RUNNING DEBUG--\n");
    while (temp != NULL)
    {
        printf("stack_a[%d] = %d\n", count, temp->value);
        temp = temp->next;
        count++;
    }
    printf("Total nodes in stack_a: %d\n", count);
}

int main(int argc, char **argv)
{
    t_node  *stack_a;
    t_node  *stack_b;
    int error;

    stack_a = init_stack_a(argc, argv);
    stack_b = NULL;
    if (stack_a == NULL)
    {
        printf("ERROR: stack_a == NULL\n");
        return (0);
    }
    stack_debug(stack_a);
    //stack_a = operation_swap(stack_a);
    if(!operation_pb(&stack_a, &stack_b))
    {
        printf("ERROR: operation_pb()\n");
        return (0);
    };
        stack_debug(stack_a);

    if(!operation_pb(&stack_a, &stack_b))
    {
        printf("ERROR: operation_pb()\n");
        return (0);
    };
        stack_debug(stack_a);

    if(!operation_pb(&stack_a, &stack_b))
    {
        printf("ERROR: operation_pb()\n");
        return (0);
    };
        stack_debug(stack_a);

    if(!operation_pa(&stack_a, &stack_b))
    {
        printf("ERROR: operation_pa()\n");
        return (0);
    };
        stack_debug(stack_a);

    if(!operation_pa(&stack_a, &stack_b))
    {
        printf("ERROR: operation_pa()\n");
        return (0);
    };
        stack_debug(stack_a);

    if(!operation_pa(&stack_a, &stack_b))
    {
        printf("ERROR: operation_pa()\n");
        return (0);
    };
        stack_debug(stack_a);

    //stack_b = operation_swap(stack_b);
    /*if (stack_b == NULL)
    {
        printf("ERROR: operation_pa()\n");
        return (0);
    }*/
    while (stack_a != NULL)
    {
        printf("stack_a->value == %d\n", stack_a->value);
        stack_a = stack_a->next;
    }
    printf("-----------\n");
    while (stack_b != NULL)
    {
        printf("stack_b->value == %d\n", stack_b->value);
        stack_b = stack_b->next;
    }
    
    return (1);
}