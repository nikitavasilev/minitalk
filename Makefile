# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/11 13:58:07 by nvasilev          #+#    #+#              #
#    Updated: 2022/05/30 04:13:32 by nvasilev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJECT_NAME =	minitalk
AUTHOR =		Nikita VASILEV

################################################################################
#                                     CONFIG                                   #
################################################################################

NAME =			server
NAME2 =			client

CC =			cc
CFLAGS =		-Wall -Wextra -Werror -g3
RM =			rm -f

INCLUDES = -I ./includes/

################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRC1 =			./srcs//server/server.c
SRC2 =			./srcs/client/client.c \
				./srcs/client/check_args.c

UTILS =			./utils/ft_putchar_fd.c \
				./utils/ft_putstr_fd.c \
				./utils/ft_putnbr_fd.c \
				./utils/ft_error.c \
				./utils/ft_isdigit.c \
				./utils/ft_atoi.c \
				./utils/ft_putstr_color_fd.c \
				./utils/ft_bzero.c \
				./utils/ft_strlen.c

################################################################################
#                                     OBJECTS                                  #
################################################################################

OBJS_SERVER =	$(SRC1:%.c=%.o)
OBJS_CLIENT =	$(SRC2:%.c=%.o)
OBJS_UTILS =	$(UTILS:%.c=%.o)

################################################################################
#                                     RULES                                    #
################################################################################

all: header $(NAME) $(NAME2)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS_UTILS) $(OBJS_SERVER)
	$(CC) $(OBJS_UTILS) $(OBJS_SERVER) $(INCLUDES) -o $@

$(NAME2): $(OBJS_UTILS) $(OBJS_CLIENT)
	$(CC) $(OBJS_UTILS) $(OBJS_CLIENT) $(INCLUDES) -o $@

bonus: all

clean:
	$(RM) $(OBJS_UTILS) $(OBJS_SERVER) $(OBJS_CLIENT)

fclean:	clean
	$(RM) $(NAME) $(NAME2)

re:	fclean all

.PHONY: bonus all clean fclean re

include header.mk
