# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jota <jota@student.42sp.org.br>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/28 07:00:00 by jota              #+#    #+#              #
#    Updated: 2025/07/28 07:00:00 by jota             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a
BONUS_NAME = get_next_line_bonus.a

SRCS = get_next_line.c get_next_line_utils.c
BONUS_SRCS = get_next_line_bonus.c get_next_line_utils_bonus.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=42

# regra padrão: compila o mandatory
all: $(NAME)

# cria a lib static do mandatory
$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

# cria a lib static do bonus
bonus: $(BONUS_OBJS)
	@ar rcs $(BONUS_NAME) $(BONUS_OBJS)

# apaga os objetos (mandatory e bonus)
clean:
	@rm -f $(OBJS) $(BONUS_OBJS)

# apaga objetos + libs
fclean: clean
	@rm -f $(NAME) $(BONUS_NAME)

# recompila tudo (fclean + all)
re: fclean all

.PHONY: all bonus clean fclean re
