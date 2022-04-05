# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcasale <tcasale@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/04 11:17:43 by tcasale           #+#    #+#              #
#    Updated: 2022/04/05 14:23:26 by tcasale          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME	= push_swap

SRCS	= push_swap.c \
		push_swap_utils.c \
		push_swap_parsing.c \
		push_swap_sort.c \
		push_swap_stack_utils.c \
		push_swap_stack_utils2.c \
		push_swap_debug.c

OBJS	= ${SRCS:.c=.o}

HEADER	= includes

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
RM		= rm -f

%.o: %.c
			${CC} -c ${CFLAGS} -I.libftprintf/libftprintf.a -c $< -o $@

all:	${NAME}

${NAME}:	${OBJS} libftprintf
	${CC} ${OBJS} ./libftprintf/libftprintf.a -o ${NAME}

libftprintf:
	${MAKE} -C ./libftprintf
	cp libftprintf/libftprintf.a ${NAME}

clean:
		${MAKE} -C ./libftprintf $@
		${RM} ${OBJS}

fclean:	clean
		${MAKE} -C ./libftprintf $@
		${RM} ${NAME}

re:	fclean all

.PHONY: all fclean re libftprintf
