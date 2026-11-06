#include "push_swap.h"

int	safe_atoi(char *str, int *result)
{
	long	n;
	int		i;
	int		sign;

	n = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str[i] < '0' || str[i] > '9')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = (n * 10) + (str[i] - '0');
		if (sign == 1 && n > 2147483647)
			return (0);
		if (sign == -1 && (-n) < -2147483648)
			return (0);
		i++;
	}
	if (str[i] != '\0')
		return (0);
	*result = n * sign;
	return (1);
}

int	duplicate(t_stack *stack, int number)
{
	t_node	*tmp;

	tmp = stack->head;
	while (tmp)
	{
		if (tmp->data == number)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
