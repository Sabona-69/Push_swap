/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-omra <hel-omra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:36:36 by hel-omra          #+#    #+#             */
/*   Updated: 2024/02/20 23:41:55 by hel-omra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sorting(t_stack **a, t_stack **b)
{
	if (is_sorted(*a) == 0)
		return ;
	else if (lst_size(a) == 2)
		sort_2(a);
	else if (lst_size(a) == 3)
		sort_3(a);
	else if (lst_size(a) == 4)
		sort_4(a, b);
	else if (lst_size(a) == 5)
		sort_5(a, b);
	else
		huge_sort(a, b);
}

int	if_index_top(t_stack **a, int index)
{
	t_stack	*cur;
	int		i;
	int		size;

	i = 0;
	size = lst_size(a) / 2;
	cur = *a;
	while (cur && i < size)
	{
		if (cur->index == index)
			return (1);
		cur = cur->next;
		i++;
	}
	return (0);
}

void	b_to_a(t_stack **a, t_stack	**b)
{
	int		max;

	max = lst_last(*a)->index;
	while (lst_size(b) > 0)
	{
		if (*b && (*b)->index == (*a)->index - 1)
			pa(a, b);
		else if (*b && (*a)->index - 1 == lst_last(*b)->index)
			(rrb(b, 0), pa(a, b));
		else if (lst_last(*a)->index == max)
			(pa(a, b), ra(a, 0));
		else if (*b && lst_last(*a)->index < (*b)->index)
			(pa(a, b), ra(a, 0));
		else if (*b && lst_last(*a)->index < lst_last(*b)->index)
			(rrb(b, 0), pa(a, b), ra(a, 0));
		else if (lst_last(*a)->index == ((*a)->index - 1))
			rra(a, 0);
		else if (*b && if_index_top(b, (*a)->index - 1) == 1)
			rb(b, 0);
		else if (*b && if_index_top(b, (*a)->index - 1) == 0)
			rrb(b, 0);
	}
}

void	huge_sort(t_stack **a, t_stack **b)
{
	int	pv1;
	int	pv2;

	pv2 = 0;
	while (lst_size(a) > 3)
	{
		pv1 = (lst_size(a) / 6) + pv2;
		pv2 += (lst_size(a) / 3);
		while (lst_size(b) < pv2 && lst_size(a) > 3)
		{
			if (lst_size(b) > 1 && (*b)->index < pv1 && (*a)->index >= pv2)
				rr(a, b);
			else if (lst_size(b) > 1 && (*b)->index < pv1)
				rb(b, 0);
			if ((*a)->index >= pv2)
				ra(a, 0);
			else if ((*a)->index < pv2)
				pb(a, b);
		}
	}
	sort_3(a);
	b_to_a(a, b);
	while (is_sorted(*a) == 1)
		rra(a, 0);
}
