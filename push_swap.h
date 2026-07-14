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
t_node	*find_min_node(t_node *stack);
t_node	*find_max_node(t_node *stack);

t_node	*create_node(int value);
t_node	*get_last_node(t_node *stack);
void add_node_back(t_node **stack, t_node *new_node);
int	is_numeric(char *str);
int	is_within_int_limits(long number);
int	has_duplicates(t_node *stack_a);
int	check_args(int argc, char **argv);
int	get_stack_size(t_node *stack);
void	free_stack(t_node **stack);
t_node	*init_stack_a(int argc, char **argv);
int	operation_swap(t_node **stack);
int operation_push(t_node **stack_a, t_node **stack_b);
int     pa(t_node **stack_a, t_node **stack_b);
int     pb(t_node **stack_a, t_node **stack_b);
int     sa(t_node **stack_a);
int     sb(t_node **stack_b);
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);
void	rra(t_node **stack_a);
void	rrb(t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);
static void	reverse_rotate(t_node **stack);
float   compute_disorder(t_node **stack);

int	find_min_index(t_node *stack);
void sort_three(t_node **stack_a);
int	find_max_index(t_node *stack);

void sort_simple(t_node **stack_a, t_node **stack_b);

void	sort_medium(t_node **stack_a, t_node **stack_b);

int complex_radix_lsd(t_node **stack_a, t_node **stack_b);

void stack_debug(t_node *stack); // remover mais tarde
