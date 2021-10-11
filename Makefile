# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/11 13:58:07 by nvasilev          #+#    #+#              #
#    Updated: 2021/10/11 14:14:37 by nvasilev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJECT_NAME =	minitalk
AUTHOR =				Nikita VASILEV

################################################################################
#                                     CONFIG                                   #
################################################################################

NAME =		server
NAME2 =		client

CC =			gcc
CFLAGS =	-Wall -Wextra -Werror
AR =			ar
ARFLAGS =	rcs
RM =			rm -f

RED_COLOR =			\033[0;31m
RESET_COLOR =		\033[0m
BLUE_COLOR =		\033[0;36m
ORANGE_COLOR =	\033[0;33m

################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRC1 =	./srcs/server.c
SRC2 =	./srcs/client.c

UTILS =	./utils/ft_putchar_fd.c \
				./utils/ft_putstr_fd.c \
				./utils/ft_putnbr_fd.c

################################################################################
#                                     OBJECTS                                  #
################################################################################

OBJS_SERVER =	$(SRC1:.c=.o)
OBJS_CLIENT =	$(SRC2:.c=.o)
OBJS =				$(UTILS:.c=.o)

################################################################################
#                                     RULES                                    #
################################################################################

all: header $(NAME) $(NAME2)

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

header:
	@printf "%b" "$(RED_COLOR)"
	@echo
	@echo "                      _ _            "
	@echo "Made by              (_) |           "
	@echo "  _ ____   ____ _ ___ _| | _____   __"
	@echo " | '_ \ \ / / _\` / __| | |/ _ \ \ / /"
	@echo " | | | \ V / (_| \__ \ | |  __/\ V / "
	@echo " |_| |_|\_/ \__,_|___/_|_|\___| \_/   for"
	@echo
	@echo ".....%%...%%%%...........%%%%%....%%%%...%%%%%...%%%%%%...%%%%.."
	@echo ".%%..%%......%%..........%%..%%..%%..%%..%%..%%....%%....%%....."
	@echo ".%%%%%%...%%%%...........%%%%%...%%%%%%..%%%%%.....%%.....%%%%.."
	@echo ".....%%..%%..............%%......%%..%%..%%..%%....%%........%%."
	@echo ".....%%..%%%%%%..........%%......%%..%%..%%..%%..%%%%%%...%%%%.."
	@echo "................................................................"
	@echo
	@printf "%b" "$(BLUE_COLOR)Name:	$(ORANGE_COLOR)$(PROJECT_NAME)\n"
	@printf "%b" "$(BLUE_COLOR)Author:	$(ORANGE_COLOR)$(AUTHOR)\n\n"
	@printf "%b" "$(RESET_COLOR)"