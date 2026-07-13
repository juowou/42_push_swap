#include "push_swap.h"
#include <limits.h>

int	is_numeric(char *str)
{
	int	i;

	i = 0;

	if (!str)
		return (0);
	// aceita sinal de '+' ou '-' só no início do número
	if (str[i] == '+' || str[i] == '-')
		i++;
	// se a string for só um sinal não é um número
	if (str[i] == '\0')
		return (0);
	// verifica se todos os caracteres são números
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0); // se encontrar uma letra ou símbolo no meio
		i++;
	}
	// se passou em tudo é um número válido/retorna verdadeiro
	return (1);
}

int	is_within_int_limits(long number)
{
	if (number < INT_MIN || number > INT_MAX)
		return (0); // está fora dos limites
	return (1); // é um int válido
}


int	has_duplicates(t_node *stack_a)
{
	t_node	*current;
	t_node	*runner;

	// current aponta para o nó que estamos testando agora
	current = stack_a;
	while (current)
	{
		// runner começa sempre um passo à frente do current
		runner = current->next;
		while (runner)
		{
			// se o nó atual for igual ao do runner, achamos um clone
			if (current->value == runner->value)
				return (1);
			runner = runner->next;
		}
		// movemos o current para testar o próximo nó
		current = current->next;
	}
	// se os loops terminarem sem encontrar clones, a lista está limpa
	return (0);
}


int	check_args(int argc, char **argv)
{
	int		i;
	long	num;

	i = 1;
	// se chamou o programa sem argumentos, só ignora
	if (argc < 2)
		return (0);	
	// varre todos os argumentos (começando do 1, pois argv[0] é "./push_swap")
	while (i < argc)
	{
		// verifica se a string só tem números/sinais válidos
		if (!is_numeric(argv[i]))
			return (0);
		// converte para long e verifica os limites de INT
		num = ft_atol(argv[i]);
		if (!is_within_int_limits(num))
			return (0);		
		i++;
	}	
	// se passou tudo sem retornar 0, os argumentos estão ok
	return (1);
}