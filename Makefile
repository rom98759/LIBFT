# =============================================================================
#	🌟 GENERAL CONFIG & FLAGS 🌟
# =============================================================================

# Program for compiling C programs
CC := cc
CFLAGS := -Wall -Wextra -Werror
INCLUDES := -I./includes

NAME := libft.a

# =============================================================================
#	📂 SOURCES & OBJECTS 📂
# =============================================================================

OBJ_PATH := ./objs

SRCS_LIBFT := libft/ft_calloc.c libft/ft_bzero.c libft/ft_memchr.c libft/ft_memcmp.c libft/ft_memcpy.c libft/ft_memmove.c libft/ft_memset.c \
	libft/ft_atoi.c libft/ft_itoa.c libft/ft_strdup.c libft/ft_split.c libft/ft_strchr.c libft/ft_strjoin.c libft/ft_strlcat.c libft/ft_strlcpy.c \
	libft/ft_strlen.c libft/ft_strncmp.c libft/ft_strnstr.c libft/ft_strrchr.c libft/ft_strtrim.c libft/ft_strmapi.c libft/ft_substr.c \
	libft/ft_isalnum.c libft/ft_isalpha.c libft/ft_isascii.c libft/ft_isdigit.c libft/ft_isprint.c libft/ft_tolower.c libft/ft_toupper.c \
	libft/ft_putchar_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c libft/ft_putstr_fd.c libft/ft_striteri.c libft/ft_lstnew.c \
	libft/ft_lstadd_front.c libft/ft_lstsize.c libft/ft_lstlast.c libft/ft_lstadd_back.c libft/ft_lstdelone.c libft/ft_lstclear.c \
	libft/ft_lstiter.c libft/ft_lstmap.c

SRCS_PRINTF := pr_printf/pr_itoa.c pr_printf/pr_print_char.c pr_printf/pr_print_hex.c pr_printf/pr_print_int.c pr_printf/pr_print_pointer.c \
	pr_printf/pr_print_str.c pr_printf/pr_print_unsigned.c pr_printf/pr_printf.c pr_printf/pr_miscellaneous.c

SRCS_GNL := gnl/get_next_line.c gnl/get_next_line_utils.c

SRCS := $(SRCS_LIBFT) $(SRCS_PRINTF) $(SRCS_GNL)

OBJS_LIBFT := $(addprefix $(OBJ_PATH)/, $(SRCS_LIBFT:.c=.o))
OBJS_PRINTF := $(addprefix $(OBJ_PATH)/, $(SRCS_PRINTF:.c=.o))
OBJS_GNL := $(addprefix $(OBJ_PATH)/, $(SRCS_GNL:.c=.o))

OBJS := $(OBJS_LIBFT) $(OBJS_PRINTF) $(OBJS_GNL)

# =============================================================================
#	📊 PROGRESS BAR CONFIG 📊
# =============================================================================

BAR_LENGTH := 50
TOTAL_FILES := $(words $(SRCS))
COMPILED_FILES := 0

define progress_bar
	$(eval COMPILED_FILES=$(shell echo $$(($(COMPILED_FILES) + 1))))
	$(eval PROGRESS_PERCENT=$(shell echo $$(($(COMPILED_FILES) * 100 / $(TOTAL_FILES)))))
	$(eval FILLED_BAR_LENGTH=$(shell echo $$(($(PROGRESS_PERCENT) * $(BAR_LENGTH) / 100))))
	@printf "\rCompiling [\033[0;32m"
	@for i in $(shell seq 1 $(FILLED_BAR_LENGTH)); do printf "#"; done
	@for i in $(shell seq 1 $(shell echo $$(($(BAR_LENGTH) - $(FILLED_BAR_LENGTH))))); do printf " "; done
	@printf "\033[0m] $(PROGRESS_PERCENT)%%"
endef

# =============================================================================
#	🏗️ RULES 🏗️
# =============================================================================

all: $(NAME)
	@echo "\n🎉 $(NAME) built successfully!"

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "\n🚀 $(NAME) library created!"

$(OBJ_PATH)/%.o: %.c
	@mkdir -p $(dir $@)
	$(call progress_bar)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# -----------------------------------------------------------------------------
# RULES FOR SPECIFIC PARTS
# -----------------------------------------------------------------------------

libft: $(OBJS_LIBFT)
	@ar rc $(NAME) $(OBJS_LIBFT)
	@ranlib $(NAME)
	@echo "📚 libft part built!"

printf: $(OBJS_PRINTF)
	@ar rc $(NAME) $(OBJS_PRINTF)
	@ranlib $(NAME)
	@echo "🖨️ printf part built!"

gnl: $(OBJS_GNL)
	@ar rc $(NAME) $(OBJS_GNL)
	@ranlib $(NAME)
	@echo "📜 gnl part built!"

# -----------------------------------------------------------------------------
# CLEANING RULES
# -----------------------------------------------------------------------------

clean:
	@rm -rf $(OBJ_PATH)
	@echo "🧹 Object files cleaned!"

fclean: clean
	@rm -f $(NAME)
	@echo "💥 $(NAME) removed!"

re: fclean all
	@echo "🔄 Rebuilding $(NAME)..."

# =============================================================================
# 💼 PHONY RULES 💼
# =============================================================================

.PHONY: all clean fclean re
