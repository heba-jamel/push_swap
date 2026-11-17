/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labu-mus <labu-mus@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 18:42:46 by labu-mus          #+#    #+#             */
/*   Updated: 2026/11/10 18:42:48 by labu-mus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	result = 0;
	sign = 1;
	while ((nptr[i] == ' ') || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = (result * 10) + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}

static int	duplicate(t_stack *stack, int number)
{
	t_node	*tmp;

	if (!stack)
		return (0);
	tmp = stack->head;
	while (tmp)
	{
		if (tmp->data == number)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	add_number(t_stack *stack, char *str)
{
	t_node	*node;
	int		number;

	number = ft_atoi(str);
	if (duplicate(stack, number))
		return (0);
	node = create_node(number);
	if (!node)
		return (0);
	push(stack, node);
	return (1);
}

t_stack	*parsing(int argc, char **argv)
{
	t_stack	*stack;
	int		i;

	i = 1;
	stack = create_stack();
	if (!stack)
		return (NULL);
	while (i < argc)
	{
		if (!parse_argument(argv[i], stack))
			return (free_stack(stack), NULL);
		i++;
	}
	return (stack);
}
