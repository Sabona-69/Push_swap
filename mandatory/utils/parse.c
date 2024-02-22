/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-omra <hel-omra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:37:55 by hel-omra          #+#    #+#             */
/*   Updated: 2024/02/20 23:42:45 by hel-omra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	is_empty(char **av, int ac)
{
	int		i;
	int		j;

	j = 0;
	while (ac--)
	{
		i = 0;
		while (av[j][i] != '\0' && (av[j][i] == '\n'
				|| av[j][i] == '\t' || av[j][i] == ' '))
			i++;
		if (av[j][i] == '\0')
			return (1);
		j++;
	}
	return (0);
}

int	syntax_error(char **av)
{
	int		i;
	int		j;

	j = 1;
	while (av[j])
	{
		i = 0;
		while (av[j][i] && ((av[j][i] >= '0' && av[j][i] <= '9')
			|| av[j][i] == '+' || av[j][i] == '-' || av[j][i] == ' '))
			i++;
		if (av[j][i] != '\0')
			return (1);
		j++;
	}
	return (0);
}

void	exist(int added, t_stack **a)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp)
	{
		if (tmp->content == added)
		{
			lst_clear(a);
			ft_error();
		}
		tmp = tmp->next;
	}
}
