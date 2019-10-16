# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lvan-vlo <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/10 11:00:00 by lvan-vlo       #+#    #+#                 #
#    Updated: 2019/08/10 11:48:59 by lvan-vlo      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --silent

NAME = libft.a

SRCS = conversionist.c csp_conversion.c di_conversion.c ft_atoi.c ft_bzero.c \
ft_delmap.c ft_f_conversion.c ft_getdigits.c ft_inbetween.c ft_isalnum.c \
ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa_base.c ft_itoa.c \
ft_lowercase.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c \
ft_lstnew.c ft_make_conversion.c ft_memalloc.c ft_memccpy.c ft_memchr.c \
ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_print_map.c \
ft_printf.c ft_putchar_fd.c ft_putchar.c ft_putendl_fd.c ft_putendl.c \
ft_putnbr_fd.c ft_putnbr.c ft_putstr_fd.c ft_putstr.c ft_strcat.c ft_strccpy.c \
ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c \
ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlchr.c \
ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c \
ft_strndup.c ft_strnequ.c ft_strnew.c ft_strnjoin.c ft_strnstr.c ft_strrchr.c \
ft_strrev.c ft_strsplit_old.c ft_strsplit.c ft_strstr.c ft_strsub.c \
ft_strtrim.c ft_substring_count.c ft_substring_size.c ft_tolower.c \
ft_toupper.c ft_utoa_base.c ft_wordcount.c get_next_line.c oux_conversion.c \
precision_padding.c

HEAD = libft.h get_next_line.h

OBJ = ${SRCS:c=o}

all: $(NAME)

$(NAME):
	@echo "\033[3;33mCompiling libft...\033[0m"
	gcc -c -Wall -Werror -Wextra $(SRCS)
	ar r $(NAME) ${OBJ} $(HEAD)

clean:
	rm -rf ${OBJ}

fclean: clean
	rm -rf $(NAME)

re: fclean all