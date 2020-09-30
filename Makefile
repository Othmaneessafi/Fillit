# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oes-safi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/27 05:26:56 by oes-safi          #+#    #+#              #
#    Updated: 2019/07/26 20:40:26 by oes-safi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INC = fillit.h
OBJ = checker.o map.o solve.o stock.o main.o
CFLAGS = -Wall -Werror -Wextra
CC = gcc
NAME = fillit
LIBS = libft/libft.a

all : $(NAME)
%.o : %.c $(INC)
	$(CC) $(FLAGS) -c -o $@ $<
$(NAME): $(OBJ)
	@make -C libft
	@$(CC) $(OBJ) -o $(NAME) -I $(INC) $(LIBS)
	@printf "\033[32mFillit compilation done\n\033[0m"

clean :
	@rm -f $(OBJ)
	@make -C libft clean
	@printf "\033[33mFillit objects removed\n\033[0m"

fclean : clean
	@rm -f $(NAME)
	@make -C libft fclean
	@printf "\033[31mFillit binary file removed\n\033[0m"

re : fclean all

