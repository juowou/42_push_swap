#include "push_swap.h"
#include <stdlib.h> 

// eliminar stack
void	free_stack(t_node **stack)
{
	t_node	*current;
	t_node	*next_node;

	// se não tiver endereço nenhum, ou se a lista já está vazia, não faz nada
	if (!stack || !*stack)
		return ;
	// current (atual) começa apontando para o primeiro nó da lista
	current = *stack;

	while (current != NULL)
	{
		// salva o endereço do próximo nó antes de destruir o atual
		next_node = current->next;
		// destrói o nó atual, liberando a memória
		free(current);
		// pula pro próximo nó que nós salvamos antes
		current = next_node;
	}
	// depois do delete, a lista agora é NULL
	*stack = NULL;
}

// gerar stack a partir de argumentos
t_node	*init_stack_a(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*new_node;
	t_node	*previous_node;
	long	num;
	int		i;
	int		is_first;

	if (check_args(argc, argv) == 0) // verificar argumentos
		return (NULL);
	stack_a = NULL;
	i = 1;
	is_first = 1;
	while (i < argc)
	{
		num = ft_atol(argv[i]); // converte a string
		new_node = create_node((int)num); // cria o nó 
		
		if (!new_node) // se o malloc falhar no meio do caminho
		{
			free_stack(&stack_a); // limpamos o que já foi criado para não vazar memória
			return (NULL);
		}
		if (is_first)
		{
			new_node->previous = NULL;
			previous_node = new_node;
			is_first = 0;
		}
		else
		{
			new_node->previous = previous_node;
			previous_node = stack_a;
		}
		add_node_back(&stack_a, new_node); // anexa o nó na lista

		i++;
	}
	// agora só verificamos se existem números repetidos
	if (has_duplicates(stack_a))
	{
		free_stack(&stack_a);
		return (NULL);
	}
	return (stack_a);
}