# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmotov <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/26 16:39:00 by mmotov            #+#    #+#              #
#    Updated: 2018/02/26 13:20:21 by mmotov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC =	./src/ft_get_file_data.c \
		./src/ft_ls.c \
		./src/ft_check_ls_flags.c \
		./src/ft_lst_files.c \
		./src/main.c \
		./src/ft_ls_recursive.c \
		./src/ft_lst_rev.c \
		./src/ft_print_files.c \
		./src/ft_print_time.c \
		./src/ft_merge_sort_lex.c \
		./src/ft_format_file.c \
		./src/ft_sorted_time.c \
		./src/ft_front_back_split.c \
		./src/ft_find_error.c \
		./src/ft_find_files.c \
		./src/ft_find_dir.c \
		./src/ft_merge_sort_size.c \
		./src/ft_misc_ft.c \
		./src/ft_make_format.c \
		./src/ft_print_info.c \
		./src/ft_initialisation.c \
		./src/ft_check_type.c \
		./src/ft_parse_flags.c \

OBJ_PATH = ./src/

OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror
LIB = ./ft_printf_final/libftprintf.a

.PHONY: all clean fclean re

all: $(NAME)

$(NAME) : $(OBJ)
	@make -C ./ft_printf_final/ all
	@gcc -o $(NAME) $(FLAGS) $(SRC) $(LIB)
	@echo made

%.o: %.c
	@gcc $(FLAGS) -c -o $@ $<

clean:
	@/bin/rm -f $(OBJ)
	@make -C ./ft_printf_final/ clean
	@echo cleaned

fclean: clean
	@/bin/rm -f $(OBJ) $(NAME)
	@make -C ./ft_printf_final/ fclean
	@echo fcleaned

re: fclean all
