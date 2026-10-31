#include "push_swap.h"

void	reverse_rotate(t_stck *stack)
{
	t_node	*tmp;

	// STEP 1:
	// Check if the stack pointer is NULL.
	// Check if the stack is empty.
	// Check if the stack contains only one node.
	// If any condition is true, stop the function.
	if (!stack || !stack->last || !stack->last->prev)
		return ;

	// STEP 2:
	// Save the address of the last node inside tmp.
	// tmp now points to node 15.
	//
	// HEAD                         LAST
	//  ↓                            ↓
	// [5]  ⇄  [10]  ⇄  [15]
	//                       ↑
	//                      tmp
	tmp = stack->last;

	// STEP 3:
	// Move the last pointer one node backwards.
	// last now points to node 10 instead of node 15.
	//
	// HEAD              LAST
	//  ↓                  ↓
	// [5]  ⇄  [10]  ⇄  [15]
	//                  ↑
	//                 tmp
	stack->last = stack->last->prev;

	// STEP 4:
	// Set the next pointer of node 10 to NULL.
	// Node 10 becomes the new last node.
	//
	// HEAD              LAST
	//  ↓                  ↓
	// [5]  ⇄  [10]       [15]
	//          next = NULL
	//                   ↑
	//                  tmp
	stack->last->next = NULL;

	// STEP 5:
	// Connect the old last node (15) to the old head (5).
	// tmp->next now points to node 5.
	//
	// [15] ─────next────→ [5] ⇄ [10]
	//   ↑                   ↑
	//  tmp                 head
	tmp->next = stack->head;

	// STEP 6:
	// Connect node 5 backwards to node 15.
	// This creates the connection in both directions.
	//
	// [15] ⇄ [5] ⇄ [10]
	//   ↑      ↑      ↑
	//  tmp    prev   last
	stack->head->prev = tmp;

	// STEP 7:
	// Set the previous pointer of node 15 to NULL.
	// Node 15 will become the first node.
	//
	// [15] ⇄ [5] ⇄ [10]
	//  prev = NULL
	tmp->prev = NULL;

	// STEP 8:
	// Update the head pointer.
	// The head now points to node 15.
	//
	// HEAD              LAST
	//  ↓                  ↓
	// [15]  ⇄  [5]  ⇄  [10]
	stack->head = tmp;
}


void	rra(t_stck *a)
{
	// Reverse rotate Stack A.
	reverse_rotate(a);
}

void	rrb(t_stck *b)
{
	// Reverse rotate Stack B.
	reverse_rotate(b);
}

void	rrr(t_stck *a, t_stck *b)
{
	// Reverse rotate Stack A.
	reverse_rotate(a);

	// Reverse rotate Stack B.
}
