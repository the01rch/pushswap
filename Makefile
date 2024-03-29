# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: redrouic <redrouic@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/04 19:41:59 by redrouic          #+#    #+#              #
#    Updated: 2024/03/14 17:37:09 by redrouic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC	=	src/main.c\
		src/utils.c\
		src/astack.c\
		src/rules.c\
		src/midpoint.c\

CC	=	gcc

OBJ	=	$(SRC:.c=.o)

NAME	=	pushswap

CFLAGS	+=	-Wall -Wextra -Werror -g3

RM	=	rm -rf

all: $(NAME)
	
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
 
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
