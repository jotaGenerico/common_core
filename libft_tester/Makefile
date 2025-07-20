# Nome da biblioteca
NAME = libft.a

# Compilador e flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

# Diretórios
INCDIR = includes
SRCDIR = srcs
BONUSDIR = srcs_bonus
OBJDIR = objs
BONUS_OBJDIR = objs_bonus
TESTDIR = tests

# Headers
HEADER = $(INCDIR)/libft.h
BONUS_HEADER = $(INCDIR)/libft.h

# Fontes da libft
SRCS = $(addprefix $(SRCDIR)/,ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c \
	ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
	ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
	ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
	ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
	ft_strtrim.c ft_substring.c ft_tolower.c ft_toupper.c)

BONUS_SRCS = $(addprefix $(BONUSDIR)/,ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
	ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
	ft_lstmap.c)

# Objetos
OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
BONUS_OBJS = $(BONUS_SRCS:$(BONUSDIR)/%.c=$(BONUS_OBJDIR)/%.o)

# === Testes ===
TEST_MAINS = \
	tests/atoi_main.c\
	tests/bzero_main.c\
	tests/calloc_main.c\
	tests/isalpha_main.c\
	tests/isascii_main.c\
	tests/isdigit_main.c\
	tests/isprint_main.c\
	tests/itoa_main.c\
	tests/memchr_main.c\
	tests/memcmp_main.c\
	tests/memcpy_main.c\
	tests/memmove_main.c\
	tests/memset_main.c\
	tests/putchar_fd_main.c\
	tests/putendl_fd_main.c\
	tests/putnbr_fd_main.c\
	tests/putstr_fd_main.c\
	tests/split_main.c\
	tests/strchr_main.c\
	tests/strdup_main.c\
	tests/striteri_main.c\
	tests/strjoin_main.c\
	tests/strlcat_main.c\
	tests/strlcpy_main.c\
	tests/strlen_main.c\
	tests/strmapi_main.c\
	tests/strncmp_main.c\
	tests/strnstr_main.c\
	tests/strrchr_main.c\
	tests/strtrim_main.c\
	tests/substr_main.c\
	tests/tolower_main.c\
	tests/toupper_main.c\

TEST_BONUS_MAINS = \
	tests_bonus/lstadd_back_main.c\
	tests_bonus/lstadd_front_main.c\
	tests_bonus/lstclear_main.c\
	tests_bonus/lstdelone_main.c\
	tests_bonus/lstiter_main.c\
	tests_bonus/lstlast_main.c\
	tests_bonus/lstmap_main.c\
	tests_bonus/lstnew_main.c\
	tests_bonus/lstsize_main.c\

TEST_BINS = $(TEST_MAINS:tests/%_main.c=tests/test_%)
TEST_BONUS_BINS = $(TEST_BONUS_MAINS:tests_bonus/%_main.c=tests_bonus/test_%)

# Regras principais
all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

bonus: $(OBJS) $(BONUS_OBJS)
	ar rcs $(NAME) $^

# Compilação dos .o
$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADER)
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(BONUS_OBJDIR)/%.o: $(BONUSDIR)/%.c $(BONUS_HEADER)
	@mkdir -p $(BONUS_OBJDIR)
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

# === Compilação dos testes ===
test: $(NAME) $(TEST_BINS)

test_bonus: $(NAME) $(TEST_BONUS_BINS)

tests/test_%: tests/%_main.c $(NAME)
	$(CC) $(CFLAGS) -I$(INCDIR) $< $(NAME) -o $@
	@echo "✅ Compilado: $@"

tests_bonus/test_%: tests_bonus/%_main.c $(NAME)
	$(CC) $(CFLAGS) -I$(INCDIR) $< $(NAME) -o $@
	@echo "✅ Compilado (bônus): $@"

# === Rodar todos os testes ===
run_tests: test
	@for bin in $(TEST_BINS); do echo ">> $$bin"; $$bin; echo ""; done

run_bonus: test_bonus
	@for bin in $(TEST_BONUS_BINS); do echo ">> $$bin"; $$bin; echo ""; done

# Limpeza
clean:
	rm -rf $(OBJDIR) $(BONUS_OBJDIR)
	rm -f $(TEST_BINS) $(TEST_BONUS_BINS)

fclean: clean
	rm -f $(NAME)

re: fclean all

# Phony
.PHONY: all bonus clean fclean re test test_bonus run_tests run_bonus
