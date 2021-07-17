/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 16:00:26 by edavid            #+#    #+#             */
/*   Updated: 2021/07/17 18:46:37 by edavid           ###   ########.fr       */
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

void	draw_map(t_mystruct *mystruct)
{
	int			i;
	int			tmp_mul;
	t_3d_point	Z;
	t_2d_point	max;
	double		zoom_ratio;

	tmp_mul = mystruct->height * mystruct->width;
	i = -1;
	max.x = 0;
	max.y = 0;
	while (++i < tmp_mul)
	{
		Z.x = (mystruct->hyperplane_pts)[i].x;
		Z.y = (mystruct->hyperplane_pts)[i].y;
		Z.z = (mystruct->hyperplane_pts)[i].z;
		if (Z.x * sqrt(3) / 2 + Z.y * -sqrt(3) / 2 > max.x)
			max.x = (Z.x * sqrt(3) / 2 + Z.y * -sqrt(3) / 2);
		if (Z.x * -1 / (double)2 + Z.y * -1 / (double)2 + Z.z > max.y)
			max.y = Z.x * -1 / (double)2 + Z.y * -1 / (double)2 + Z.z;
	}
	zoom_ratio = min_of((SCREEN_W - 50) / 2.0 / max.x,
		(SCREEN_H - 50) / 2.0 / max.y);
	i = -1;
	while (++i < tmp_mul)
	{
		Z.x = (mystruct->hyperplane_pts)[i].x;
		Z.y = (mystruct->hyperplane_pts)[i].y;
		Z.z = (mystruct->hyperplane_pts)[i].z;
		mystruct->screen_pts[i] = (t_2d_point){(Z.x * sqrt(3) / 2 + Z.y
			* -sqrt(3) / 2) * zoom_ratio + SCREEN_W / 2.0, (Z.x * -1 / 2.0
			+ Z.y * -1 / 2.0 + Z.z) * zoom_ratio + SCREEN_H / 2.0};
	}
	connect_points(mystruct);
	// origin
	my_mlx_pixel_put(&mystruct->img, SCREEN_W / 2, SCREEN_H / 2, g_mlx_green);
	mlx_put_image_to_window(mystruct->vars.mlx, mystruct->vars.win,
		mystruct->img.img, 0, 0);
}
