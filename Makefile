# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rberon-s <rberon-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/30 15:19:48 by nhamill           #+#    #+#              #
#    Updated: 2019/10/29 18:39:09 by rberon-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

FLGS = -Wall -Wextra -Werror -MMD -MP -g

CC = gcc

DIR = srcs

SRC = main.c bfs.c fs.c route.c who.c parse.c step.c nbors.c edge.c room.c \
	ant.c find.c set.c free.c path.c fix_neighbors.c route_help.c exit.c \
	init.c

SRCS = $(addprefix $(DIR)/,$(SRC))

OBJ = $(addprefix $(DIR)/,$(SRC:.c=.o))

DEP = $(addprefix $(DIR)/,$(patsubst %.c,%.d,$(SRC)))

INC = -I includes -I $(LIBFT)

LIB = libft/libft.a

PRINT = libft/liblight_printf.a

LIBFT = libft

LIB_IN = -L libft -lft -llight_printf

all: $(NAME)

$(NAME): $(LIB) $(PRINT) $(OBJ)
	$(CC) -o $@ $(OBJ) $(LIB_IN)

LIBA:
	@make -C $(LIBFT)

.PHONY: LIBA

$(LIB): LIBA

$(PRINT): LIBA

%.o: %.c
	$(CC) $(FLGS) -c $< -o $@ $(INC)

-include $(DEP)

clean:
	make -C $(LIBFT) clean
	rm -f $(OBJ) $(DEP)

fclean: clean
	make -C $(LIBFT) fclean
	rm -f $(NAME)

re: fclean all
