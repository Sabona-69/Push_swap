/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-omra <hel-omra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:36:44 by hel-omra          #+#    #+#             */
/*   Updated: 2024/02/22 05:24:19 by hel-omra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker.h"

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (!lst && new)
		*lst = new;
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

t_stack	*ft_lstnew(int content)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

t_stack	*lst_last(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (lst == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = lst_last(*lst);
	last->next = new;
}

int	lst_size(t_stack **a)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	if (!(*a))
		return (0);
	tmp = *a;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
