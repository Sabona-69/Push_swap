/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-omra <hel-omra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 01:47:51 by hel-omra          #+#    #+#             */
/*   Updated: 2024/02/22 02:07:02 by hel-omra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker.h"

void	rra(t_stack **a)
{
	t_stack	*bef_last;
	t_stack	*last;

	if (!(*a) || !(*a)->next)
		return ;
	bef_last = *a;
	while (bef_last->next->next)
		bef_last = bef_last->next;
	last = bef_last->next;
	bef_last->next = NULL;
	ft_lstadd_front(a, last);
}

void	rrb(t_stack **b)
{
	t_stack	*bef_last;
	t_stack	*last;

	if (!(*b) || !(*b)->next)
		return ;
	bef_last = *b;
	while (bef_last->next->next)
		bef_last = bef_last->next;
	last = bef_last->next;
	bef_last->next = NULL;
	ft_lstadd_front(b, last);
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
}
