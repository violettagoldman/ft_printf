# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgoldman <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/31 21:24:15 by vgoldman          #+#    #+#              #
#    Updated: 2019/11/26 10:19:08 by vgoldman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC =	./src/ft_printf.c\
		./src/handle_ut.c\
		./src/handle_ut2.c\
		./src/handle_format.c\
		./src/handlers.c\
		./src/handlers2.c\
		./src/handle_ut3.c

OBJ =	./obj/ft_printf.o\
		./obj/handle_ut.o\
		./obj/handle_ut2.o\
		./obj/handle_format.o\
		./obj/handlers.o\
		./obj/handlers2.o\
		./obj/handle_ut3.o

FLAGS = -Werror -Wall -Wextra

all: ${NAME}

test: ${NAME} main.c
	@gcc ${FLAGS} -g3 -fsanitize=address -I./inc/ -L. -lftprintf main.c && ./a.out

norme:
	@echo "\033[0;32mChecking the norme...\033[0m"
	@norminette ./src/*.c
	@norminette ./includes/*.h

${NAME}:${OBJ}
		@printf "\033[0;32mMaking the library...\033[0m\r"
		@mkdir -p ./obj/
		@ar rcs ${NAME} ${OBJ}
		@echo "\033[32;1mThe library is done \xE2\x9C\x94\033[0m          "

./obj/%.o: ./src/%.c
	@mkdir -p ./obj/
	@gcc ${FLAGS} -I./inc/ -c $< -o $@

clean:
	@rm -rf ${OBJ} a.out a.out.dSYM
	@echo "\033[32;1mCleaned \xE2\x9C\x94\033[0m"

fclean: clean
		@rm -rf ${NAME} obj
		@echo "\033[32;1mForced cleaned \xE2\x9C\x94\033[0m"

re: fclean all

.PHONY: clean fclean all re


