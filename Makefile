# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/08/10 11:22:05 by lvan-vlo       #+#    #+#                 #
#    Updated: 2019/09/28 14:48:43 by rcorke        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --silent

FLAGS = -Wall -Wextra -Werror

NAME = lem-in

SRC = main.c store_input.c input_type.c error.c \
make_tables.c hash_functions.c add_link.c new_queue_functions.c \
make_real_paths.c move_ants.c new_bfs.c path_traversal.c path_traversal_2.c \
free_erryting.c free_functions.c utility_functions.c print_storage.c \
ft_fits_in_int.c

INC = -I lem_in.h

LIBFT = libft/libft.a

OBJ := ${SRC:c=o}

all: $(NAME)

$(NAME):
	make -C libft/ re
	echo "\033[3;92mCompiling lem-in...\033[0m"
	gcc -c $(FLAGS) $(SRC)
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(INC) $(LIBFT)

clean:
	rm -rf $(OBJ)
	make -C libft/ clean

fclean: clean
	rm -rf $(NAME)
	make -C libft/ fclean

re: fclean all