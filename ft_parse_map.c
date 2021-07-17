/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 17:24:08 by gilq              #+#    #+#             */
/*   Updated: 2021/07/17 15:40:48 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "ft_structs.h"
#include "ft_error.h"
#include "gnl/ft_get_next_line.h"
#include "libft/libft.h"
#include "ft_utils.h"

int	extract_number(char **str)
{
	char	*number_str;
	char	*space_pointer;
	int		result;

	if (!str || !*str)
		return (0);
	space_pointer = ft_strchr_v2(*str, ' ');
	number_str = ft_strdup_v2(*str, space_pointer - *str);
	result = ft_atoi(number_str);
	free(number_str);
	if (*space_pointer)
		*str = space_pointer + 1;
	return (result);
}

void	convert_to_points(t_mystruct *mystruct)
{
	int		y;
	int		x;
	char	*str;

	mystruct->hyperplane_pts = malloc(mystruct->height * mystruct->width
		* sizeof(*mystruct->hyperplane_pts));
	y = -1;
	while (++y < mystruct->height)
	{
		str = *(mystruct->hyperplane + y);
		x = -1;
		while(++x < mystruct->width)
		{
			*(mystruct->hyperplane_pts + y * mystruct->width + x) = (t_point){
				x, y, extract_number(&str)
			};
		}
	}
}

static int	count_numbers(char *str)
{
	int	in_a_number;
	int	number_counter;

	in_a_number = 0;
	number_counter = 0;
	if (*str && *str != ' ')
	{
		in_a_number = 1;
		number_counter = 1;	
	}
	while (*str)
	{
		if (in_a_number)
		{
			if (*str == ' ')
				in_a_number = 0;
		}
		else if (*str != ' ')
		{
			in_a_number = 1;
			number_counter++;
		}
		str++;
	}
	return (number_counter);
}

void    parse_map(t_mystruct *mystruct, char **argv)
{
    int     fd;
    char    *line;
    int     cur_line;

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        ft_error("could not open file");
    cur_line = 0;
    if (get_next_line(fd, &line) < 0)
        ft_error("gnl error");
    while (*line != '\0')
    {
        mystruct->hyperplane = ft_realloc(mystruct->hyperplane,
            ++cur_line * sizeof(*mystruct->hyperplane));
        *(mystruct->hyperplane + cur_line - 1) = line;
        if (get_next_line(fd, &line) < 0)
            ft_error("gnl error");
    }
    free(line);
    mystruct->height = cur_line;
	mystruct->width = count_numbers(*mystruct->hyperplane);
	convert_to_points(mystruct);
}
