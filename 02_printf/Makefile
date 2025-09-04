# Library name
NAME		= libftprintf.a

# Directories
SRC_DIR		= src
OBJ_DIR		= objects
INC_DIR		= include
LIBFT_DIR	= libft
LIBFT_INC	= $(LIBFT_DIR)/include
LIBFT_LIB	= $(LIBFT_DIR)/libft.a

# Compiler and flags
CC			= cc
CFLAGS			= -Wall -Wextra -Werror
AR			= ar rcs
RM			= rm -rf

# Include paths
INCLUDES	= -I$(INC_DIR) -I$(LIBFT_INC)

# Source files by category
FORMATTER_SRC	= ft_flags.c \
				  ft_format_output.c \
				  ft_parser.c \
				  ft_precision_num.c \
				  ft_precision_str.c

SPECIFIERS_SRC	= ft_handle_char.c \
				  ft_handle_decimal.c \
				  ft_handle_hex.c \
				  ft_handle_integer.c \
				  ft_handle_percent.c \
				  ft_handle_pointer.c \
				  ft_handle_string.c \
				  ft_handle_unsigned.c

UTILS_SRC		= ft_buffer.c \
				  ft_dispatch_specifier.c \
				  ft_format_utils.c

# Main source files
MAIN_SRC		= ft_printf.c
BONUS_SRC		= ft_printf_bonus.c

# Full source paths
FORMATTER_SRCS	= $(addprefix $(SRC_DIR)/formatter/, $(FORMATTER_SRC))
SPECIFIERS_SRCS	= $(addprefix $(SRC_DIR)/specifiers/, $(SPECIFIERS_SRC))
UTILS_SRCS		= $(addprefix $(SRC_DIR)/utils/, $(UTILS_SRC))
MAIN_SRCS		= $(addprefix $(SRC_DIR)/, $(MAIN_SRC))
BONUS_SRCS		= $(addprefix $(SRC_DIR)/, $(BONUS_SRC))

# All sources (without bonus)
SRCS = $(FORMATTER_SRCS) $(SPECIFIERS_SRCS) $(UTILS_SRCS) $(MAIN_SRCS)

# All sources (with bonus)
SRCS_BONUS = $(FORMATTER_SRCS) $(SPECIFIERS_SRCS) $(UTILS_SRCS) $(BONUS_SRCS)

# Object files
FORMATTER_OBJS	= $(addprefix $(OBJ_DIR)/formatter/, $(FORMATTER_SRC:.c=.o))
SPECIFIERS_OBJS	= $(addprefix $(OBJ_DIR)/specifiers/, $(SPECIFIERS_SRC:.c=.o))
UTILS_OBJS		= $(addprefix $(OBJ_DIR)/utils/, $(UTILS_SRC:.c=.o))
MAIN_OBJS		= $(addprefix $(OBJ_DIR)/, $(MAIN_SRC:.c=.o))
BONUS_OBJS		= $(addprefix $(OBJ_DIR)/, $(BONUS_SRC:.c=.o))

# All objects (without bonus)
OBJS = $(FORMATTER_OBJS) $(SPECIFIERS_OBJS) $(UTILS_OBJS) $(MAIN_OBJS)

# All objects (with bonus)
OBJS_BONUS = $(FORMATTER_OBJS) $(SPECIFIERS_OBJS) $(UTILS_OBJS) $(BONUS_OBJS)

# Colors for output
GREEN	= \033[0;32m
YELLOW	= \033[0;33m
RED	= \033[0;31m
BLUE	= \033[0;34m
NC	= \033[0m

# Default target
all: $(NAME)

# Create library (mandatory)
$(NAME): $(LIBFT_LIB) $(OBJS)
	@echo "$(YELLOW)Creating ft_printf library $(NAME)...$(NC)"
	@cp $(LIBFT_LIB) $(NAME)
	@$(AR) $(NAME) $(OBJS)
	@echo "$(GREEN)Library $(NAME) created successfully!$(NC)"

# Create library with bonus
bonus: $(NAME)

# Build libft
$(LIBFT_LIB):
	@echo "$(BLUE)Building libft...$(NC)"
	@$(MAKE) -C $(LIBFT_DIR)
	@echo "$(GREEN)Libft built successfully!$(NC)"

# Create object directories
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/formatter
	@mkdir -p $(OBJ_DIR)/specifiers
	@mkdir -p $(OBJ_DIR)/utils

# Compile object files by category
$(OBJ_DIR)/formatter/%.o: $(SRC_DIR)/formatter/%.c | $(OBJ_DIR)
	@echo "$(YELLOW)Compiling $<...$(NC)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/specifiers/%.o: $(SRC_DIR)/specifiers/%.c | $(OBJ_DIR)
	@echo "$(YELLOW)Compiling $<...$(NC)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/utils/%.o: $(SRC_DIR)/utils/%.c | $(OBJ_DIR)
	@echo "$(YELLOW)Compiling $<...$(NC)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "$(YELLOW)Compiling $<...$(NC)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean object files and directories
clean:
	@echo "$(RED)Cleaning ft_printf object files...$(NC)"
	@$(RM) $(OBJ_DIR)
	@$(RM) .bonus_done
	@echo "$(BLUE)Cleaning libft...$(NC)"
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "$(GREEN)Object files cleaned!$(NC)"

# Clean everything
fclean: clean
	@echo "$(RED)Cleaning ft_printf library...$(NC)"
	@$(RM) $(NAME)
	@echo "$(BLUE)Cleaning libft library...$(NC)"
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "$(GREEN)Everything cleaned!$(NC)"

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all bonus clean fclean re
