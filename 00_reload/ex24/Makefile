# Nome da biblioteca a ser criada
NAME = libft.a

# Compilador e flags exigidos
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Diretórios obrigatórios
SRC_DIR = srcs
INC_DIR = includes
OBJ_DIR = objects

# Fontes obrigatórias (explicitamente listadas, sem wildcard)
SRCS = \
	$(SRC_DIR)/ft_putchar.c \
	$(SRC_DIR)/ft_putstr.c \
	$(SRC_DIR)/ft_strcmp.c \
	$(SRC_DIR)/ft_strlen.c \
	$(SRC_DIR)/ft_swap.c

# Objetos (transforma os .c em .o)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Regra padrão
all: $(NAME)

# Como gerar a lib estática
$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

# Como compilar os .c em .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

# Garante que o diretório objects exista
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Remove objetos
clean:
	rm -rf $(OBJ_DIR)

# clean + remove a lib gerada
fclean: clean
	rm -f $(NAME)

# Faz tudo de novo
re: fclean all

# Garante que essas regras sempre rodem do zero
.PHONY: all clean fclean re
