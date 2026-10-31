/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labu-mus <labu-mus@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 17:41:16 by labu-mus          #+#    #+#             */
/*   Updated: 2026/10/31 17:41:20 by labu-mus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stck *stack)
{
	t_node	*tmp;

	if (!stack || !stack-> head || !stack -> head -> next)
		return ;
	tmp = stack->head;
	stack -> head = stack->head->next;
	stack -> head -> prev = NULL;
	stack -> last -> next = tmp;
	tmp -> prev = stack -> last;
	tmp -> next = NULL;
	stack -> last = tmp;
}

void	ra(t_stck *a)
{
	rotate(a);
}

void	rb(t_stck *b)
{
	rotate(b);
}

void	rr(t_stck *a, t_stck *b)
{
	rotate(a);
	rotate(b);
}
