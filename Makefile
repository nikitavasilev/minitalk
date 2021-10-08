NAME = server
NAME2 = client

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs
RM = rm -f

SRC1 =		./srcs/server.c

SRC2 =		./srcs/client.c

UTILS = 	./utils/ft_putchar_fd.c \
			./utils/ft_putstr_fd.c \
			./utils/ft_putnbr_fd.c

OBJS_SERVER = $(SRC1:.c=.o)

OBJS_CLIENT = $(SRC2:.c=.o)

OBJS = $(UTILS:.c=.o)

all: $(NAME) $(NAME2)

.c.o: $(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS) $(OBJS_SERVER)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS) $(OBJS_SERVER)
	ranlib $(NAME)

$(NAME2): $(OBJS) $(OBJS_SERVER)
	$(AR) $(ARFLAGS) $(NAME2) $(OBJS) $(OBJS_SERVER)
	ranlib $(NAME2)

clean:
	$(RM) $(OBJS) $(OBJS_SERVER) $(OBJS_CLIENT)

fclean:	clean
	$(RM) $(NAME) $(NAME2)

re:	fclean all

.PHONY: bonus all clean fclean re
