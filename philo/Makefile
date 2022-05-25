# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/14 21:14:47 by estoffel          #+#    #+#              #
#    Updated: 2022/05/03 20:16:52 by estoffel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror -g3 -pthread

SRC		=	\
			die.c		\
			free.c		\
			init.c		\
			main.c		\
			parsing.c	\
			routine.c	\
			utils.c		\
			time.c		\
			visual.c	\

OBJ		=	$(addprefix ./src/,$(SRC:%.c=%.o))

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	clear
	@echo "🌼\033[1;97m P H I L O  C R E A T E D  W I T H  S U C C E S S 🌼\e[0m"
	@printf "\n"

clean:
	@rm -f $(OBJ)
	clear
	@echo "💧\033[1;97m E V E R Y T H I N G  I S  C L E A N E D 💧\e[0m"
	@printf "\n"

fclean:
	@rm -f $(OBJ)
	$(RM) $(NAME)
	clear
	@echo "💧\033[1;97m E V E R Y T H I N G  I S  C L E A N E D 💧\e[0m"
	@printf "\n"

re: fclean all

.PHONY: all clean fclean re
