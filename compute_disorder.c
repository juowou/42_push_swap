#include "push_swap.h"

// calcula a metrica de desorganização do stack
// dividindo o número de erros (se stack[i] > stack[i+1])
// pelo numero total de pares

// EXEMPLO:
// 2, 1, 3, 4
// Número total de erros: 1 { 2 > 1 }! 
// Número total de pares: 3 {2 e 1} {1 e 3}, {3 e 4}
// DISORDER METRIC => 1/3 = 0.333 
// (está 33% desorganizado, ou 67% organizado)

float   compute_disorder(t_node *stack)
{
    t_node  *next_stack;
    float mistakes;
    float total_pairs;

    if (stack == NULL || stack->next == NULL)
        return (0);
    next_stack = stack->next;
    mistakes = 0;
    total_pairs = 0;
    while (next_stack != NULL)
    {
        total_pairs += 1;
        // se o valor do stack atual for maior do que
        // o valor do stack seguinte = +1 erro.
        if (stack->value > next_stack->value)
            mistakes += 1;
        stack = stack->next;
        next_stack = stack->next;
    }
    return (mistakes/total_pairs);
}

/*
function compute_disorder(stack a):
mistakes = 0
total_pairs = 0
for i from 0 to size(a)-1:
    for j from i+1 to size(a)-1:
        total_pairs += 1
        if a[i] > a[j]:
            mistakes += 1
return mistakes / total_pairs
*/