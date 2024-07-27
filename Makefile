# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/17 19:54:47 by lsampiet          #+#    #+#              #
#    Updated: 2024/07/27 19:49:31 by lsampiet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= push_swap
C_FLAGS:= -Wextra -Wall -Werror
LIBFT= ./libs/libft
BIN= ./bin/
SRC_D= ./src/
CC= cc
HEADER_M= ./includes/push_swap.h
LIBS= $(LIBFT)/libft.a
SRC= push_swap.c \
	 check_args.c \
	 utils.c \
	 create_stacks.c

SRC:= $(addprefix $(SRC_D),$(SRC))

INCLUDES= -I includes -I $(LIBFT)/ -I $(LIBFT)/ft_printf/includes
C_OBJS= $(patsubst $(SRC_D)%.c, $(BIN)%.o, $(SRC))

all: $(NAME)
	echo "Mandatory part OK!🎉"

libft:
	echo "Compiling LIBFT..."
	make all bonus new -C $(LIBFT) $(C_FLAGS) --no-print-directory

$(BIN)%.o: $(SRC_D)%.c
	mkdir -p $(BIN)
	$(CC) $(C_FLAGS) -g3 -o $@ -c $< && echo "Compiling: $(notdir $<)"

$(NAME): $(C_OBJS) libft
	echo "Creating $(NAME)"
	$(CC) $(C_OBJS) $(LIBS) $(INCLUDES) -o $(NAME) -g3 $(C_FLAGS)

clean:
	echo "Cleaning objects..."
	rm -rf $(BIN)
	make fclean -C $(LIBFT) --no-print-directory

fclean: clean
	echo "Cleaning executables..."
	rm -rf $(NAME)
	echo "All done!✨"

re: fclean all

.PHONY: all, clean, fclean, re, libft

.SILENT:
