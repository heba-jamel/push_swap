/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labu-mus <labu-mus@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 18:51:26 by labu-mus          #+#    #+#             */
/*   Updated: 2026/10/31 18:51:26 by labu-mus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stck *stack)
{
	t_node	*tmp;

	if (!stack || !stack -> last || !stack -> last -> prev)
		return ;
	tmp = stack -> last;
	stack -> last = stack -> last -> prev;
	stack -> last -> next = NULL;
	tmp -> next = stack -> head;
	stack -> head -> prev = tmp;
	tmp -> prev = NULL;
	stack -> head = tmp;
}

void	rra(t_stck *a)
{
	reverse_rotate(a);
}

void	rrb(t_stck *b)
{
	reverse_rotate(b);
}

void	rrr(t_stck *a, t_stck *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
