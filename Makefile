

NAME = push_swap

SRCS		= 	push_swap.c \

OBJS			= $(SRCS:.c=.o)
CC				= clang
FLAGS 			= -g
SANITIZE		= -fsanitize=address

$(NAME) : 		$(OBJS)

all : 			$(NAME)

%.o: %.c
				$(CC) -c $(FLAGS) -o $@ $^

clean :
				/bin/rm -rf $(OBJS)

fclean : clean
				/bin/rm -rf $(NAME)
sanitize : 		$(OBJS)
				./$(NAME) 3 2 1	

re : fclean all
.PHONY			: all clean fclean re