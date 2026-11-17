/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halomari <halomari@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 19:21:44 by halomari          #+#    #+#             */
/*   Updated: 2026/11/17 14:31:27 by halomari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

float	calculate_disorder(t_stack *stack)
{
	t_node	*j;
	t_node	*i;
	int		mistakes;
	int		total_pairs;

	if (!stack || !stack->head || !stack->head->next)
		return (0.0);
	mistakes = 0;
	total_pairs = 0;
	i = stack->head;
	j = stack->head->next;
	while (i)
	{
		while (j)
		{
			if (i->data > j->data)
				mistakes++;
			total_pairs++;
			j = j->next;
		}
		i = i->next;
		if (i)
			j = i->next;
	}
	return ((float)mistakes / total_pairs);
}
