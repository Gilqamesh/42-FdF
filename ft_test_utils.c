/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 18:33:43 by gilq              #+#    #+#             */
/*   Updated: 2021/07/17 18:12:38 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_structs.h"
#include "ft_test_utils.h"

void    print_map(t_mystruct *mystruct)
{
    int 	y;
	char	*str;

    y = -1;
    while (++y < mystruct->height)
    {
        str = *(mystruct->hyperplane + y);
        while (*str)
            printf("%c", *str++);
        printf("\n");
    }
}

void	print_3d_points(t_mystruct *mystruct)
{
	int		x;
	int		mul_tmp;
	t_3d_point	*P;

	printf("Points\n");
	P = mystruct->hyperplane_pts;
	mul_tmp = mystruct->height * mystruct->width;
	x = -1;
	while (++x < mul_tmp)
	{
		printf("%d: %d %d %d\n", x + 1, P->x, P->y, P->z);
		P++;
	}
}
