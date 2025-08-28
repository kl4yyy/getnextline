CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

NAME = libftprintf.a

SRCS = 
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
