# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: icastell <icastell@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/30 18:18:35 by icastell          #+#    #+#              #
#    Updated: 2022/03/22 19:41:53 by icastell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
MKDIR	=	mkdir -p 
#SRC		=	src

#LIBFT	=	-L libft -lft
#LIB		=	lib/push_swap.h
#P_SWAP	=	src/push_swap.c
SRCS	=	philo.c\
			ft_check_valid_num.c\
			ft_print_utils.c\
			ft_utils.c\


OBJS	:=	$(SRCS:.c=.o)

all:	$(NAME)

$(NAME)	:	$(OBJS)

	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

normi:
#			norminette -R CheckForbiddenSourceHeader | grep "Error"
#			norminette -R CheckForbiddenSourceHeader $(SRCS) $(LIB) $(P_SWAP)
			norminette -R CheckForbiddenSourceHeader $(SRCS)
#			norminette -R CheckForbiddenSourceHeader | grep "OK"

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -rf $(NAME)

#fclean_all:	fclean
#			make fclean -C libft

re:		fclean all

.PHONY:	all clean fclean re normi