/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 18:02:33 by edavid            #+#    #+#             */
/*   Updated: 2021/07/16 19:41:31 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_get_next_line.h"
#include "../libft/libft.h"

int	contains_newline(char *str, size_t n)
{
	size_t	index_of_newline;

	index_of_newline = 0;
	while (index_of_newline < n)
	{
		if (str[index_of_newline] == '\n')
			return ((int)index_of_newline);
		index_of_newline++;
	}
	return (index_of_newline);
}

char 	*ft_strjoin_v3(char **s1, char **s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*new;
	char	*r;
	char	*tmp;

	s1_len = ft_strlen(*s1);
	s2_len = ft_strlen(*s2);
	new = (char *)malloc(s1_len + s2_len + 1);
	if (!new)
		return ((char *)0);
	r = new;
	tmp = *s1;
	while (s1_len--)
		*r++ = *tmp++;
	free(*s1);
	tmp = *s2;
	while (s2_len--)
		*r++ = *tmp++;
	free(*s2);
	*r = '\0';
	return (new);
}

char	*ft_strdup_v2(const char *s, int n)
{
	char	*new;
	char	*r;

	new = (char *)malloc(n + 1);
	if (!new)
		return ((char *)0);
	r = new;
	while (n--)
		*new++ = *s++;
	*new = '\0';
	return (r);
}
