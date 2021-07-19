/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_shapes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 19:47:11 by edavid            #+#    #+#             */
/*   Updated: 2021/07/19 20:12:01 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include "ft_colors.h"
#include <math.h>

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

void	draw_triangle(t_mystruct *mystruct, t_tri2d *T)
{
	line_put_parametric(&mystruct->img, (t_2d_point){(T->p)[0].x, (T->p)[0].y},
		(t_2d_point){(T->p)[1].x, (T->p)[1].y}, g_mlx_red);
	line_put_parametric(&mystruct->img, (t_2d_point){(T->p)[1].x, (T->p)[1].y},
		(t_2d_point){(T->p)[2].x, (T->p)[2].y}, g_mlx_red);
	line_put_parametric(&mystruct->img, (t_2d_point){(T->p)[2].x, (T->p)[2].y},
		(t_2d_point){(T->p)[0].x, (T->p)[0].y}, g_mlx_red);
}
