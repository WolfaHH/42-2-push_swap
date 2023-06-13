NAME = push_swap

SRCS		= 	push_swap.c \
				main.c \
				push_swap_combinations2.c \
				push_swap_combinations.c \
				push_swap_merge.c \
				push_swap_utils.c \
				push_swap_utils2.c \
				push_swap_utils3.c \
				main_utils.c \
				main_utils_2.c \
				main_code1.c \
				main_code2.c \
				main_code3.c \
				main_code4.c \
				utils.c \

LIBFT_DIR	= 42-libft-master
LIBFT_SRCS	= $(wildcard $(LIBFT_DIR)/*.c)
LIBFT_OBJS	= $(LIBFT_SRCS:.c=.o)
LIBFT		= libft.a

SRCS_OBJS	= $(SRCS:.c=.o)
OBJS		= $(SRCS_OBJS) $(LIBFT_OBJS)
CC			= clang
FLAGS 		= -g
SANITIZE	= -fsanitize=address

$(NAME) : 		$(LIBFT) $(SRCS_OBJS)
				$(CC) $(FLAGS) -o $@ $(SRCS_OBJS) $(LIBFT)

all : 			$(NAME)

$(LIBFT):		$(LIBFT_OBJS)
				ar rcs $@ $^

%.o: %.c
				$(CC) -c $(FLAGS) -o $@ $^

clean :
				/bin/rm -rf $(OBJS)

fclean : clean
				/bin/rm -rf $(NAME) $(LIBFT)

sanitize : 		$(OBJS)
				./$(NAME) 3 2 1

re : fclean all
.PHONY			: all clean fclean re