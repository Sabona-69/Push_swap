/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-omra <hel-omra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:27:02 by hel-omra          #+#    #+#             */
/*   Updated: 2024/02/22 02:07:21 by hel-omra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker.h"

void	swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

void	sa(t_stack **a)
{
	if (!(*a) || !(*a)->next)
		return ;
	swap(&(*a)->content, &(*a)->next->content);
	swap(&(*a)->index, &(*a)->next->index);
}

void	sb(t_stack **b)
{
	if (!(*b) || !(*b)->next)
		return ;
	swap(&(*b)->content, &(*b)->next->content);
	swap(&(*b)->index, &(*b)->next->index);
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
}
