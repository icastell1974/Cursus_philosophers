# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: icastell <icastell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/30 18:18:35 by icastell          #+#    #+#              #
#    Updated: 2022/04/28 20:51:18 by icastell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
MKDIR	=	mkdir -p
DEBUG	=	-g3 -fsanitize=address

SRCS	=	philo.c\
			ft_check_valid_num.c\
			ft_print_utils.c\
			ft_utils.c\
			ft_time.c\
			ft_mutex_utils.c\
			ft_philosophers.c\
			ft_pthreads.c\
			ft_philosophers_actions.c\
			ft_print_philo_utils.c\


OBJS	:=	$(SRCS:.c=.o)

all:	$(NAME)

$(NAME)	:	$(OBJS)

#Para probar
#	$(CC) $(CFLAGS) $(SRCS) $(DEBUG) -pthreads -o $(NAME)
#Para entregar
	$(CC) $(CFLAGS) $(SRCS) -pthreads -o $(NAME)

normi:
			norminette -R CheckForbiddenSourceHeader $(SRCS)
			norminette -R CheckForbiddenSourceHeader philo.h
#			norminette -R CheckForbiddenSourceHeader | grep "Error"
#			norminette -R CheckForbiddenSourceHeader | grep "OK"

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:		fclean all

.PHONY:	all clean fclean re normi