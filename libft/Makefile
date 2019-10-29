#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nhamill <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/09 01:49:49 by nhamill           #+#    #+#              #
#    Updated: 2019/10/18 20:28:18 by nhamill          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

PRINT = liblight_printf.a

FLAGS = -Wall -Wextra -Werror -MMD -MP

SRC = ./ft_atoi.c ./ft_bzero.c ./ft_isalnum.c ./ft_isalpha.c ./ft_isascii.c \
./ft_isdigit.c ./ft_isprint.c ./ft_itoa.c ./ft_memalloc.c ./ft_memccpy.c \
./ft_memchr.c ./ft_memcmp.c ./ft_memcpy.c ./ft_memdel.c ./ft_memmove.c \
./ft_memset.c ./ft_putchar_fd.c ./ft_putchar.c ./ft_putendl_fd.c ./ft_putendl.c\
./ft_putnbr_fd.c ./ft_putnbr.c ./ft_putstr_fd.c ./ft_putstr.c ./ft_strcat.c \
./ft_strchr.c ./ft_strcmp.c ./ft_strcpy.c ./ft_strdup.c ./ft_strequ.c \
./ft_striter.c ./ft_striteri.c ./ft_strjoin.c ./ft_strlcat.c ./ft_strlen.c \
./ft_strmapi.c ./ft_strmap.c ./ft_strncat.c ./ft_strncmp.c ./ft_strncpy.c \
./ft_strnequ.c ./ft_strnew.c ./ft_strnstr.c ./ft_strrchr.c ./ft_strsplit.c \
./ft_strstr.c ./ft_strsub.c ./ft_strtrim.c ./ft_tolower.c ./ft_toupper.c \
./ft_strclr.c ./ft_strdel.c ./ft_lstnew.c ./ft_lstdelone.c ./ft_lstdel.c \
./ft_lstadd.c ./ft_lstiter.c ./ft_lstmap.c ./ft_lstsplit.c ./ft_strrev.c \
./ft_lstaddlast.c ./ft_lstfind.c ./ft_lstfold.c ft_pow.c ft_isspace.c \
get_next_line.c

SRC_PR = ft_printf.c ft_printf1.c

INC = -I .

OBJ = $(SRC:.c=.o)

OBJ_PR = $(SRC_PR:.c=.o)

DEP = $(patsubst %.c,%.d,$(SRC))

DEP_PR = $(patsubst %.c,%.d,$(SRC_PR))

all: $(NAME) $(PRINT)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(PRINT): $(OBJ_PR)
	@ar rc $(PRINT) $(OBJ_PR)
	@ranlib $(PRINT)

.c.o:
	gcc $(FLAGS) $(INC) -c $< -o $@

-include $(DEP) $(DEP_PR)

clean:
	@rm -f $(OBJ) $(DEP) $(OBJ_PR) $(DEP_PR)

fclean: clean
	@rm -f $(NAME) $(PRINT)

re:		fclean all
