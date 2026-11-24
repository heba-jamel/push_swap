/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halomari <halomari@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 19:10:12 by halomari          #+#    #+#             */
/*   Updated: 2026/11/21 13:42:42 by halomari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_node(t_stack *src, t_stack *dest)
{
	t_node	*temp;

	if (!src || !dest || !src->head)
		return ;
	temp = pop(src);
	if (temp)
		push(dest, temp);
}

void	pa(t_stack *a, t_stack *b)
{
	move_node(b, a);
}

void	pb(t_stack *a, t_stack *b)
{
	move_node(a, b);
}
