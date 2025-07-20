# Nome da biblioteca a ser criada.
NAME = libft.a

# Compilador C a ser usado.
CC = cc

# Flags de compilação obrigatórias.
CFLAGS = -Wall -Wextra -Werror

# Caminho para o arquivo de cabeçalho principal.
HEADER = libft.h

# Nome do arquivo sentinela para controlar o "relink" do bônus.
BONUS_DONE = .bonus_done

# Arquivos fonte da parte obrigatória.
SRCS = ft_atoi.c \
	   ft_bzero.c \
	   ft_calloc.c \
	   ft_isalnum.c \
	   ft_isalpha.c \
	   ft_isascii.c \
	   ft_isdigit.c \
	   ft_isprint.c \
	   ft_itoa.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_memcpy.c \
	   ft_memmove.c \
	   ft_memset.c \
	   ft_putchar_fd.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c \
	   ft_putstr_fd.c \
	   ft_split.c \
	   ft_strchr.c \
	   ft_strdup.c \
	   ft_striteri.c \
	   ft_strjoin.c \
	   ft_strlcat.c \
	   ft_strlcpy.c \
	   ft_strlen.c \
	   ft_strmapi.c \
	   ft_strncmp.c \
	   ft_strnstr.c \
	   ft_strrchr.c \
	   ft_strtrim.c \
	   ft_substr.c \
	   ft_tolower.c \
	   ft_toupper.c

# Arquivos fonte da parte bônus.
BONUS_SRCS = ft_lstnew.c \
			 ft_lstadd_front.c \
			 ft_lstsize.c \
			 ft_lstlast.c \
			 ft_lstadd_back.c \
			 ft_lstdelone.c \
			 ft_lstclear.c \
			 ft_lstiter.c \
			 ft_lstmap.c

# Geração dos nomes dos arquivos objeto.
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

# Regra 'all': Padrão para construir o projeto.
# Depende da regra que cria a biblioteca final ($(NAME)).
all: $(NAME)

# Regra para criar a biblioteca estática (libft.a) com as funções obrigatórias.
# Depende de todos os arquivos objeto da parte obrigatória ($(OBJS)).
# Se qualquer OBJS for mais novo que $(NAME), esta regra é executada.
$(NAME): $(OBJS)
	ar rcs $@ $^

# Regra 'bonus': Chama a regra que adiciona as funções bônus e atualiza a sentinela.
# Esta regra é .PHONY, o que significa que ela não cria um arquivo real com o nome 'bonus'.
# Ela apenas invoca a regra $(BONUS_DONE), que é quem faz o trabalho e é rastreável pelo make.
bonus: $(BONUS_DONE)

# Regra para construir/atualizar a parte bônus da libft.a.
# O alvo desta regra é o arquivo sentinela ($(BONUS_DONE)).
# O 'make' só executará esta regra se:
# 1. O arquivo sentinela ($(BONUS_DONE)) não existir.
# 2. Algum arquivo objeto do bônus ($(BONUS_OBJS)) for mais novo que a sentinela.
# 3. A própria 'libft.a' ($(NAME)) for mais nova que a sentinela (indicando que a libft.a foi reconstruída
#    pelos mandatórios, então o bônus precisa ser reinserrado).
$(BONUS_DONE): $(BONUS_OBJS) $(NAME)
	# Adiciona/atualiza os objetos do BÔNUS na libft.a existente.
	ar rcs $(NAME) $(BONUS_OBJS)
	# Cria ou atualiza a sentinela para indicar que o bônus foi processado.
	touch $(BONUS_DONE)

# Regra padrão para compilar qualquer arquivo .c em um arquivo .o.
# O arquivo .o depende do seu arquivo .c correspondente e do libft.h.
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

# Regras de Limpeza
clean:
	rm -f $(OBJS) $(BONUS_OBJS) $(BONUS_DONE)

# Regra 'fclean': Remove todos os arquivos objeto, o arquivo sentinela e a biblioteca final.
fclean: clean
	rm -f $(NAME)

# Regra 're': Recompila tudo do zero.
re: fclean all

# Declaração das regras 'all', 'bonus', 'clean', 'fclean', 're' como .PHONY.
# Isso garante que elas sejam executadas mesmo que um arquivo com o mesmo nome exista.
.PHONY: all bonus clean fclean re
