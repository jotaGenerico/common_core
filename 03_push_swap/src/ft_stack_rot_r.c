/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_rot_r.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-cad <jose-cad@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 09:54:42 by jose-cad          #+#    #+#             */
/*   Updated: 2025/10/08 09:54:44 by jose-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	rr(t_stack *a, t_stack *b, int print)
{
	ra(a, 0);
	rb(b, 0);
	if (print)
		write(1, "rr\n", 3);
}

void	rrr(t_stack *a, t_stack *b, int print)
{
	rra(a, 0);
	rrb(b, 0);
	if (print)
		write(1, "rrr\n", 4);
}

void	ft_rotate_both(t_stack *a, t_stack *b, t_node *cheapest_a,
		t_node *cheapest_b)
{
	while (a->top != cheapest_a && b->top != cheapest_b
		&& cheapest_a->above_median && cheapest_b->above_median)
		rr(a, b, 1);
	while (a->top != cheapest_a && b->top != cheapest_b
		&& !(cheapest_a->above_median) && !(cheapest_b->above_median))
		rrr(a, b, 1);
}
