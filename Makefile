NAME	=	pipex
SRCS_R	=	srcs/pipex.c\
			srcs/get_path.c
SRCS_B	=	srcs/pipex_bonus.c\
			srcs/get_path.c
OBJS_R	=	$(SRCS_R:.c=.o)
OBJS_B	=	$(SRCS_B:.c=.o)
CC		=	gcc
FLAGS	=	-Wall -Werror -Wextra
LIBFT	=	libft/libft.a

ifdef BONUS
OBJS = $(OBJS_B)
else
OBJS = $(OBJS_R)
endif

all:		$(NAME)
$(NAME):	$(LIBFT) $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)
bonus:
	$(MAKE) BONUS=1 re
$(LIBFT):
	Make -C libft
%.o: %.c
	$(CC) $(FLAGS) -Ilibft -Iincludes -c $< -o $@
clean:
	make fclean -C libft
	rm -f $(OBJS_R)
	rm -f $(OBJS_B)
fclean: clean
	rm -f $(LIBFT)
	rm -f $(NAME)
re: fclean all
