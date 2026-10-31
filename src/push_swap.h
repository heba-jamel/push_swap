/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halomari <halomari@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 16:00:06 by halomari          #+#    #+#             */
/*   Updated: 2026/10/29 16:42:37 by halomari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

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
}	t_stck;

#endif
