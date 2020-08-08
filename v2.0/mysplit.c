/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mysplit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 11:57:39 by abelarif          #+#    #+#             */
/*   Updated: 2020/08/07 12:09:31 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static  size_t          len_word(const char *s, char c, char d)
{
        size_t  i;
        size_t  len;

        i = 0;
        len = 0;
        while (s[i] == c || s[i] == d)
                i++;
        while (s[i] != c && s[i] != d &&  s[i++])
                len++;
        return (len);
}

static  size_t          count_word(const char *s, char c, char d)
{
        size_t  i;
        size_t  count;

        i = 0;
        count = 0;
        while (s[i])
        {
                if (s[i] != c && s[i] != d)
                        count++;
                while (s[i] != c && s[i] != d && s[i + 1])
                        i++;
                i++;
        }
        return (count);
}

void                            *free_split(char **split, int k)
{
        while (k >= 0)
        {
                free(split[k]);
                k--;
        }
        free(split);
        split = NULL;
        return (NULL);
}

char                            **mysplit(char const *s, char c, char d)
{
        size_t  i;
        size_t  j;
        size_t  k;
        char    **split;

        i = 0;
        k = 0;
        if (!s || !(split = (char **)malloc(sizeof(char *)
                                        * (count_word(s, c, d) + 1))))
                return (NULL);
        while (i < count_word(s, c, d))
        {
                if (!(split[i] = (char *)malloc(sizeof(char)
                                                * (len_word(&s[k], c, d) + 1))))
                        return ((free_split(split, k - 1)));
                j = 0;
                while (s[k] == c || s[k] == d)
                        k++;
                while (s[k] != c && s[k] != d && s[k])
                        split[i][j++] = s[k++];
                split[i][j] = '\0';
                i++;
        }
        split[i] = NULL;
        return (split);
}