/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 17:24:08 by gilq              #+#    #+#             */
/*   Updated: 2021/07/19 09:21:41 by edavid           ###   ########.fr       */
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
		while (++x < mystruct->width)
		{
			while (*str == ' ')
				str++;
			*(mystruct->hyperplane_pts + y * mystruct->width + x) = (t_3d_point){
				x, y, ft_atoi(str)
			};
			while (*str && *str != ' ')
				str++;
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
	mystruct->screen_pts = malloc(mystruct->height * mystruct->width
		* sizeof(*mystruct->screen_pts));
	convert_to_points(mystruct);
}
