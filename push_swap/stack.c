/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labu-mus <labu-mus@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 17:42:22 by labu-mus          #+#    #+#             */
/*   Updated: 2026/11/06 17:42:27 by labu-mus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int data)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->prev = NULL;
	new_node->next = NULL;
	new_node->data = data;
	return (new_node);
}

t_stack	*create_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->head = NULL;
	stack->last = NULL;
	stack->size = 0;
	return (stack);
}

void	push(t_stack *stack, t_node *node)
{
	if (!stack || !node)
		return ;
	node->next = stack->head;
	if (!node->next)
		stack->last = node;
	else
		stack->head->prev = node;
	stack->head = node;
	stack->head->prev = NULL;
	stack->size += 1;
}

t_node	*pop(t_stack *stack)
{
	t_node	*temp;

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
	stack->size -= 1;
	return (temp);
}

void	free_stack(t_stack *stack)
{
	t_node	*temp;

	if (!stack)
		return ;
	while (stack->head)
	{
		temp = stack->head;
		stack->head = temp->next;
		free(temp);
	}
	stack->size = 0;
	stack->last = NULL;//dangling pointer 
	free(stack);
}
