#include <stdlib.h>
#include <limits.h>
#include <stdio.h> // substituir por ft_printf

typedef struct s_node {
    int             value;
    int             cost;
    int             is_cheapest;
    struct s_node   *next;
} t_node;

long	ft_atol(const char *str);
t_node	*create_node(int value);
t_node	*get_last_node(t_node *stack);
void add_node_back(t_node **stack, t_node *new_node);
int	is_numeric(char *str);
int	is_within_int_limits(long number);
int	has_duplicates(t_node *stack_a);
int	check_args(int argc, char **argv);
void	free_stack(t_node **stack);
t_node	*init_stack_a(int argc, char **argv);
t_node  *operation_swap(t_node *stack);
t_node *operation_pa(t_node *stack_a, t_node *stack_b);