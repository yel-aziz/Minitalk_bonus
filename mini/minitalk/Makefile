NAME = $(CLIENT) $(SERVER)

CLIENT = client

SERVER = server

SRCS = client.c server.c utils.c 

OBJS  = $(SRCS:.c=.o)

HEADER  = minitalk.h

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(SRCS) $(OBJS) $(HEADER)
		@gcc $(CFLAGS) server.c utils.c -o $(SERVER)
		@gcc $(CFLAGS) client.c utils.c -o $(CLIENT)
		@echo ------------ready------------



clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf  $(SERVER) $(CLIENT) $(OBJS)

re: fclean all

.PHONY: all re clean fclean