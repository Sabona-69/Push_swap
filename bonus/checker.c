/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-omra <hel-omra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:33:19 by hel-omra          #+#    #+#             */
/*   Updated: 2024/02/22 04:10:08 by hel-omra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

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
	if (is_sorted(a) == 0)
		write (1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
		lst_clear (&a);
		lst_clear (&b);
}

