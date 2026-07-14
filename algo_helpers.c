#include "push_swap.h"

// varre a lista toda e devolve a posição onde o menor número está
int	find_min_index(t_node *stack)
{
	int		min_index;
	int		current_index;
	t_node	*min_node;

	if (!stack)
		return (-1); // retorno de segurança para lista vazia
	// usar esta função do arquivo 01_utils_math.c para descobrir qual é o menor nó
	min_node = find_min_node(stack);
	
	current_index = 0;
	min_index = 0;
	// varre a lista para descobrir em qual posição esse nó tá
	while (stack)
	{
		// quando o nó atual estiver no mesmo endereço do menor nó, achamos o índice
		if (stack == min_node)
		{
			min_index = current_index;
			break ; // como já achamos o índice, podemos quebrar o loop
		}
		current_index++;
		stack = stack->next;
	}
	return (min_index);
}

// ordena uma stack de 3 números 
void sort_three(t_node **stack_a)
{
	t_node	*max_node;

	// descobrir qual é o maior número dos 3
	max_node = find_max_node(*stack_a);

	// mandar o maior número para o fundo da stack
	// se o maior estiver no topo (primeiro nó), roda tudo pra cima (ra)
	if (*stack_a == max_node)
		ra(stack_a);
	// se o maior estiver no meio (segundo nó), roda pro inverso (rra)
	else if ((*stack_a)->next == max_node)
		rra(stack_a);

	// agora o maior já está no fundo com certeza
	// então basta verificar se o primeiro é maior que o segundo; se for, trocamos (sa)
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
}

// varre a lista toda e devolve a posição do maior número
int	find_max_index(t_node *stack)
{
	int		max_index;
	int		current_index;
	t_node	*max_node;

	// se a lista não existir, devolve -1 (erro/vazio)
	if (!stack)
		return (-1); 
		
	// usar esta função do arquivo 01_utils_math.c para descobrir qual é o maior nó
	max_node = find_max_node(stack);
	
	current_index = 0;
	max_index = 0;
	
	// varre a lista para descobrir em qual posição esse nó tá
	while (stack)
	{
		// quando o nó atual estiver no mesmo endereço do maior nó, achamos o índice
		if (stack == max_node)
		{
			max_index = current_index; 
			break ; // como já achamos o índice, podemos quebrar o loop
		}
		current_index++;
		stack = stack->next;
	}
	// devolve a posição exata pra matemática do sort_medium funcionar
	return (max_index);
}