#include <stdlib.h>
#include <limits.h>
#include <stdio.h> // substituir por ft_printf

typedef struct s_node {
    int             value;
    int             cost;
    int             is_cheapest;
    struct s_node   *previous;
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
int	operation_swap(t_node *stack);
int operation_push(t_node **stack_a, t_node **stack_b);
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);
static void	reverse_rotate(t_node **stack);
float   compute_disorder(t_node **stack);
int complex_radix_lsd(t_node **stack_a);

void stack_debug(t_node *stack); // remover mais tarde
