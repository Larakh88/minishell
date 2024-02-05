# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile                                           :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: lel-khou <marvin@42.fr>                    +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2021/10/02 11:08:57 by lel-khou          #+#    #+#             #
#   Updated: 2021/10/15 17:02:29 by lel-khou         ###   ########.fr       #
#                                                                            #
# ************************************************************************** #

CC	= gcc

CFLAGS	= -g -Wall -Wextra -Werror

HEADER	= libft.h

NAME	= libft.a

RM	= rm -f

CFILES	= ft_isascii.c ft_isprint.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
			ft_tolower.c ft_toupper.c ft_strlen.c ft_strlcpy.c ft_strlcat.c \
			ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c \
			ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strcmp.c \
			ft_memchr.c ft_memcmp.c ft_strdup.c ft_calloc.c ft_itoa.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_strmapi.c ft_striteri.c

BONUS	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
		  ft_lstdelone.c ft_lstclear.c ft_lstiter.c

OBJS	= $(CFILES:.c=.o)

BOBJS	= $(BONUS:.c=.o)

all	: $(NAME)

$(NAME)	: $(OBJS) $(HEADER)
	ar -rcs	$(NAME) $(OBJS)
	ranlib $(NAME)

bonus	: $(NAME) $(BOBJS)
	ar -rcs $(NAME) $(BOBJS)
	ranlib $(NAME)

%.o	: %.c
	$(CC) $(CFLAGS) -c $<
clean	:
	$(RM) $(OBJS) $(BOBJS)

fclean	: clean
	$(RM) $(NAME)

re	: fclean all
