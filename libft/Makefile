# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-ghem <ael-ghem@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/11 18:29:29 by ael-ghem          #+#    #+#              #
#    Updated: 2019/10/23 16:00:09 by ael-ghem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror -c

SRCS = 	ft_atoi.c		\
		ft_bzero.c		\
		ft_isalnum.c	\
		ft_isalpha.c	\
		ft_isascii.c	\
		ft_isdigit.c	\
		ft_isprint.c	\
		ft_memccpy.c	\
		ft_memchr.c		\
		ft_memcmp.c		\
		ft_memcpy.c		\
		ft_memmove.c	\
		ft_memset.c		\
		ft_strchr.c		\
		ft_strlcat.c	\
		ft_strlcpy.c	\
		ft_strlen.c		\
		ft_strncmp.c	\
		ft_strnstr.c	\
		ft_strrchr.c	\
		ft_tolower.c	\
		ft_toupper.c	\
		ft_calloc.c		\
		ft_strdup.c		\
		ft_strjoin.c	\
		ft_strtrim.c	\
		ft_split.c		\
		ft_itoa.c		\
		ft_substr.c		\
		ft_strmapi.c	\
		ft_putchar_fd.c	\
		ft_putstr_fd.c	\
		ft_putendl_fd.c	\
		ft_putnbr_fd.c

BONUS = ft_lstadd_back_bonus.c	\
		ft_lstadd_front_bonus.c	\
		ft_lstclear_bonus.c		\
		ft_lstdelone_bonus.c	\
		ft_lstiter_bonus.c		\
		ft_lstlast_bonus.c		\
		ft_lstnew_bonus.c		\
		ft_lstsize_bonus.c		\
		ft_lstmap_bonus.c

$(NAME):
	gcc $(FLAGS) $(SRCS)
	ar -rc $(NAME) $(SRCS:.c=.o)
	ranlib $(NAME)

all: $(NAME)

clean:
	rm -f *.o

fclean:	clean
	rm -f $(NAME)

re: fclean
	make all

bonus: fclean
	gcc $(FLAGS) $(SRCS) $(BONUS)
	ar -rc $(NAME) $(SRCS:.c=.o) $(BONUS:.c=.o)
	ranlib $(NAME)