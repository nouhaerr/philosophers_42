# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/07 16:04:25 by nerrakeb          #+#    #+#              #
#    Updated: 2023/07/18 22:48:20 by nerrakeb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror -fsanitize=thread -g3

CFILES = philo.c utils.c check_args.c \
		init.c start_philos.c start_eating.c \

OBJ = $(CFILES:.c=.o)

NAME = philo

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -lpthread $(OBJ) -o $(NAME)

all : $(NAME)

clean :
	@rm -rf $(OBJ)
	@echo "\033[1;31m- Object files removed!\033[0m"

fclean : clean
	@rm -rf $(NAME)
	@echo "\033[1;31m all clean\033[0;0m"

re : fclean all

.SILENT : $(OBJ)

.PHONY: all clean fclean re
