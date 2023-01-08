SERVER	= server
CLIENT	= client
CFLAGS	= -Wall -Wextra -Werror
CC		= cc
SERVER_FILES	=	src_s/server.c
CLIENT_FILES 	= 	src_c/client.c	
RM = 		rm -f
OBJ_C	= $(CLIENT_FILES:%.c=%.o)
OBJ_S	= $(SERVER_FILES:%.c=%.o)

all:  $(SERVER) $(CLIENT)

$(SERVER): $(OBJ_S)
	make -C ./libft
	$(CC) $(CFLAGS) $(OBJ_S) libft/libft.a -o $(SERVER)

$(CLIENT): $(OBJ_C)
	make -C ./libft
	$(CC) $(CFLAGS) $(OBJ_C) libft/libft.a -o $(CLIENT)

clean:
	@make clean -C libft/
	- @$(RM) $(OBJ_S) $(OBJ_C)

fclean: clean
	@make fclean -C libft/
	- @$(RM) ${SERVER} ${CLIENT}

re: fclean all

.PHONY: clean fclean all re client
