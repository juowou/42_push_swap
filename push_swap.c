#include "push_swap.h"
#include <stdio.h> // substituir por ft_printf

int main(int argc, char **argv)
{
    t_node  *stack_a;
    t_node  *stack_b;
    int error;

    stack_a = init_stack_a(argc, argv);
    if (stack_a == NULL)
    {
        printf("ERROR\n");
        return (0);
    }

    stack_b = NULL;
    stack_debug(stack_a);
    complex_radix_lsd(&stack_a);
    return (1);
}