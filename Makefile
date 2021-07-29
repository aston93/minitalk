NAME_SERV	= server.out
NAME_CLNT	= client.out
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
SERVER		= server
CLIENT		= client
HEADER_SERV	= $(SERVER)/minitalk_serv.h
HEADER_CLNT	= $(CLIENT)/minitalk_client.h

OBJ_CLIENT = $(CLIENT)/main_client.o $(CLIENT)/utils.o

OBJ_SERVER = $(SERVER)/main_server.o $(SERVER)/utils.o $(SERVER)/serv_handler.o

all: create_libft $(NAME_SERV) $(NAME_CLNT)

$(NAME_SERV): $(OBJ_SERVER) $(HEADER_SERV)
	$(CC) -o $(NAME_SERV) $(OBJ_SERVER) libft/libft.a

$(NAME_CLNT): $(OBJ_CLIENT) $(HEADER_CLNT)
	$(CC) -o $(NAME_CLNT) $(OBJ_CLIENT) libft/libft.a

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

create_libft:
	cd libft && make

clean:
	rm -f $(OBJ_CLIENT) $(OBJ_SERVER)
	@echo "clean done"

fclean: clean
	rm -f $(NAME_SERV) $(NAME_CLNT)
	@echo "fclean done"

re: fclean all
