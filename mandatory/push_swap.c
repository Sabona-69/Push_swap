/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-omra <hel-omra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 10:10:07 by hel-omra          #+#    #+#             */
/*   Updated: 2024/02/22 04:57:39 by hel-omra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (0);
	if (is_empty(av, ac) == 1)
		ft_error();
	if (syntax_error(av) == 1)
		ft_error();
	stack_fill(av, &a);
	sorting(&a, &b);
	lst_clear(&a);
}
