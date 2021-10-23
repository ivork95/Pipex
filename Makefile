NAME	=	pipex
SRCS	=	srcs/pipex.c

OBJS	=	$(SRCS:.c=.o)
CC		=	gcc
FLAGS	=	-Wall -Werror -Wextra
LIBFT	=	libft/libft.a

all:		$(NAME)
$(NAME):	$(LIBFT) $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)
$(LIBFT):
	Make -C libft
%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@
$(LIBFT):
	make -C libft
clean:
	make fclean -C libft
	rm -f $(OBJS_PS) $(OBJS_C)
fclean: clean
	rm -f $(LIBFT)
	rm -f $(NAME)
re: fclean all
