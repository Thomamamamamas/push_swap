# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcasale <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/13 14:52:20 by tcasale           #+#    #+#              #
#    Updated: 2022/03/28 12:25:47 by tcasale          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRCS	= ft_atoi.c \
ft_bzero.c \
ft_calloc.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c \
ft_itoa.c \
ft_memchr.c \
ft_memcmp.c \
ft_memcpy.c \
ft_memmove.c \
ft_memset.c \
ft_putchar_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_putstr_fd.c \
ft_split.c \
ft_strchr.c \
ft_strcmp.c \
ft_strdup.c \
ft_striteri.c \
ft_strjoin.c \
ft_strlcat.c \
ft_strlcpy.c \
ft_strlen.c \
ft_strmapi.c \
ft_strncmp.c \
ft_strnstr.c \
ft_strrchr.c \
ft_strtrim.c \
ft_substr.c \
ft_tolower.c \
ft_toupper.c \

BONUS	= ft_lstadd_back.c \
ft_lstadd_front.c \
ft_lstclear.c \
ft_lstdelone.c \
ft_lstiter.c \
ft_lstlast.c \
ft_lstmap.c \
ft_lstnew.c \
ft_lstsize.c 

SUPP	= ft_putchar.c \
ft_putstr.c \
ft_putnbr.c \
ft_putnbr_unsigned.c \
ft_putadress.c \
ft_puthexa_upper.c \
ft_puthexa_lower.c \
ft_itoa_base.c \
ft_itoa_unsigned.c \
ft_itoa_adress.c

OBJS	= ${SRCS:.c=.o}
OBJS_BONUS = ${BONUS:.c=.o}
OBJS_SUPP = ${SUPP:.c=.o}

HEADER	= includes

CC		= gcc
RM		= rm -f
AR		= ar rcs

CFLAGS = -Wall -Wextra -Werror

%.o: %.c
			${CC} -c ${CFLAGS} -o $@ $<

all: $(NAME)

$(NAME):	$(OBJS) $(OBJS_SUPP)
			$(AR) $@ $^

bonus:	$(OBJS) ${OBJS_BONUS} $(OBJS_SUPP) 
			$(AR) ${NAME} $^

clean:
		${RM} ${OBJS} ${OBJS_BONUS} ${OBJS_SUPP}

fclean:	clean
		${RM} ${NAME}

re: fclean all

.PHONY:	all clean fclean bonus re
