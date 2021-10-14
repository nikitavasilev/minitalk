# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/11 13:58:07 by nvasilev          #+#    #+#              #
#    Updated: 2021/10/14 15:53:55 by nvasilev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJECT_NAME =	minitalk
AUTHOR =		Nikita VASILEV

################################################################################
#                                     CONFIG                                   #
################################################################################

NAME =			server
NAME2 =			client

CC =			gcc
CFLAGS =		-Wall -Wextra -Werror
RM =			rm -f

################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRC1 =			./srcs/server.c
SRC2 =			./srcs/client.c

UTILS =			./utils/ft_putchar_fd.c \
				./utils/ft_putstr_fd.c \
				./utils/ft_putnbr_fd.c \
				./utils/ft_error.c

################################################################################
#                                     OBJECTS                                  #
################################################################################

OBJS_SERVER =	$(SRC1:%.c=%.o)
OBJS_CLIENT =	$(SRC2:%.c=%.o)
OBJS =			$(UTILS:%.c=%.o)

################################################################################
#                                     RULES                                    #
################################################################################

all: header $(NAME) $(NAME2)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(OBJS_SERVER)
	$(CC) $(OBJS) $(OBJS_SERVER) -o $@

$(NAME2): $(OBJS) $(OBJS_CLIENT)
	$(CC) $(OBJS) $(OBJS_CLIENT) -o $@

clean:
	$(RM) $(OBJS) $(OBJS_SERVER) $(OBJS_CLIENT)

fclean:	clean
	$(RM) $(NAME) $(NAME2)

re:	fclean all

.PHONY: bonus all clean fclean re

include header.mk
