/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halomari <halomari@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 16:00:06 by halomari          #+#    #+#             */
/*   Updated: 2026/11/05 19:15:23 by halomari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limts.h>

typedef struct s_node
{
	struct s_node	*prev;
	struct s_node	*next;
	int				data;
}	t_node;

typedef struct s_stck
{
	t_node	*head;
	t_node	*last;
}	t_stack;

void    sa(t_stack *stackA);
void    sb(t_stack *stackB);
void    ss(t_stack *stackA,t_stack *stackB);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
#endif
