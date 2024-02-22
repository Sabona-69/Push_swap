/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-omra <hel-omra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 01:47:31 by hel-omra          #+#    #+#             */
/*   Updated: 2024/02/22 05:42:05 by hel-omra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker.h"

void	ra(t_stack **a)
{
	t_stack	*tmp;

	if (!(*a) || !(*a)->next)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp ->next = NULL;
	ft_lstadd_back (a, tmp);
}

void	rb(t_stack **b)
{
	t_stack	*tmp;

	if (!(*b) || !(*b)->next)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = NULL;
	ft_lstadd_back(b, tmp);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = NULL;
	if (!(*b))
		return ;
	tmp = *b;
	*b = tmp->next;
	ft_lstadd_front(a, tmp);
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!(*a))
		return ;
	tmp = *a;
	*a = tmp->next;
	ft_lstadd_front(b, tmp);
}
