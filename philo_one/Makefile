NAME			= philo_one.out

CC				= clang
CFLAGS			= -Wall -Wextra -Werror -pthread

SRCS_DIR		= srcs
SRCS_FILES		= init.c main.c utils.c simulation.c
SRCS			= $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))

OBJS_DIR		= objs
OBJS_FILES		= $(SRCS_FILES:.c=.o)
OBJS			= $(addprefix $(OBJS_DIR)/, $(OBJS_FILES))

HEADERS_DIR		= includes
HEADERS_FILES	= philo_one.h
HEADERS			= $(addprefix $(HEADERS_DIR)/, $(HEADERS_FILES))

all: $(NAME)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADERS) | $(OBJS_DIR)
	$(CC) $(CFLAGS) -I $(HEADERS_DIR) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re