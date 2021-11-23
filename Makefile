NAME	=	pipex
SRCS	=	srcs/pipex.c\
			srcs/get_path.c

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
	$(CC) $(FLAGS) -Ilibft -Iincludes -c $< -o $@
$(LIBFT):
	make -C libft
clean:
	make fclean -C libft
	rm -f $(OBJS)
fclean: clean
	rm -f $(LIBFT)
	rm -f $(NAME)
re: fclean all
