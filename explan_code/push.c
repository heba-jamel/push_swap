#include "push_swap.h"

void	push(t_stack *src, t_stack *dest)
{
	t_node	*temp;

	/* Do nothing if a stack is missing or the source is empty. */
	if (!src || !dest || !src->head)
		return ;

	/* Keep the source's top node so we can move it. */
	temp = src->head;

	/* Remove it from the source stack. */
	src->head = temp->next;
	if (src->head)
		src->head->prev = NULL;
	else
		src->last = NULL; /* The source is now empty. */

	/* Put the moved node at the top of the destination stack. */
	temp->prev = NULL;
	temp->next = dest->head;
	if (dest->head)
		dest->head->prev = temp;
	else
		dest->last = temp; /* The destination was empty. */

	dest->head = temp; /* Update the destination's top node. */
}

void	pa(t_stack *a, t_stack *b)
{
	push(b, a); /* Move the top node from b to a. */
}

void	pb(t_stack *a, t_stack *b)
{
	push(a, b); /* Move the top node from a to b. */
}
