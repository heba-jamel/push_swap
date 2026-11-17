/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labu-mus <labu-mus@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 18:42:00 by labu-mus          #+#    #+#             */
/*   Updated: 2026/11/10 18:42:03 by labu-mus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_number(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] < '0' || str[i] > '9')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}

static int	range_number(char *str)
{
	long	number;
	int		sign;

	number = 0;
	sign = 1;
	if (!str)
		return (0);
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		number = (number * 10) + (*str - '0');
		if (sign == 1 && number > INT_MAX)
			return (0);
		if (sign == -1 && (-number) < INT_MIN)
			return (0);
		str++;
	}
	if (*str != '\0')
		return (0);
	return (1);
}

static int	empty_input(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] == ' ')  // "" "      "
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

static void	free_split(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	parse_argument(char *str, t_stack *stack)
{
	char	**split;
	int		i;

	if (!str || !stack)
		return (0);
	i = 0;
	if (empty_input(str))
		return (0);
	split = ft_split(str, ' ');
	if (!split)
		return (0);
	while (split[i])
	{
		if (!is_valid_number(split[i]) || !range_number(split[i]))
			return (free_split(split), 0);
		if (!add_number(stack, split[i]))
			return (free_split(split), 0);
		i++;
	}
	free_split(split);
	return (1);
}
