/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alg_cost.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-cad <jose-cad@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 09:53:12 by jose-cad          #+#    #+#             */
/*   Updated: 2025/10/08 09:53:15 by jose-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_init_nodes_a(t_stack *a, t_stack *b)
{
	ft_current_index(a);
	ft_current_index(b);
	ft_set_target_a(a, b);
	ft_cost_analysis_a(a, b);
	ft_set_cheapest(b);
}

void	ft_init_nodes_b(t_stack *a, t_stack *b)
{
	ft_current_index(a);
	ft_current_index(b);
	ft_set_target_b(a, b);
	ft_cost_analysis_b(a, b);
	ft_set_cheapest(a);
}
