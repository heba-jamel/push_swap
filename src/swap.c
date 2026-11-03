#include "push_swap.h"

static void	swap(t_node *head)
{
    int temp;

    temp = head -> data;
    head->data = head -> next->data;
    head -> next -> data = temp;
}

void    sa(t_stck *stackA)
{
    if (!stackA || !(stackA->head) || !(stackA->head->next))
    return ;

    swap(stackA->head);
}

void    sb(t_stck *stackB)
{
    if (!stackB || !(stackB->head) || !(stackB->head->next))
    return ;

    swap(stackB->head);   
}

void    ss(t_stck *stackA,t_stck *stackB)
{
    sa(stackA);
    sb(stackB);
}