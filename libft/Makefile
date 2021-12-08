# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ivork <ivork@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/05 12:53:39 by ivork         #+#    #+#                  #
#    Updated: 2021/10/19 19:28:15 by ivork         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
SRCS	=	ft_memset.c\
			ft_bzero.c\
			ft_memcpy.c\
			ft_memccpy.c\
			ft_memmove.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_strlen.c\
			ft_strlcpy.c\
			ft_strlcat.c\
			ft_strchr.c\
			ft_strrchr.c\
			ft_strnstr.c\
			ft_strncmp.c\
			ft_atod.c\
			ft_atoi.c\
			ft_isalpha.c\
			ft_isdigit.c\
			ft_isalnum.c\
			ft_isascii.c\
			ft_isprint.c\
			ft_toupper.c\
			ft_tolower.c\
			ft_calloc.c\
			ft_strdup.c\
			ft_substr.c\
			ft_strjoin.c\
			ft_strtrim.c\
			ft_split.c\
			ft_itoa.c\
			ft_strmapi.c\
			ft_putchar_fd.c\
			ft_putstr_fd.c\
			ft_putendl_fd.c\
			ft_putnbr_fd.c\
			get_next_line/get_next_line.c\
			get_next_line/get_next_line_utils.c\
			ft_printf/ft_printf.c			\
			ft_printf/ft_printf_utils.c	\
			ft_printf/ft_print_char.c		\
			ft_printf/ft_print_num.c		\
			ft_printf/ft_print_pos.c		\
			ft_printf/ft_print_neg.c		\
			ft_printf/ft_print_point.c

SRCS_B	=	ft_lstnew.c\
			ft_lstadd_front.c\
			ft_lstsize.c\
			ft_lstlast.c\
			ft_lstadd_back.c\
			ft_lstdelone.c\
			ft_lstclear.c\
			ft_lstiter.c\
			ft_lstmap.c

OBJS	=	$(SRCS:.c=.o)
OBJS_B	=	$(SRCS_B:.c=.o)
LIBC	=	ar -rcs
RM		=	rm -f
CC		=	gcc
FLAGS	=	-Wall -Werror -Wextra
INCS	=	.

RELEVANT_OBJS = $(OBJS) $(OBJS_B)

all:		$(NAME)

$(NAME):	$(RELEVANT_OBJS)
			${LIBC} $(NAME) $(RELEVANT_OBJS)

.c.o:
			${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I${INCS}

bonus:
			$(MAKE) WITH_BONUS=1 all

clean:
			${RM} $(OBJS) $(OBJS_B)

fclean:     clean
			${RM} $(NAME)

re:			fclean all

.PHONY:		all .c.o clean fclean re
