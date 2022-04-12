SRCS	=	srcs/errors.c\
			srcs/libft/ft_memcpy.c\
			srcs/libft/ft_split.c\
			srcs/libft/ft_strdup.c\
			srcs/libft/ft_strjoin.c\
			srcs/libft/ft_strlen.c\
			srcs/libft/ft_strnstr.c\
			srcs/libft/ft_substr.c\
			srcs/init.c\
			srcs/main.c

NAME	= pipex

OBJS	= $(SRCS:.c=.o)

OBJS_D	=$(patsubst %.c,%.d,$(SRCS))

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

RM	=	rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@ -MD

include $(wildcard $(OBJS_D))

clean:
	$(RM) $(OBJS) $(OBJS_D)

fclean:	clean
	$(RM) $(NAME)

re: 	fclean all
	
.PHONY: all clean fclean re bonus