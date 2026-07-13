#include "push_swap.h"

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