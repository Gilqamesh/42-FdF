/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_shapes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 19:47:11 by edavid            #+#    #+#             */
/*   Updated: 2021/07/20 19:09:05 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ft_utils.h"
#include "ft_colors.h"

// uses parametric equation of line segment
void	line_put_parametric(t_img *data, t_2d_point A, t_2d_point B, int color)
{
	double	t;
	double	increment;

	t = 0;
	increment = 1 / sqrt(pow(abs_of(A.x - B.x), 2) + pow(abs_of(A.y - B.y), 2));
	while (t <= 1)
	{
		my_mlx_pixel_put(data, t * A.x + (1 - t) * B.x, t * A.y + (1 - t) * B.y,
			color);
		t += increment;
	}
}

void	draw_triangle(t_mystruct *mystruct, t_tri *T)
{
	line_put_parametric(&mystruct->img, (t_2d_point){(T->p)[0].x, (T->p)[0].y},
		(t_2d_point){(T->p)[1].x, (T->p)[1].y}, g_mlx_red);
	line_put_parametric(&mystruct->img, (t_2d_point){(T->p)[1].x, (T->p)[1].y},
		(t_2d_point){(T->p)[2].x, (T->p)[2].y}, g_mlx_red);
	line_put_parametric(&mystruct->img, (t_2d_point){(T->p)[2].x, (T->p)[2].y},
		(t_2d_point){(T->p)[0].x, (T->p)[0].y}, g_mlx_red);
}

void	line_put_gradient(t_img *data, t_2d_point A, t_2d_point B,
t_2d_point colors)
{
	double	t;
	double	increment;
	t_rgba	cur_rgba;
	double	cur_red;
	double	cur_green;
	double	cur_blue;
	double	red_inc;
	double	green_inc;
	double	blue_inc;

	t = 0;
	increment = 1 / sqrt(pow(abs_of(A.x - B.x), 2) + pow(abs_of(A.y - B.y), 2));
	cur_red = get_red_from_hex(colors.x);
	cur_green = get_green_from_hex(colors.x);
	cur_blue = get_blue_from_hex(colors.x);
	red_inc = (get_red_from_hex(colors.y) - get_red_from_hex(colors.x)) * increment;
	green_inc = (get_green_from_hex(colors.y) - get_green_from_hex(colors.x)) * increment;
	blue_inc = (get_blue_from_hex(colors.y) - get_blue_from_hex(colors.x)) * increment;
	cur_rgba = hex_to_rgba(colors.x);
	while (t <= 1)
	{
		my_mlx_pixel_put(data, t * B.x + (1 - t) * A.x, t * B.y + (1 - t) * A.y, rgba_to_hex(cur_rgba));
		cur_red += red_inc;
		cur_green += green_inc;
		cur_blue += blue_inc;
		cur_rgba = make_rgba(round_to_nearest(cur_red), round_to_nearest(cur_green),
					round_to_nearest(cur_blue), 0);
		t += increment;
	}
}
