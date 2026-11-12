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
<<<<<<< HEAD:src/push_swap.h
# include <limts.h>
=======
# include <limits.h>

typedef enum e_strategy
{
	ADAPTIVE,
	SIMPLE,
	MEDIUM,
	COMPLEX
}	t_strategy;
>>>>>>> loai-work:push_swap/push_swap.h

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
	int		size;

}	t_stack;

typedef struct s_config
{
	t_strategy	strategy;
	int			bench;
	int			numbers_start;
}	t_config;

t_node	*create_node(int data);
t_stack	*create_stack(void);
void	push(t_stack *stack, t_node *node);
t_node	*pop(t_stack *stack);
void	free_stack(t_stack *stack);
char	**ft_split(char const *s, char c);
int		parse_argument(char *arg, t_stack *stack);
int		add_number(t_stack *stack, char *str);
t_stack	*parsing(int argc, char **argv);

#endif
