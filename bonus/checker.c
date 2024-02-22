/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-omra <hel-omra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:33:19 by hel-omra          #+#    #+#             */
/*   Updated: 2024/02/22 05:58:52 by hel-omra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	ft_result(t_stack **a, t_stack **b)
{
	if (is_sorted(*a) == 0 && lst_size(b) == 0)
		write (1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	if (lst_size(b) != 0)
		lst_clear (b);
	lst_clear (a);
}

int	main(int ac, char *av[])
{
	char		*instractions;
	t_stack		*a;
	t_stack		*b;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (0);
	if (is_empty(av, ac) == 1)
		ft_error();
	if (syntax_error(av) == 1)
		ft_error();
	stack_fill(av, &a);
	while (1)
	{
		instractions = get_next_line(0);
		if (!instractions)
		{
			free(instractions);
			break ;
		}
		do_operations(&a, &b, instractions);
		free(instractions);
	}
	ft_result(&a, &b);
}
