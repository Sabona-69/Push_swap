# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hel-omra <hel-omra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/06 09:28:50 by hel-omra          #+#    #+#              #
#    Updated: 2024/02/22 05:57:20 by hel-omra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	push_swap

B_NAME	= 	checker

Flags	= 	-Wall -Wextra -Werror
FILES	=	mandatory/sort/sorting.c mandatory/sort/tiny_sort.c \
			mandatory/utils/handle_errors.c mandatory/utils/parse.c mandatory/utils/stack_fill.c mandatory/utils/utils.c mandatory/utils/utils2.c \
			mandatory/operations/operations_1.c mandatory/operations/operations_2.c mandatory/operations/operations_3.c \
			mandatory/push_swap.c

B_FILES =	bonus/utils/handle_errors_bonus.c bonus/utils/parse_bonus.c bonus/utils/stack_fill_bonus.c bonus/utils/utils_bonus.c \
			bonus/utils/utils2_bonus.c bonus/utils/utils3_bonus.c bonus/utils/get_next_line.c\
			bonus/operations/operations1_bonus.c bonus/operations/operations2_bonus.c bonus/operations/operations3_bonus.c \
			bonus/checker.c

 OBJ	=	$(FILES:.c=.o)

B_OBJ	=	$(B_FILES:.c=.o)

 all		: $(NAME)

$(B_NAME)	: $(B_OBJ)
		cc $(Flags) $(B_OBJ) -o $(B_NAME)

$(NAME)		: $(OBJ)
		cc $(Flags) $(OBJ) -o $(NAME) 

bonus		: $(B_NAME)

bonus/%.o	: bonus/%.c include/checker.h
		cc $(Flags) -c $< -o $@

mandatory/%.o	: mandatory/%.c include/push_swap.h
		cc $(Flags) -c $< -o $@
	
clean		:
		@rm -rf $(OBJ) $(B_OBJ)

fclean		: clean
		@rm -rf $(NAME) $(B_NAME)

  re		: fclean all