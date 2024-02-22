/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-omra <hel-omra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 01:47:51 by hel-omra          #+#    #+#             */
/*   Updated: 2024/02/20 23:41:46 by hel-omra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	rra(t_stack **a, int flag)
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
	if (flag == 0)
		write (1, "rra\n", 4);
}

void	rrb(t_stack **b, int flag)
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
	if (flag == 0)
		write (1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a, 1);
	rrb(b, 1);
	write (1, "rrr\n", 4);
}
