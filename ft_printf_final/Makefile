# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmotov <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/26 16:39:00 by mmotov            #+#    #+#              #
#    Updated: 2018/02/12 09:28:35 by mmotov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_LIB =        ft_atoi.c         \
				 ft_bzero.c         \
				 ft_change_lst.c     \
				 ft_isalnum.c        \
				 ft_isalpha.c        \
				 ft_isascii.c        \
				 ft_isdigit.c        \
				 ft_islower.c        \
				 ft_isprint.c        \
				 ft_isupper.c        \
				 ft_itoa.c           \
				 ft_lstadd.c         \
				 ft_lstdel.c         \
				 ft_lstdelone.c      \
				 ft_lstiter.c        \
				 ft_lstmap.c         \
				 ft_lstnew.c         \
				 ft_lstprint.c       \
				 ft_lstsize.c        \
				 ft_memalloc.c       \
				 ft_memccpy.c        \
				 ft_memchr.c         \
				 ft_memcmp.c         \
				 ft_memcpy.c         \
				 ft_memdel.c         \
				 ft_memmove.c        \
				 ft_memset.c         \
				 ft_putchar.c        \
				 ft_putchar_fd.c     \
				 ft_putendl.c        \
				 ft_putendl_fd.c     \
				 ft_putnbr.c         \
				 ft_putnbr_fd.c      \
				 ft_putstr.c         \
				 ft_putstr_fd.c      \
				 ft_strcat.c         \
				 ft_strchr.c         \
				 ft_strclr.c         \
				 ft_strcmp.c         \
				 ft_strcpy.c         \
				 ft_strdel.c         \
				 ft_strdup.c         \
				 ft_strequ.c         \
				 ft_striter.c        \
				 ft_striteri.c       \
				 ft_strjoin.c        \
				 ft_strlcat.c        \
				 ft_strlen.c         \
				 ft_strmap.c         \
				 ft_strmapi.c        \
				 ft_strncat.c        \
				 ft_strncmp.c        \
				 ft_strncpy.c        \
				 ft_strnequ.c        \
				 ft_strnew.c         \
				 ft_strnstr.c        \
				 ft_strrchr.c        \
				 ft_strsplit.c       \
				 ft_strstr.c         \
				 ft_strsub.c         \
				 ft_strtrim.c        \
				 ft_swap.c           \
				 ft_tolower.c        \
				 ft_toupper.c        \
				 ft_lstadd_end.c	 \
				 ft_lstdel_func.c    \

SRC =            ft_printf.c                \
				 ft_char.c                  \
				 ft_check_accur.c           \
				 ft_find_change.c           \
				 ft_hexal.c                 \
				 ft_integers.c              \
				 ft_itoa_base.c             \
				 ft_itoa_uns.c              \
				 ft_make_unicode.c          \
				 ft_octal.c                 \
				 ft_percent.c               \
				 ft_ptr.c                   \
				 ft_push_char.c             \
				 ft_push_x.c                \
				 ft_str_toupper.c           \
				 ft_string.c                \
				 ft_string_unicode.c        \
				 ft_octal.c                 \
				 ft_unicode.c               \
				 ft_unsigned.c			\
				 ft_check_width_num.c	\
				 ft_check_accur_str.c	\
				 ft_str_long_inegers.c	\
				 ft_invalid.c            \
				 ft_check_flags_num.c    \
				 ft_check_width_str.c    \
				 ft_print_null.c         \
				 ft_add_accur.c          \
				 ft_full_arr_strlen.c    \
				 ft_del_arr.c            \
				 ft_print_unicode.c      \
				 ft_check_width_unicode.c \
				 ft_end_form.c           \
				 ft_flags_search.c       \
				 ft_width_search.c       \
				 ft_size_search.c        \
				 ft_accuracy_search.c    \
				 ft_type_search.c        \
				 ft_check_apostrophe.c   \
				 ft_star.c

OBJ_PATH = ./libftprintf/
OBJ_LIB_PATH = ./libft/

INCLUDE = -I ./libftprintf -I ./libft/
OBJ = $(addprefix $(OBJ_PATH), $(SRC:.c=.o))
OBJ_LIB = $(addprefix $(OBJ_LIB_PATH), $(SRC_LIB:.c=.o))
CFLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re
all: $(NAME)

$(NAME): $(OBJ) $(OBJ_LIB)
	@ar rc $(NAME) $(OBJ) $(OBJ_LIB)
	@ranlib $(NAME)
	@echo made

%.o: %.c
	@gcc -g $(CFLAGS) -c $< -o $@ $(INCLUDE)

clean:
	/bin/rm -f $(OBJ) $(OBJ_LIB)
	echo cleaned

fclean: clean
	/bin/rm -f $(NAME)
	echo fcleaned

re: fclean all
