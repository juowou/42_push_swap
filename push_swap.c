#include "push_swap.h"
#include <stdio.h> // substituir por ft_printf

void stack_debug(t_node *stack)
{
    t_node *temp = stack;
    int count = 0;
    while (temp != NULL)
    {
        printf("stack[%d] = %d\n", count, temp->value);
        temp = temp->next;
        count++;
    }
    printf("Total nodes in stack: %d\n", count);
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
    printf("\n--RUNNING DEBUG--\n");
    stack_debug(stack_a);
    printf("\n");
    stack_debug(stack_b);

    printf("\nDISORDER METRIC = %.2f\n\n", compute_disorder(stack_a));

    while (stack_a != NULL)
    {
        operation_push(&stack_a, &stack_b);
        operation_swap(&stack_b);
        printf("\n--RUNNING DEBUG--\n");
        stack_debug(stack_a);
        printf("\n");
        stack_debug(stack_b);
        printf("\nDISORDER METRIC = %.2f\n\n", compute_disorder(stack_b));
    }
    while (stack_b != NULL)
    {
        operation_swap(&stack_b);
        operation_push(&stack_b, &stack_a);
        operation_swap(&stack_b);
        printf("\n--RUNNING DEBUG--\n");
        stack_debug(stack_a);
        printf("\n");
        stack_debug(stack_b);
        printf("\nDISORDER METRIC = %.2f\n\n", compute_disorder(stack_a));
    }

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