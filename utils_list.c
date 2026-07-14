#include "push_swap.h"

t_node	*create_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
    // cost e is_cheapest serão usados mais à frente para as rotações, já add logo pra não esquecer rs
	node->cost = 0;
	node->is_cheapest = 0;
	node->next = NULL;
	return (node);
}


t_node	*get_last_node(t_node *stack)
{
	if (!stack)
		return (NULL);
	// enquanto o nó atual apontar para um próximo nó, seguimos
	while (stack->next)
		stack = stack->next;
	// quando o loop quebrar significa o próximo é NULL, i.e. chegamos no último nó
	return (stack);
}


void add_node_back(t_node **stack, t_node *new_node)
{
	t_node	*last_node;

	if (!stack || !new_node)
		return ;	
	// se a lista estiver vazia, o novo nó se torna a cabeça da lista
	if (*stack == NULL)
		*stack = new_node;
	else
	{
		// encontramos o último nó passando a cabeça da lista (*stack)
		last_node = get_last_node(*stack);
		// faz o "next" do último nó apontar para o novo nó que chegou
		last_node->next = new_node;
	}
}

// conta quantos nós existem na stack
int	get_stack_size(t_node *stack)
{
	int	size;

	size = 0;
	// percorre a lista até o final (quando o ponteiro for NULL)
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	// devolve o tamanho total da stack
	return (size);
}