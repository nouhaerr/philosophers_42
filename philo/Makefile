# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/07 16:04:25 by nerrakeb          #+#    #+#              #
#    Updated: 2023/07/30 04:09:20 by nerrakeb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

CFILES = philo.c utils.c check_args.c \
		init.c start_philos.c start_eating.c \
		utils_time.c
	
OBJ = $(CFILES:.c=.o)

NAME = philo

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

all : $(NAME)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.SILENT : $(OBJ)

.PHONY: all clean fclean re
