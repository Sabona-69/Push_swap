/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-omra <hel-omra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:45:50 by hel-omra          #+#    #+#             */
/*   Updated: 2024/02/22 04:39:24 by hel-omra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

size_t	ft_strlen2d(char **s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	char	*new;
	int		i;

	i = ft_strlen(s);
	new = malloc (i + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	**strjoin_2d(char **av, char **arr)
{
	char	**new;
	int		i;
	int		k;

	if (av == NULL)
		return (arr);
	new = malloc (sizeof(char *) * (ft_strlen2d(arr) + ft_strlen2d(av) + 1));
	if (!new)
		free2d_2(av, arr);
	(1) && (i = 0, k = 0);
	while (av[i])
	{
		new[k] = ft_strdup(av[i++]);
		if (new[k++] == NULL)
			free2d(new, k - 1, 1);
	}
	i = 0;
	while (arr[i])
	{
		new[k] = ft_strdup(arr[i++]);
		if (new[k++] == NULL)
			free2d(new, k - 1, 1);
	}
	(free2d(av, ft_strlen2d(av) - 1, 2), free2d(arr, ft_strlen2d(arr) - 1, 2));
	return (new[k] = NULL, new);
}

int	get_index(t_stack *list, int number)
{
	t_stack	*node;
	int		index;

	node = list;
	index = 0;
	while (node)
	{
		if (node->content < number)
			index++;
		node = node->next;
	}
	return (index);
}

void	stack_fill(char **av, t_stack **a)
{
	t_stack	*tmp;
	t_stack	*node;
	char	**arr;
	int		i;

	arr = NULL;
	i = 1;
	while (av[i])
		arr = strjoin_2d(arr, ft_split(av[i++]));
	i = 0;
	while (arr[i])
	{
		tmp = ft_lstnew(custom_atoi(arr[i++]));
		if (!tmp)
			return (free(tmp), lst_clear(a), exit(1));
		exist(tmp->content, a);
		ft_lstadd_back(a, tmp);
	}
	node = *a;
	while (node)
	{
		node->index = get_index(*a, node->content);
		node = node->next;
	}
	free2d (arr, ft_strlen2d(arr) - 1, 2);
}
