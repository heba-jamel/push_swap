#include "push_swap.h"

void	push(t_stack *src, t_stack *dest)
{
	t_node	*temp;

	/* Nothing to move if a stack is missing or the source is empty. */
	if (!src || !dest || !src->head)
		return ;

	/* Save the source's top node. */
	temp = src->head;

	/* Remove it from the source stack. */
	src->head = temp->next;
	if (src->head)
		src->head->prev = NULL;
	else
		src->last = NULL; /* Source is now empty. */

	/* Place the moved node at the top of the destination. */
	temp->prev = NULL;
	temp->next = dest->head;
	if (dest->head)
		dest->head->prev = temp;
	else
		dest->last = temp; /* Destination was empty. */

	dest->head = temp; /* The moved node is now the destination's top. */
}

void	pa(t_stack *a, t_stack *b)
{
	push(b, a); /* Move the top node from b to a. */
}

void	pb(t_stack *a, t_stack *b)
{
	push(a, b); /* Move the top node from a to b. */
}
