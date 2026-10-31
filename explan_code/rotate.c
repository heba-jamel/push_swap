#include "push_swap.h"

void	rotate(t_stck *stack)
{
	t_node	*tmp;

	// STEP 1:
	// Check if the stack pointer is NULL.
	// Check if the stack is empty.
	// Check if the stack contains only one node.
	// If any condition is true, stop the function.
	if (!stack || !stack->head || !stack->head->next)
		return ;

	// STEP 2:
	// Save the address of the first node inside tmp.
	// tmp now points to node 5.
	//
	// HEAD                         LAST
	//  ↓                            ↓
	// [5]  ⇄  [10]  ⇄  [15]
	//  ↑
	// tmp
	tmp = stack->head;

	// STEP 3:
	// Move the head pointer to the second node.
	// Head now points to node 10.
	//
	//        HEAD                  LAST
	//          ↓                    ↓
	// [5]     [10]  ⇄  [15]
	//  ↑
	// tmp
	stack->head = stack->head->next;

	// STEP 4:
	// Set the previous pointer of node 10 to NULL.
	// Node 10 becomes the first node.
	//
	// HEAD                  LAST
	//  ↓                     ↓
	// [10]  ⇄  [15]
	//  prev = NULL
	// [5]
	//  ↑
	// tmp
	stack->head->prev = NULL;

	// STEP 5:
	// Connect the old last node (15) to the old first node (5).
	// The last node now points forward to tmp.
	//
	// HEAD
	//  ↓
	// [10]  ⇄  [15] ─────→ [5]
	//          ↑            ↑
	//         last         tmp
	stack->last->next = tmp;

	// STEP 6:
	// Connect node 5 backwards to node 15.
	// This creates the reverse connection.
	//
	// [10]  ⇄  [15]  ⇄  [5]
	//          ↑         ↑
	//         last      tmp
	tmp->prev = stack->last;

	// STEP 7:
	// Set the next pointer of node 5 to NULL.
	// Node 5 becomes the last node.
	//
	// [10]  ⇄  [15]  ⇄  [5]
	//                     next = NULL
	tmp->next = NULL;

	// STEP 8:
	// Update the last pointer to point to node 5.
	// The stack now has a new last node.
	//
	// HEAD                  LAST
	//  ↓                     ↓
	// [10]  ⇄  [15]  ⇄  [5]
	stack->last = tmp;
}

void	ra(t_stck *a)
{
	// STEP 1:
	// Receive a pointer to Stack A.
	// The pointer allows us to modify the original stack.

	// STEP 2:
	// Call the main rotate function on Stack A.
	// The first node moves to the end.
	rotate(a);
}

void	rb(t_stck *b)
{
	// STEP 1:
	// Receive a pointer to Stack B.

	// STEP 2:
	// Call the main rotate function on Stack B.
	// The first node moves to the end.
	rotate(b);
}

void	rr(t_stck *a, t_stck *b)
{
	// STEP 1:
	// Receive pointers to Stack A and Stack B.

	// STEP 2:
	// Rotate Stack A.
	// Move its first node to the end.
	rotate(a);

	// STEP 3:
	// Rotate Stack B.
	// Move its first node to the end.
	rotate(b);
}
