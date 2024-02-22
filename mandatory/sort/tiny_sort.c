/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-omra <hel-omra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 01:59:10 by hel-omra          #+#    #+#             */
/*   Updated: 2024/02/22 05:41:12 by hel-omra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	is_sorted(t_stack *a)
{
	t_stack	*tmp;

	if (!a)
		return (1);
	tmp = a;
	while (tmp->next && tmp->content < tmp->next->content)
		tmp = tmp->next;
	if (tmp->next == NULL)
		return (0);
	return (1);
}

void	sort_2(t_stack **a)
{
	sa(a, 0);
}

void	sort_3(t_stack **a)
{
	int	n[3];

	n[0] = (*a)->content;
	n[1] = (*a)->next->content;
	n[2] = (*a)->next->next->content;
	if (is_sorted(*a) == 1)
	{
		if (n[1] < n[0] && n[1] < n[2] && n[0] < n[2])
			sa(a, 0);
		else if (n[2] < n[1] && n[2] < n[0] && n[0] > n[1])
		{
			sa(a, 0);
			rra(a, 0);
		}
		else if (n[1] < n[0] && n[1] < n[2] && n[0] > n[2])
			ra(a, 0);
		else if (n[0] < n[1] && n[0] < n[2] && n[1] > n[2])
		{
			sa(a, 0);
			ra(a, 0);
		}
		else if (n[2] < n[0] && n[2] < n[1] && n[0] < n[1])
			rra(a, 0);
	}
}

void	sort_4(t_stack **a, t_stack **b)
{
	t_stack	*current;

	current = *a;
	while (current)
	{
		if (current->index == 0)
			break ;
		else if (lst_last((*a))->index == 0)
		{
			rra(a, 0);
			break ;
		}
		ra(a, 0);
		current = *a;
	}
	pb(a, b);
	sort_3(a);
	pa(a, b);
}

void	sort_5(t_stack **a, t_stack **b)
{
	t_stack	*current;

	current = *a;
	while (current)
	{
		if (current->index == 1)
			break ;
		else if (lst_last((*a))->index == 1)
		{
			rra(a, 0);
			break ;
		}
		ra(a, 0);
		current = *a;
	}
	pb(a, b);
	sort_4(a, b);
	pa(a, b);
	if ((*a)->content > (*a)->next->content)
		sa(a, 0);
}
