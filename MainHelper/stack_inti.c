/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_inti.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halomari <halomari@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 11:21:48 by halomari          #+#    #+#             */
/*   Updated: 2026/11/05 18:57:15 by halomari         ###   ########.fr       */
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

t_stack *stack_init(int *numbers, int size)
{
	t_stack	*stack;
	t_node	*add;
	int 	i;
	int	j;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->head = NULL;
	stack->last = NULL;
	j = size -1;
	i = 0;
	while (i < size)
	{
		add = new_node(numbers[j]);
		if (!add)
		{
			free_stack(stack);
			return (NULL);
		}
		push_node(stack, add);
		i++;
		j--;
	}
	return (stack);
}

void	free_stack(t_stack *stack)
{
	t_node	*temp;

	if (!stack)
		return ;
	while(stack->head)
	{
		temp = stack->head;
		stack->head = temp->next;
		free(temp);
	}
	free(stack);
}
