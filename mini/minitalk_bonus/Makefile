NAME = $(CLIENT_BONUS) $(SERVER_BONUS)

CLIENT_BONUS = client_bonus

SERVER_BONUS = server_bonus

SRCS = client_bonus.c server_bonus.c utils_bonus.c 

OBJS  = $(SRCS:.c=.o)

HEADER  = minitalk_bonus.h

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(SRCS) $(OBJS) $(HEADER)
		@gcc $(CFLAGS) server_bonus.c utils_bonus.c -o $(SERVER_BONUS)
		@gcc $(CFLAGS) client_bonus.c utils_bonus.c -o $(CLIENT_BONUS)
		@echo ------------ready------------



clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf  $(SERVER_BONUS) $(CLIENT_BONUS) $(OBJS)

re: fclean all

.PHONY: all re clean fclean