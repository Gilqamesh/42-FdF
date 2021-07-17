/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 16:00:26 by edavid            #+#    #+#             */
/*   Updated: 2021/07/17 17:17:14 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include "ft_display.h"
#include "ft_utils.h"
#include "mlx/mlx.h"
#include "ft_colors.h"
#define ZOOM 20 // figure out a good value for this automatically to fill up the screen

void	display_points(t_mystruct *mystruct)
{
	int	i;
	int	tmp_mul;
	int	x;
	int	y;
	int	z;

	tmp_mul = mystruct->height * mystruct->width;
	i = -1;
	while (++i < tmp_mul)
	{
		x = mystruct->hyperplane_pts[i].x;
		y = mystruct->hyperplane_pts[i].y;
		z = mystruct->hyperplane_pts[i].z;
		printf("%d %d %d %f %f\n", x, y, z, (x * sqrt(3) / 2 + y * -sqrt(3) / 2) * ZOOM,
			(x * -1 / (double)2 + y * -1 / (double)2 + z) * ZOOM);
		my_mlx_pixel_put(&mystruct->img,
		(x * sqrt(3) / 2 + y * -sqrt(3) / 2) * ZOOM + SCREEN_W / 2,
		(x * -1 / (double)2 + y * -1 / (double)2 + z) * ZOOM + SCREEN_H / 2,
		g_mlx_red);
	}
	// origin
	my_mlx_pixel_put(&mystruct->img, SCREEN_W / 2, SCREEN_H / 2, g_mlx_green);
	mlx_put_image_to_window(mystruct->vars.mlx, mystruct->vars.win,
		mystruct->img.img, 0, 0);
}
