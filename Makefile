# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asioud <asioud@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 11:20:22 by asioud            #+#    #+#              #
#    Updated: 2022/12/27 13:40:12 by asioud           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fract
CC			=	cc
AR			=	ar rcs
RM			=	rm -rf
CFLAGS		=	-Wall -Wextra -Werror -Ofast
GL_FLAG		=	-lglfw -L
GL_PATH		=	/Users/$(USER)/.brew/opt/glfw/lib/
LIBFT_PATH	=	libs/libft/libft.a
LIBMLX_PATH	=	libs/mlx/libmlx42.a

SRC			=	main.c				\
				srcs/colors.c		\
				srcs/draw_utils.c	\
				srcs/fractals.c		\
				srcs/hooks.c		\
				srcs/parse.c

OBJ			=	${SRC:.c=.o}

$(NAME) : $(OBJ)
	@echo "----- Making mlx -----"
	cd libs/mlx/ && make
	@echo "----- Making libft -----"
	cd libs/libft && make
	@echo "----- Compiling fract -----"
	${CC} ${CFLGS} ${SRC} -o ${NAME} ${LIBMLX_PATH} ${LIBFT_PATH} ${GL_FLAG} ${GL_PATH}

all: ${NAME}

install_brew:
	@echo "----- installing brew -----"
	rm -rf $HOME/.brew && rm -rf $HOME/goinfre/.brew && \
	git clone --depth=1 https://github.com/Homebrew/brew $HOME/goinfre/.brew && \
	echo 'export PATH=$HOME/goinfre/.brew/bin:$PATH' >> $HOME/.zshrc && \
	source $HOME/.zshrc && brew update

install_glfw:
	@echo "----- installing glfw -----"
	brew install glfw

install: install_brew install_glfw

clean:
	cd libs/mlx && make clean
	cd libs/libft && make clean
	rm -f ${OBJ}

fclean: clean
	cd libs/mlx && make fclean
	cd libs/libft && make fclean
	rm -f ${NAME}
	
re: fclean all

.PHONY: all install clean fclean re

