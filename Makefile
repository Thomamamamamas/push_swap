# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcasale <tcasale@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/04 11:17:43 by tcasale           #+#    #+#              #
#    Updated: 2022/07/08 17:12:59 by tcasale          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME	= push_swap

SRCS	= $(wildcard *.c) 

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
