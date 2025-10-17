/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-cad <jose-cad@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 09:54:11 by jose-cad          #+#    #+#             */
/*   Updated: 2025/10/08 09:54:13 by jose-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_reverse_rotate(t_stack *stack)
{
	t_node	*temp;

	if (!stack || !stack->top || stack->size < 2)
		return ;
	temp = stack->bottom;
	stack->bottom = stack->bottom->prev;
	stack->bottom->next = NULL;
	temp->prev = NULL;
	temp->next = stack->top;
	stack->top->prev = temp;
	stack->top = temp;
}

void	rra(t_stack *a)
{
	ft_reverse_rotate(a);
	write(1, "rra\n", 3);
}

void	rrb(t_stack *b)
{
	ft_reverse_rotate(b);
	write(1, "rrb\n", 3);
}

void	rrr(t_stack *a, t_stack *b)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	write(1, "rrr\n", 3);
}
