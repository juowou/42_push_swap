#include "push_swap.h"

long	ft_atol(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	// pula espaços em branco ou caracteres de controle 
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	// verifica o sinal
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	// constrói o número long
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	return (result * sign);
}

// analisa a pilha e devolve um ponteiro para o nó com o menor número
t_node	*find_min_node(t_node *stack)
{
	t_node	*min_node;

	if (!stack)
		return (NULL);
	// assumir que o primeiro nó é o menor até que se prove o contrário
	min_node = stack;
	while (stack)
	{
		// se achar um número menor que o salvo, atualiza o ponteiro
		if (stack->value < min_node->value)
			min_node = stack;
		// vai pro próximo nó
		stack = stack->next;
	}
	// não move o número, só avisa onde ele tá
	return (min_node);
}

// procura e devolve o ponteiro para o nó que contém o valor mais alto
t_node	*find_max_node(t_node *stack)
{
	t_node	*max_node;

	if (!stack)
		return (NULL);
	// assumir que o primeiro nó é o maior de início
	max_node = stack;
	while (stack)
	{
		// se achar um número maior que o salvo, atualiza o ponteiro
		if (stack->value > max_node->value)
			max_node = stack;
		stack = stack->next;
	}
	return (max_node);
}