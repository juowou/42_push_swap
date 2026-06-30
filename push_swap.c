#include "push_swap.h"
#include <stdio.h> // substituir por ft_printf

int main(int argc, char **argv)
{
    t_node  *stack_a;

    stack_a = init_stack_a(argc, argv);
    if (stack_a == NULL)
    {
        printf("ERROR: stack_a == NULL\n");
        return (0);
    }
    while (stack_a != NULL)
    {
        printf("stack_a.value == %d\n", stack_a->value);
        stack_a = stack_a->next;
    }
    return (1);
}