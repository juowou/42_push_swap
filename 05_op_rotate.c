#include "push_swap.h"
#include <unistd.h> // necessário para usar o write

// função auxiliar estática de manipulação de ponteiros para fazer a rotação (de A e B)
static void	rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	// se a lista não existir, estiver vazia ou com só 1 elemento, sai da função
	if (!stack || !*stack || !(*stack)->next)
		return ;	
	// first guarda o primeiro nó (o atual topo da stack)
	first = *stack;
	// last acha o último nó usando a função do arquivo 02_utils_list.c
	last = get_last_node(*stack);
	// o novo topo da pilha passa a ser o segundo nó
	*stack = first->next;
	// o antigo primeiro nó vai para o final, não aponta mais para ninguém
	first->next = NULL;
	// o antigo último nó agora aponta pro nó que foi pro fundo
	last->next = first;
}

// ra: desloca os elementos da stack A um nível pra cima
void	ra(t_node **stack_a)
{
	rotate(stack_a);
	// imprime a operação seguida de \n, conforme subject
	write(1, "ra\n", 3);
}

// rb: desloca os elementos da stack B um nível pra cima
void	rb(t_node **stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

// rr: roda ra e rb simultaneamente nas duas stacks
void	rr(t_node **stack_a, t_node **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}