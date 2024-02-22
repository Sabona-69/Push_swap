/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-omra <hel-omra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:28:09 by hel-omra          #+#    #+#             */
/*   Updated: 2024/02/22 04:38:45 by hel-omra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
}	t_stack;

// linked list functions 
void		ft_lstadd_back(t_stack **lst, t_stack *new);
void		ft_lstadd_front(t_stack **lst, t_stack *new);
void		lst_clear(t_stack **a);
int			lst_size(t_stack **a);
t_stack		*ft_lstnew(int content);
t_stack		*lst_last(t_stack *lst);

// operations
void		sa(t_stack **a, int flag);
void		sb(t_stack **b, int flag);
void		ss(t_stack **a, t_stack **b);
void		ra(t_stack **a, int flag);
void		rb(t_stack **b, int flag);
void		rr(t_stack **a, t_stack **b);
void		pa(t_stack **a, t_stack **b);
void		pb(t_stack **a, t_stack **b);
void		rra(t_stack **a, int flag);
void		rrb(t_stack **b, int flag);
void		rrr(t_stack **a, t_stack **b);

// handle Errors
void		ft_error(void);
int			is_empty(char **av, int ac);
int			syntax_error(char **av);
void		free2d(char **s, int i, int flag);
void		free2d_2(char **s, char **s1);

// utils
size_t		ft_strlen(char *s);
size_t		ft_strlen2d(char **s);
int			is_sorted(t_stack *a);
void		stack_fill(char **av, t_stack **a);
char		**ft_split(char *s);
int			custom_atoi(char *s);
void		exist(int added, t_stack **a);
int			get_index(t_stack *list, int number);

// Sort
void		sorting(t_stack **a, t_stack **b);
void		sort_2(t_stack **a);
void		sort_3(t_stack **a);
void		sort_4(t_stack **a, t_stack **b);
void		sort_5(t_stack **a, t_stack **b);
void		huge_sort(t_stack **a, t_stack **b);

#endif