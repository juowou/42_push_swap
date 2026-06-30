#include "push_swap.h"

long	ft_atol(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	// Pula espaços em branco ou caracteres de controle
	//	L> não vão existir espaços em branco ou caracteres de
	//		controle por causa da verificação do is_numeric(),
	//		logo este while() não vai ser utilizado
	//while (*str == ' ' || (*str >= 9 && *str <= 13))
	//	str++;
	// Verifica o sinal
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	// Constrói o número long
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	return (result * sign);
}