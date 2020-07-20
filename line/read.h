/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 15:40:42 by abelarif          #+#    #+#             */
/*   Updated: 2020/07/18 15:40:43 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_H
#define READ_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "../../libft/libft.h"
#include "get_next_line.h"

typedef struct s_splitpoint t_splitpoint;
typedef	struct s_command t_command;

struct s_splitpoint
{
	char		*long_command;
	t_splitpoint	*next;
};

struct s_command
{
	char		*command;
	t_command	*next;
};

#endif
