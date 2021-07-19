/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 16:00:26 by edavid            #+#    #+#             */
/*   Updated: 2021/07/19 10:17:15 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include "ft_display.h"
#include "ft_utils.h"
#include "mlx/mlx.h"
#include "ft_colors.h"

void	connect_points(t_mystruct *mystruct)
{
	int	y;
	int	x;

	y = -1;
	while (++y < mystruct->height)
	{
		x = -1;
		while (++x < mystruct->width - 1)
			line_put_parametric(&mystruct->img,
				(mystruct->screen_pts)[y * mystruct->width + x],
				(mystruct->screen_pts)[y * mystruct->width + x + 1], g_mlx_red);
		x = -1;
		if (y < mystruct->height - 1)
		while (++x < mystruct->width)
			line_put_parametric(&mystruct->img,
				(mystruct->screen_pts)[y * mystruct->width + x],
				(mystruct->screen_pts)[(y + 1) * mystruct->width + x],
				g_mlx_red);
	}
}

static void	calculate_average(t_2d_pointf *average, t_3d_point *Z, int i)
{
	t_2d_pointf	P;

	P = (t_2d_pointf){Z->x * sqrt(3) / 2 + Z->y * -sqrt(3) / 2,
		Z->x * 1 / 2.0 + Z->y * 1 / 2.0 + Z->z};
	if (i < 0)
		return ;
	else if (!i)
		*average = (t_2d_pointf){P.x, P.y};
	else
		*average = (t_2d_pointf){(average->x * i + P.x) / (double)(i + 1),
			(average->y * i + P.y) / (double)(i + 1)};
}

void	draw_map(t_mystruct *mystruct)
{
	int			i;
	int			tmp_mul;
	t_3d_point	Z;
	t_3d_pointf	max;
	t_2d_pointf	average;
	double		zoom_ratio;

	tmp_mul = mystruct->height * mystruct->width;
	i = -1;
	max.x = 0;
	max.y = 0;
	max.z = 0;
	while (++i < tmp_mul)
	{
		Z.x = (mystruct->hyperplane_pts)[i].x;
		Z.y = (mystruct->hyperplane_pts)[i].y;
		Z.z = -(mystruct->hyperplane_pts)[i].z;
		calculate_average(&average, &Z, i);
		if (abs_of(Z.z) > max.z)
			max.z = abs_of(Z.z);
		if (abs_of(Z.x * sqrt(3) / 2 + Z.y * -sqrt(3) / 2) > max.x)
			max.x = abs_of((Z.x * sqrt(3) / 2 + Z.y * -sqrt(3) / 2));
		if (abs_of(Z.x * 1 / 2.0 + Z.y * 1 / 2.0 + Z.z) > max.y)
			max.y = abs_of(Z.x * 1 / 2.0 + Z.y * 1 / 2.0 + Z.z);
	}
	// printf("%f %f %f %f\n", average.x, average.y, max.x, max.y);
	// x should be at 0 before transformation
	// x should be at 0 before transformation
	// apply to every x: x - average.x
	// apply to every y: y - average.y
	max.x -= average.x;
	max.y -= average.y;
	// 
	zoom_ratio = min_of(SCREEN_W / 2.25 / max.x, SCREEN_H / 2.25 / max.y);
	i = -1;
	while (++i < tmp_mul)
	{
		Z.x = (mystruct->hyperplane_pts)[i].x;
		Z.y = (mystruct->hyperplane_pts)[i].y;
		Z.z = -(mystruct->hyperplane_pts)[i].z;
		mystruct->screen_pts[i] = (t_2d_point){((Z.x * sqrt(3) / 2 + Z.y
			* -sqrt(3) / 2) - average.x) * zoom_ratio + SCREEN_W / 2.0,
			((Z.x * 1 / 2.0 + Z.y * 1 / 2.0 + Z.z * 3.0 / max.z) - average.y)
			* zoom_ratio + SCREEN_H / 2.0};
	}
	connect_points(mystruct);
	// origin
	my_mlx_pixel_put(&mystruct->img, SCREEN_W / 2, SCREEN_H / 2, g_mlx_green);
	mlx_put_image_to_window(mystruct->vars.mlx, mystruct->vars.win,
		mystruct->img.img, 0, 0);
}
