/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-omra <hel-omra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 01:14:51 by hel-omra          #+#    #+#             */
/*   Updated: 2024/02/22 04:37:45 by hel-omra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	is_sorted(t_stack *a)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp->next && tmp->content < tmp->next->content)
		tmp = tmp->next;
	if (tmp->next == NULL)
		return (0);
	return (1);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)

{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && i < n && s1[i] && s2[i])
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	do_operations(t_stack **a, t_stack **b, char *instractions)
{
	
	if (ft_strncmp(instractions, "pa\n", 3) == 0)
		pa(a, b);
	else if (ft_strncmp(instractions, "pb\n", 3) == 0)
		pb(a, b);
	else if (ft_strncmp(instractions, "sa\n", 3) == 0)
		sa(a);
	else if (ft_strncmp(instractions, "sb\n", 3) == 0)
		sb(b);
	else if (ft_strncmp(instractions, "ss\n", 3) == 0)
		ss(a, b);
	else if (ft_strncmp(instractions, "ra\n", 3) == 0)
		ra(a);
	else if (ft_strncmp(instractions, "rb\n", 3) == 0)
		rb(b);
	else if (ft_strncmp(instractions, "rr\n", 3) == 0)
		rr(a, b);
	else if (ft_strncmp(instractions, "rra\n", 4) == 0)
		rra(a);
	else if (ft_strncmp(instractions, "rrb\n", 4) == 0)
		rrb(b);
	else if (ft_strncmp(instractions, "rrr\n", 4) == 0)
		rrr(a, b);
	else
		ft_error();
}
