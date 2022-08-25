# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcasale <tcasale@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/04 11:17:43 by tcasale           #+#    #+#              #
#    Updated: 2022/08/13 14:33:13 by tcasale          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME	= push_swap

SRCS	= $(wildcard srcs/*.c) 

OBJS	= ${SRCS:.c=.o}

HEADER	= includes

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
RM		= rm -f

%.o: %.c
			${CC} -c ${CFLAGS} -I.srcs/libftprintf/libftprintf.a -c $< -o $@

all:	${NAME}

${NAME}:	${OBJS} libftprintf
	${CC} ${OBJS} ./srcs/libftprintf/libftprintf.a -o ${NAME}

libftprintf:
	${MAKE} -C ./srcs/libftprintf
	cp srcs/libftprintf/libftprintf.a ${NAME}

clean:
		${MAKE} -C ./srcs/libftprintf $@
		${RM} ${OBJS}

fclean:	clean
		${MAKE} -C ./srcs/libftprintf $@
		${RM} ${NAME}

re:	fclean all

.PHONY: all fclean re libftprintf
