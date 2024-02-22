/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-omra <hel-omra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:27:02 by hel-omra          #+#    #+#             */
/*   Updated: 2024/02/20 23:41:34 by hel-omra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

void	sa(t_stack **a, int flag)
{
	if (!(*a) || !(*a)->next)
		return ;
	swap(&(*a)->content, &(*a)->next->content);
	swap(&(*a)->index, &(*a)->next->index);
	if (flag == 0)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, int flag)
{
	if (!(*b) || !(*b)->next)
		return ;
	swap(&(*b)->content, &(*b)->next->content);
	swap(&(*b)->index, &(*b)->next->index);
	if (flag == 0)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a, 1);
	sb(b, 1);
	write(1, "ss\n", 3);
}
