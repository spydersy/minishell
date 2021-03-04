# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/25 15:59:29 by abelarif          #+#    #+#              #
#    Updated: 2021/02/25 16:04:48 by abelarif         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=minishell

SRCS=	command_handling.c\
		ft_errors.c\
		import_line.c\
		index_split.c\
		line_handling_utils.c\
		main.c\
		minishell.c\
		./gnl/*.c\
		./libft/*.c\

OBJS=	$(SRCS:.c=.o)

$(NAME):
	