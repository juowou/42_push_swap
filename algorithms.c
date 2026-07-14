#include "push_swap.h"

// algoritmo da classe O(n^2) (para 5 números ou menos)
void sort_simple(t_node **stack_a, t_node **stack_b)
{
	int	size;
	int	min_idx;

	size = get_stack_size(*stack_a);
	
	// empurramos os menores números para a stack B até sobrarem só 3 números na stack A
	while (size > 3)
	{
		min_idx = find_min_index(*stack_a);

		// Se o menor tá na metade de cima ou no meio, roda pra cima (ra)
		if (min_idx <= size / 2)
		{
			while (min_idx > 0)
			{
				ra(stack_a);
				min_idx--;
			}
		}
		// se tá na metade de baixo, roda pra baixo (rra)
		else
		{
			while (min_idx < size)
			{
				rra(stack_a);
				min_idx++;
			}
		}
		// agora o menor número está no topo com certeza
		// daí é empurrar ele pra stack B e atualizar o tamanho da stack A
		pb(stack_a, stack_b);
		size--;
	}
	
	// com só 3 números na stack A, chamar a função base
	sort_three(stack_a);
	
	// no fim, a stack B tem os menores números (em ordem decrescente)
	// daí é devolver todos para a Pilha A (que tem os 3 maiores)
	while (*stack_b)
		pa(stack_a, stack_b);
}

// HELPER ESTÁTICO: média matemática da pilha
static long	get_average(t_node *stack)
{
	long	sum;
	int		count;

	sum = 0;
	count = 0;
	// varre a lista do começo ao fim
	while (stack)
	{
		sum += stack->value; // soma o valor de todos os nós
		count++;             // conta quantos nós existem
		stack = stack->next;
	}
	// proteção contra divisão por zero (caso a lista chegue vazia aqui)
	if (count == 0)
		return (0);
	// devolve a média exata (soma total dividida pela quantidade)
	return (sum / count);
}

// HELPER ESTÁTICO: empurra pra B baseado na média
static void	push_to_b_by_average(t_node **stack_a, t_node **stack_b)
{
	int		size;
	long	average;

	// descobre quantos números há na stack A no total
	size = get_stack_size(*stack_a);
	
	// continua dividindo e empurrando até sobrar apenas os 3 maiores
	while (size > 3)
	{
		// calcula a média atual dos números que ainda estão na stack A
		average = get_average(*stack_a);
		
		// se o número no topo for menor ou igual à média, é "pequeno"
		if ((*stack_a)->value <= average)
		{
			pb(stack_a, stack_b); // joga para a stack B
			size--;               // registra que a stack A ficou menor
		}
		// se o número for maior que a média, é "grande" (e deve ficar na A)
		else
		{
			ra(stack_a);          // roda para o fundo para testar o próximo
		}
	}
}

// HELPER ESTÁTICO: devolve pra A achando o maior
static void	return_to_a(t_node **stack_a, t_node **stack_b)
{
	int	max_idx;
	int	b_size;

	// enquanto a stack B tiver qualquer número dentro dela
	while (*stack_b)
	{
		// descobre onde (qual posição/índice) está o maior número de todos
		max_idx = find_max_index(*stack_b);
		b_size = get_stack_size(*stack_b);
		
		// se o maior número está na metade de cima (ou meio)
		if (max_idx <= b_size / 2)
		{
			// roda para cima (rb) até o número chegar no topo (índice 0)
			while (max_idx-- > 0)
				rb(stack_b);
		}
		// se o maior número está na metade de baixo
		else
		{
			// roda por baixo (rrb) até ele subir direto para o topo
			while (max_idx++ < b_size)
				rrb(stack_b);
		}
		// agora que o maior número da B está no topo, devolvemos ele pra A
		pa(stack_a, stack_b);
	}
}

// FUNÇÃO PRINCIPAL
void	sort_medium(t_node **stack_a, t_node **stack_b)
{
	// não faz nada se a lista for nula
	if (!stack_a || !*stack_a)
		return ;
		
	stack_debug((*stack_a));
	stack_debug((*stack_b));
	// joga tudo que for abaixo da média pra B (várias vezes)
	push_to_b_by_average(stack_a, stack_b);
	
	stack_debug((*stack_a));
	stack_debug((*stack_b));
	// ordena os 3 maiores de todos que ficaram na A
	sort_three(stack_a);
	
	stack_debug((*stack_a));
	stack_debug((*stack_b));
	// traz todos de volta da stack B pra A, do maior pro menor
	return_to_a(stack_a, stack_b);

	stack_debug((*stack_a));
	stack_debug((*stack_b));
}