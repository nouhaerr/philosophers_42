# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/07 16:04:25 by nerrakeb          #+#    #+#              #
#    Updated: 2023/07/29 02:44:27 by nerrakeb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror #-fsanitize=thread -g3

CFILES = philo_bonus.c utils_bonus.c check_args_bonus.c \
		init_bonus.c start_philos_bonus.c start_eating_bonus.c \
		utils_time_bonus.c begin_routine_bonus.c
	
OBJ = $(CFILES:.c=.o)

NAME = philo_bonus

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

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
