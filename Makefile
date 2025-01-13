NAME		= libftprintf.a

CFLAGS		= -Wall -Wextra -Werror -Iinclude
ARFLAGS 	= rcs
RM			= rm -rf

BUILD_DIR	= build
VPATH		= src
SRCS		= ft_printf.c ft_putnbr.c ft_putchar.c ft_putstr.c
OBJS		= $(addprefix $(BUILD_DIR)/,$(SRCS:.c=.o))

all: $(NAME)

$(BUILD_DIR):
	mkdir -p $@

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $^ -o $@

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

clean:
	$(RM) $(BUILD_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re