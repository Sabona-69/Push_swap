/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-omra <hel-omra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 23:58:07 by hel-omra          #+#    #+#             */
/*   Updated: 2024/02/22 04:33:55 by hel-omra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

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
void		sa(t_stack **a);
void		sb(t_stack **b);
void		ss(t_stack **a, t_stack **b);
void		ra(t_stack **a);
void		rb(t_stack **b);
void		rr(t_stack **a, t_stack **b);
void		pa(t_stack **a, t_stack **b);
void		pb(t_stack **a, t_stack **b);
void		rra(t_stack **a);
void		rrb(t_stack **b);
void		rrr(t_stack **a, t_stack **b);
void		do_operations(t_stack **a, t_stack **b, char *instractions);

// handle Errors
int			is_empty(char **av, int ac);
int			syntax_error(char **av);
void		ft_error(void);
void		free2d(char **s, int i, int flag);
void		free2d_2(char **s, char **s1);

// utils
size_t		ft_strlen2d(char **s);
size_t		ft_strlen(char *s);
int			is_sorted(t_stack *a);
int			get_index(t_stack *list, int number);
int			custom_atoi(char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		stack_fill(char **av, t_stack **a);
void		exist(int added, t_stack **a);
char		**ft_split(char *s);
char		*ft_strjoin(char *s, char *buffer);
char		*ft_strdup(char *s);
int			is_sorted(t_stack *a);
// Get_next_line
char		*get_next_line(int fd);	

#endif