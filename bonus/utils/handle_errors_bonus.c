/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-omra <hel-omra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 10:45:12 by hel-omra          #+#    #+#             */
/*   Updated: 2024/02/22 04:32:51 by hel-omra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker.h"

void	free2d_2(char **s, char **s1)
{
	free2d(s, ft_strlen2d(s) - 1, 2);
	free2d(s1, ft_strlen2d(s1) - 1, 1);
}

void	free2d(char **s, int i, int flag)
{
	while (i > -1)
		free(s[i--]);
	free(s);
	if (flag == 1)
		exit(1);
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	lst_clear(t_stack **a)
{
	t_stack	*current;
	t_stack	*tmp;

	current = *a;
	while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	*a = NULL;
}
