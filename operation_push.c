#include "push_swap.h"

// a operação vai ser a mesma, quer seja pa (stack_a -> stack_b), quer seja pb (stack_b -> stack_a)
// só mudam os parametros: (t_node **stack_a -> t_node **stack_b)

int operation_push(t_node **stack_a, t_node **stack_b)
{
    // EXEMPLO:
    // **stack_a = 1, 2, 3
    // **stack_b = 4, 5
    t_node  *tmp;

    if (*stack_a == NULL)
        return (0);

    // tmp = o node que queremos copiar para o stack_b (com o valor de stack_a->value)
    tmp = create_node((*stack_a)->value);
    // tmp = 1, tmp->next = NULL
    if (!tmp)
        return (0);

    // o proximo item do tmp é o atual topo do stack_b
    tmp->next = *stack_b;
    // tmp = 1, tmp->next = 4 (stack_b)

    // o *stack_b passa a apontar para o tmp
    *stack_b = tmp;
    // *stack_b = 1 (tmp)
    // **stack_b = 1, 4, 5
    // **stack_a = 1, 2, 3

    // STACK_B CONCLUIDO. LIMPAR STACK_A:
    // tmp = atual topo do stack_a (que foi copiado para o stack_b)
    tmp = *stack_a;
    // tmp = 1 (stack_a)

    // *stack_a passa a apontar para o proximo item (stack_a->next);
    *stack_a = (*stack_a)->next;
    // stack_a = 2 (stack_a->next);

    // eliminar o topo do stack_a (tmp) (que foi copiado para o stack_b)
    free(tmp);
    // tmp = 1 -> eliminado;

    // **stack_a = 2, 3
    // **stack_b = 1, 4, 5
    return (1);
}