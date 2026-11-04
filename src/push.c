/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halomari <halomari@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 19:10:12 by halomari          #+#    #+#             */
/*   Updated: 2026/11/04 19:10:18 by halomari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack *src, t_stack *dest)
{
	t_node	*temp;

	if (!src || !dest || !src->head)
		return ;
	temp = src->head;
	src->head = temp->next;
	if (src->head)
		src->head->prev = NULL;
	else
		src->last = NULL;
	temp->prev = NULL;
	temp->next = dest->head;
	if (dest->head)
		dest->head->prev = temp;
	else
		dest->last = temp;
	dest->head = temp;
}

void	pa(t_stack *a, t_stack *b)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	push(a, b);
	write(1, "pb\n", 3);
}
