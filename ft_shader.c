/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 13:31:48 by edavid            #+#    #+#             */
/*   Updated: 2021/07/20 15:30:04 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_utils.h"
#include "ft_colors.h"

// 0 - bottom point, 1 - mid point, 2 - top point of the triangle on 2d plane
static void	sort_tri_by_y(t_tri2d *dst, t_tri2d *src)
{
	if ((*src).p[0].y > (*src).p[1].y)
	{
		if ((*src).p[0].y > (*src).p[2].y)
		{
			(*dst).p[0] = (*src).p[0];
			if ((*src).p[1].y > (*src).p[2].y)
			{
				(*dst).p[1] = (*src).p[1];
				(*dst).p[2] = (*src).p[2];
			}
			else
			{
				(*dst).p[1] = (*src).p[2];
				(*dst).p[2] = (*src).p[1];
			}
		}
		else
		{
			(*dst).p[0] = (*src).p[2];
			(*dst).p[1] = (*src).p[0];
			(*dst).p[2] = (*src).p[1];
		}
	}
	else
	{
		if ((*src).p[1].y > (*src).p[2].y)
		{
			(*dst).p[0] = (*src).p[1];
			if ((*src).p[0].y > (*src).p[2].y)
			{
				(*dst).p[1] = (*src).p[0];
				(*dst).p[2] = (*src).p[2];
			}
			else
			{
				(*dst).p[1] = (*src).p[2];
				(*dst).p[2] = (*src).p[0];
			}
		}
		else
		{
			(*dst).p[0] = (*src).p[2];
			(*dst).p[1] = (*src).p[1];
			(*dst).p[2] = (*src).p[0];
		}
	}
}

// does not work with lines of same slope
static t_2d_point	get_intersection(t_line *f, t_line *g)
{
	t_2d_pointf	f_params;
	t_2d_pointf	g_params;
	int			is_f_vertical;
	int			is_g_vertical;

	// .x is constant, .y is slope, 0.00001f is arbitrary value
	if (abs_of(f->p[0].x - f->p[1].x) < 0.00001f)
		is_f_vertical = 1;
	else
	{
		f_params.y = (f->p[0].y - f->p[1].y) / (float)(f->p[0].x - f->p[1].x);
		f_params.x = f->p[0].y - f->p[0].x * f_params.y;
		is_f_vertical = 0;
	}
	if (abs_of(g->p[0].x - g->p[1].x) < 0.00001f)
		is_g_vertical = 1;
	else
	{
		g_params.y = (g->p[0].y - g->p[1].y) / (float)(g->p[0].x - g->p[1].x);
		g_params.x = g->p[0].y - g->p[0].x * g_params.y;
		is_g_vertical = 0;
	}
	// printf("%d %d, %f %f, %f %f\n", is_f_vertical, is_g_vertical, f_params.x, f_params.y, g_params.x, g_params.y);
	if (!is_f_vertical && !is_g_vertical)
		return ((t_2d_point){(g_params.x - f_params.x)
			/ (f_params.y - g_params.y), (g_params.x - f_params.x)
			/ (f_params.y - g_params.y) * f_params.y + f_params.x});
	if (is_f_vertical)
		return ((t_2d_point){f->p[0].x, g_params.y * f->p[0].x + g_params.x});
	return ((t_2d_point){f->p[1].x, f_params.y * f->p[1].x * f_params.x});
}

void	shade_triangle(t_mystruct *mystruct, t_tri2d *tri2d)
{
	t_tri2d		sorted;
	int			iter_y;
	t_2d_point	Q;
	t_2d_point	P;

	sort_tri_by_y(&sorted, tri2d);
	// printf("sorted: %d %d, %d %d, %d %d\n", sorted.p[0].x, sorted.p[0].y,
	// 	sorted.p[1].x, sorted.p[1].y, sorted.p[2].x, sorted.p[2].y);
	iter_y = sorted.p[2].y;
	// fill the triangle with horizontal lines starting from the top
	// exclude the first and last point to avoid congruence (+ its excessive)
	while (++iter_y < sorted.p[0].y)
	{
		// fill top and bottom part separately
		if (iter_y <= sorted.p[1].y)
		{
			Q = get_intersection(&(t_line){sorted.p[2], sorted.p[0]},
				&(t_line){(t_2d_point){0, iter_y}, (t_2d_point){1, iter_y}});
			P = get_intersection(&(t_line){sorted.p[2], sorted.p[1]},
				&(t_line){(t_2d_point){0, iter_y}, (t_2d_point){1, iter_y}});
			// printf("%d %d, %d %d\n", P.x, P.y, Q.x, Q.y);
			line_put_parametric(&mystruct->img, Q, P, g_mlx_green);
		}
		else
		{
			Q = get_intersection(&(t_line){sorted.p[2], sorted.p[0]},
				&(t_line){(t_2d_point){0, iter_y}, (t_2d_point){1, iter_y}});
			P = get_intersection(&(t_line){sorted.p[1], sorted.p[0]},
				&(t_line){(t_2d_point){0, iter_y}, (t_2d_point){1, iter_y}});
			// printf("%d %d, %d %d\n", P.x, P.y, Q.x, Q.y);
			line_put_parametric(&mystruct->img, Q, P, g_mlx_green);
		}
	}
}
