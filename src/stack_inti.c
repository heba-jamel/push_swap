/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_inti.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halomari <halomari@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 11:21:48 by halomari          #+#    #+#             */
/*   Updated: 2026/11/05 13:32:50 by halomari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(int data)
{
	t_node	*node;

	node = malloc (sizeof (t_node));
	if (!node)
		return (NULL);
	node->prev = NULL;
	node->next = NULL;
	node->data = data;
	return (node);
}

void    push_node(t_stack *stack, t_node *node)
{
	if (!stack || !node)
		return ;
	node->next = stack->head;
	if (! node->next)
		stack->last = node;
	else
		stack->head->prev = node;
	stack->head = node;
	stack->head->prev = NULL;
}

t_node  *pop_node(t_stack *stack)
{
    t_node  *temp;

    if (!stack || !stack->head)
        return (NULL);
    temp = stack->head;
    stack->head = temp->next;
    if (stack->head)
        stack->head->prev = NULL;
    else
        stack->last = NULL;
    temp->prev = NULL;
    temp->next = NULL;
    return (temp);
}
