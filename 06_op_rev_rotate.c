#include "push_swap.h"
#include <unistd.h>

// função auxiliar estática para a rotação um nível pra baixo, o último vira o primeiro
static void	reverse_rotate(t_node **stack)
{
	t_node	*last;
	t_node	*second_to_last;

	// se a lista não existir, estiver vazia ou com só 1 elemento, sai da função
	if (!stack || !*stack || !(*stack)->next)
		return ;
    // inicia last no topo (primeiro nó) pra começar a percorrer a stack
	last = *stack;
    // penúltimo nó se tornará o novo final da lista e precisará apontar pra NULL
	second_to_last = NULL;
	// percorre a lista até o final, e guarda o rastro do penúltimo nó
	while (last->next != NULL)
	{
		second_to_last = last;
		last = last->next;
	}
	// o penúltimo nó agora passa a ser o último, logo NULL
	second_to_last->next = NULL;
	// o nó que estava por último agora aponta para o antigo topo da stack
	last->next = *stack;
	// a cabeça da lista passa a ser esse nó que acabou de subir
	*stack = last;
}

// rra: empurra todos os elementos de A um nível para baixo
void	rra(t_node **stack_a)
{
	reverse_rotate(stack_a);
	// imprime a operação seguida de \n, conforme subject
	write(1, "rra\n", 4);
}

// rrb: empurra todos os elementos de B um nível para baixo
void	rrb(t_node **stack_b)
{
	reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
}

// rrr: roda rra e rrb simultaneamente nas duas stacks
void	rrr(t_node **stack_a, t_node **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}