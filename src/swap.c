/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halomari <halomari@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 18:36:01 by halomari          #+#    #+#             */
/*   Updated: 2026/11/04 19:56:33 by halomari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	swap(t_node *head)
{
	int	temp;

	temp = head->data;
	head->data = head->next->data;
	head->next->data = temp;
}

void	sa(t_stack *stackA)
{

}

void	sb(t_stack *stackB)
{
	if (!stackB || !stackB->head || !stackB->head->next)
		return ;
	swap(stackB->head);
	write(1, "sb\n", 3);
}

void	ss(t_stack *stackA, t_stack *stackB)
{
	sa(stackA);
	sb(stackB);
	write(1, "ss\n", 3);
}
