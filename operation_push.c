#include "push_swap.h"

// a operação vai ser a mesma, quer seja pa (stack_a -> stack_b), quer seja pb (stack_b -> stack_a)
// só mudam os parametros: (t_node **stack_a -> t_node **stack_b)

int operation_push(t_node **stack_a, t_node **stack_b)
{
    // EXEMPLO:
    // **stack_a = 1, 2, 3  (3 nodes)
    // **stack_b = 4, 5     (2 nodes)
    t_node  *tmp;

    if (*stack_a == NULL)
        return (0);

    // tmp = novo node, com o valor copiado do stack_a->value
    tmp = create_node((*stack_a)->value);
    // tmp = 1 (stack_a->value), tmp->next = NULL
    if (!tmp)
        return (0);

    // o proximo node do tmp é o atual topo do stack_b
    tmp->next = *stack_b;
    // tmp = 1, tmp->next = 4 (*stack_b)

    // o *stack_b passa a apontar para o tmp
    *stack_b = tmp;
    // *stack_b = 1 (*tmp)
    // **stack_b = 1, 4, 5
    // **stack_a = 1, 2, 3

    // STACK_B CONCLUIDO. LIMPAR STACK_A:
    // tmp = atual topo do stack_a (que foi copiado para o stack_b)
    tmp = *stack_a;
    // tmp = 1 (*stack_a)

    // *stack_a passa para o proximo item (stack_a->next);
    *stack_a = (*stack_a)->next;
    // stack_a = 2 (*stack_a->next);

    // eliminar *tmp (antigo topo do stack_a) (que foi copiado para o stack_b)
    free(tmp);
    // tmp = 1 -> eliminado;

    // **stack_a = 2, 3     (2 nodes)
    // **stack_b = 1, 4, 5  (3 nodes)
    return (1);
}

int pa(t_node **stack_a, t_node **stack_b)
{
    if (operation_push(stack_b, stack_a))
    {
        printf("pa\n");
        return (1);
    }
    return (0);
}

int pb(t_node **stack_a, t_node **stack_b)
{
    if (operation_push(stack_a, stack_b))
    {
        printf("pb\n");
        return (1);
    }
    return (0);
}
