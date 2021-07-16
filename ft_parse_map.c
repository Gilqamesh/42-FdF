/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilq <gilq@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 17:24:08 by gilq              #+#    #+#             */
/*   Updated: 2021/07/16 18:45:49 by gilq             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include "ft_structs.h"
#include "ft_error.h"
#include "gnl/ft_get_next_line.h"
#include "libft/libft.h"
#include "ft_utils.h"

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
        free(line);
        get_next_line(fd, &line);
        if (get_next_line(fd, &line) < 0)
            ft_error("gnl error");
    }
    free(line);
    mystruct->width = ft_strlen(*(mystruct->hyperplane
        + cur_line - 1)) / 2 + 1;
    mystruct->height = cur_line;
}
