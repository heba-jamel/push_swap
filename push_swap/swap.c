/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halomari <halomari@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 18:36:01 by halomari          #+#    #+#             */
/*   Updated: 2026/11/04 20:23:24 by halomari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_node *head)
{
	int	temp;

	temp = head->data;
	head->data = head->next->data;
	head->next->data = temp;
}

void	sa(t_stack *stackA)
{
	if (!stackA || !stackA->head || !stackA->head->next)
		return ;
	swap(stackA->head);
}

void	sb(t_stack *stackB)
{
	if (!stackB || !stackB->head || !stackB->head->next)
		return ;
	swap(stackB->head);
}

void	ss(t_stack *stackA, t_stack *stackB)
{
	sa(stackA);
	sb(stackB);
}
