# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/09 10:22:48 by oabdelha          #+#    #+#              #
#    Updated: 2022/02/08 13:53:10 by oabdelha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

CM = cc

FLAG = -Wall -Wextra -Werror

SRC = push_swap.c utils/creat.c utils/operations.c utils/operations_2.c utils/sorting.c utils/sort_big_list.c utils/bubble_sort.c utils/utils_sorting.c \
utils/fonction_linked_list_2.c utils/fonction_linked_list.c utils/ft_putendl_fd.c utils/ft_split.c utils/auxiliary_functions.c utils/operation_3.c utils/utils_checking.c

BONUS = checker.c utils/creat.c utils/operations.c utils/operations_2.c utils/sorting.c utils/sort_big_list.c utils/bubble_sort.c utils/utils_sorting.c \
utils/fonction_linked_list_2.c utils/fonction_linked_list.c utils/ft_putendl_fd.c utils/ft_split.c utils/auxiliary_functions.c utils/operation_3.c utils/utils_checking.c

CNVRT = $(SRC:.c=.o)

CNVRTB = $(BONUS:.c=.o)

INCLUDE = push_swap.h

all: $(NAME)

$(NAME): $(CNVRT) $(INCLUDE)
	@$(CM) $(FLAG) $(CNVRT) -o push_swap

bonus: $(CNVRTB) $(INCLUDE)
	@$(CM) $(FLAG) $(CNVRTB) -o checker

%.o : %.c $(INCLUDE)
	@$(CM) $(FLAG) -o $@  -c $<

clean:
	@rm -rf $(CNVRT) $(CNVRTB) push_swap checker
	
fclean: clean
	@rm -rf $(NAME)

re: fclean all
