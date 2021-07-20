/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 16:00:26 by edavid            #+#    #+#             */
/*   Updated: 2021/07/20 17:06:53 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include "libft/libft.h"
#include "ft_display.h"
#include "ft_utils.h"
#include "mlx/mlx.h"
#include "ft_colors.h"
#include "ft_view_port.h"
#include "ft_test_utils.h"

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

static void	calculate_average(t_2d_pointf *average, t_3d_pointf *Z, int i)
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
	t_3d_pointf	Z;
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

void	draw_map2(t_mystruct *mystruct)
{
	int			tmp_mul;
	int			i;
	t_3d_pointf	Z;
	t_3d_pointf	V;
	t_3d_pointf	W;
	t_3d_pointf max_W;
	t_2d_pointf	max_min_Z;
	double		ratio;
	t_2d_pointf	average;

	tmp_mul = mystruct->width * mystruct->height;
	ft_bzero(&max_W, sizeof(t_3d_pointf));
	i = -1;
	while (++i < tmp_mul)
	{
		Z = (t_3d_pointf){
			(mystruct->hyperplane_pts)[i].x,
			(mystruct->hyperplane_pts)[i].y,
			(mystruct->hyperplane_pts)[i].z
		};
		multiply_vec3d_m4x4(&Z, &V, &g_matRotZ, mystruct);
		multiply_vec3d_m4x4(&V, &Z, &g_matRotX, mystruct);
		// printf("%f %f %f\n", Z.x, Z.y, Z.z);
		if (!i)
		{
			max_min_Z.y = Z.z;
			max_min_Z.x = Z.z;
		}
		else
		{
			if (Z.z < max_min_Z.y)
				max_min_Z.y = Z.z;
			if (Z.z > max_min_Z.x)
				max_min_Z.x = Z.z;
		}
	}
	i = -1;
	while (++i < tmp_mul)
	{
		Z = (t_3d_pointf){
			(mystruct->hyperplane_pts)[i].x,
			(mystruct->hyperplane_pts)[i].y,
			(mystruct->hyperplane_pts)[i].z
		};
		// translate all of our points
		if (max_min_Z.y <= 0)
			Z.z += abs_of(max_min_Z.y) + 1.0f;
		// denormalize Z.z
		Z.z *= 2.0 / (max_min_Z.x + abs_of(max_min_Z.y) + 1.0f);
		// printf("o: %f %f %f\n", Z.x, Z.y, Z.z);
		multiply_vec3d_m4x4(&Z, &W, &mystruct->projection_mat, mystruct);
		if (abs_of(W.x) > max_W.x)
			max_W.x = abs_of(W.x);
		if (abs_of(W.y) > max_W.y)
			max_W.y = abs_of(W.y);
		if (abs_of(W.z) > max_W.z)
			max_W.z = abs_of(W.z);
	}
	ratio = max_of(max_W.x, max_W.y);
	i = -1;
	while (++i < tmp_mul)
	{
		Z = (t_3d_pointf){
			(mystruct->hyperplane_pts)[i].x,
			(mystruct->hyperplane_pts)[i].y,
			(mystruct->hyperplane_pts)[i].z
		};
		multiply_vec3d_m4x4(&Z, &W, &mystruct->projection_mat, mystruct);
		// scale them between 0 and 1
		W = (t_3d_pointf){W.x / ratio, W.y / ratio, W.z};
		// scale them up to the size of screen
		// printf("%f %f\n", W.x, W.y);
		W = (t_3d_pointf){W.x * SCREEN_W / 2.0, W.y * SCREEN_H / 2.0, W.z};
		// my_mlx_pixel_put(&mystruct->img, W.x, W.y, g_mlx_green);
		// printf("%f %f\n", W.x, W.y);
		mystruct->screen_pts[i] = (t_2d_point){W.x, W.y};
		calculate_average(&average, &W, i);
	}
	connect_points(mystruct);
	// clear previous screen
	mlx_put_image_to_window(mystruct->vars.mlx, mystruct->vars.win,
		mystruct->blank_img.img, 0, 0);
	mlx_put_image_to_window(mystruct->vars.mlx, mystruct->vars.win,
		mystruct->img.img, SCREEN_W / 2 - W.x, SCREEN_H / 2 - W.y);
}

void	clear_img(t_img *img)
{
	int	y;
	int	x;

	y = -1;
	while (++y < SCREEN_H)
	{
		x = -1;
		while (++x < SCREEN_W)
			my_mlx_pixel_put(img, x, y, g_mlx_blank);
	}
}

// Optimize: Only run the matrix multiplications if there was a corresponding
// button press
void	draw_map3(t_mystruct *mystruct)
{
	int			i;
	t_tri		triProjected;
	t_tri		triTranslated;
	t_tri		vertCamera;
	t_tri		triRotatedZ;
	t_tri		triRotatedZX;
	t_tri2d		tri2d;
	t_mat4x4	worldToCamera;

	// clear previous screen
	clear_img(&mystruct->img);
	worldToCamera = mystruct->projection_mat;
	// worldToCamera.m[3][1] = -10.0f;
	// worldToCamera.m[3][2] = -20.0f;
	worldToCamera.m[3][0] = mystruct->camera_position.x;
	worldToCamera.m[3][1] = mystruct->camera_position.y;
	worldToCamera.m[3][2] = mystruct->camera_position.z;
	i = -1;
	while (++i < mystruct->n_of_trigons)
	{
		vertCamera = *(mystruct->trigons + i);
		// triTranslated = *(mystruct->trigons + i);
		// (triTranslated.p)[0].z += 3.0f;
		// (triTranslated.p)[1].z += 3.0f;
		// (triTranslated.p)[2].z += 3.0f;

		// printf("Z values: %f %f %f\n", vertCamera.p[0].z,
		// 	vertCamera.p[1].z, vertCamera.p[2].z);
		
		// Change camera position
		multiply_vec3d_m4x4(&(vertCamera.p)[0],
			&(triTranslated.p)[0], &worldToCamera, mystruct);
		multiply_vec3d_m4x4(&(vertCamera.p)[1],
			&(triTranslated.p)[1], &worldToCamera, mystruct);
		multiply_vec3d_m4x4(&(vertCamera.p)[2],
			&(triTranslated.p)[2], &worldToCamera, mystruct);

		// printf("Z values: %f %f %f\n", triTranslated.p[0].z,
		// 	triTranslated.p[1].z, triTranslated.p[2].z);
		
		// Rotate Z
		multiply_vec3d_m4x4(&(triTranslated.p)[0],
			&(triRotatedZ.p)[0], &g_matRotZ, mystruct);
		multiply_vec3d_m4x4(&(triTranslated.p)[1],
			&(triRotatedZ.p)[1], &g_matRotZ, mystruct);
		multiply_vec3d_m4x4(&(triTranslated.p)[2],
			&(triRotatedZ.p)[2], &g_matRotZ, mystruct);

		// printf("Z values: %f %f %f\n", triRotatedZ.p[0].z,
		// 	triRotatedZ.p[1].z, triRotatedZ.p[2].z);

		// Rotate X
		multiply_vec3d_m4x4(&(triRotatedZ.p)[0],
			&(triRotatedZX.p)[0], &g_matRotX, mystruct);
		multiply_vec3d_m4x4(&(triRotatedZ.p)[1],
			&(triRotatedZX.p)[1], &g_matRotX, mystruct);
		multiply_vec3d_m4x4(&(triRotatedZ.p)[2],
			&(triRotatedZX.p)[2], &g_matRotX, mystruct);

		// printf("Z values: %f %f %f\n", triRotatedZX.p[0].z,
		// 	triRotatedZX.p[1].z, triRotatedZX.p[2].z);
		
		// Projection matrix
		multiply_vec3d_m4x4(&(triRotatedZX.p)[0],
			&(triProjected.p)[0], &mystruct->projection_mat, mystruct);
		multiply_vec3d_m4x4(&(triRotatedZX.p)[1],
			&(triProjected.p)[1], &mystruct->projection_mat, mystruct);
		multiply_vec3d_m4x4(&(triRotatedZX.p)[2],
			&(triProjected.p)[2], &mystruct->projection_mat, mystruct);

		// printf("Z values: %f %f %f\n", triProjected.p[0].z,
		// 	triProjected.p[1].z, triProjected.p[2].z);

		// If outside of observed space
		if ((triProjected.p)[0].x > 1 || (triProjected.p)[0].x < -1 ||
			(triProjected.p)[0].y > 1 || (triProjected.p)[0].y < -1 ||
			(triProjected.p)[1].x > 1 || (triProjected.p)[0].x < -1 ||
			(triProjected.p)[1].y > 1 || (triProjected.p)[1].y < -1 ||
			(triProjected.p)[2].x > 1 || (triProjected.p)[2].x < -1 ||
			(triProjected.p)[2].y > 1 || (triProjected.p)[2].y < -1)
			continue ;
		// Scale into view
		(triProjected.p)[0].x += 1.0f;
		(triProjected.p)[0].y += 1.0f;
		(triProjected.p)[1].x += 1.0f;
		(triProjected.p)[1].y += 1.0f;
		(triProjected.p)[2].x += 1.0f;
		(triProjected.p)[2].y += 1.0f;
		// printf("%f %f %f %f %f %f\n", (triProjected.p)[0].x, (triProjected.p)[0].y,
		// 	(triProjected.p)[1].x, (triProjected.p)[1].y, (triProjected.p)[2].x,
		// 	(triProjected.p)[2].y);

		(triProjected.p)[0].x *= 0.5f * SCREEN_W;
		// (triProjected.p)[0].y *= 0.5f * SCREEN_H;
		(triProjected.p)[1].x *= 0.5f * SCREEN_W;
		// (triProjected.p)[1].y *= 0.5f * SCREEN_H;
		(triProjected.p)[2].x *= 0.5f * SCREEN_W;
		// (triProjected.p)[2].y *= 0.5f * SCREEN_H;

		(triProjected.p)[0].x = min_of(SCREEN_W - 1, (triProjected.p)[0].x);
		(triProjected.p)[0].y = min_of(SCREEN_H - 1, (1 - (triProjected.p)[0].y * 0.5f) * SCREEN_H);
		(triProjected.p)[1].x = min_of(SCREEN_W - 1, (triProjected.p)[1].x);
		(triProjected.p)[1].y = min_of(SCREEN_H - 1, (1 - (triProjected.p)[1].y * 0.5f) * SCREEN_H);
		(triProjected.p)[2].x = min_of(SCREEN_W - 1, (triProjected.p)[2].x);
		(triProjected.p)[2].y = min_of(SCREEN_H - 1, (1 - (triProjected.p)[2].y * 0.5f) * SCREEN_H);
		
		// printf("*****\nProjected triangles:\n");
		// printf("%d.:\n", i);
		// print_3d_point((triProjected.p)[0]);
		// print_3d_point((triProjected.p)[1]);
		// print_3d_point((triProjected.p)[2]);
		tri2d = (t_tri2d){
			(t_2d_point){(triProjected.p)[0].x, (triProjected.p)[0].y},
			(t_2d_point){(triProjected.p)[1].x, (triProjected.p)[1].y},
			(t_2d_point){(triProjected.p)[2].x, (triProjected.p)[2].y}
		};
		printf("%f %f\n", mystruct->maxima_Z.x, mystruct->maxima_Z.y);
		draw_triangle(mystruct, &tri2d);
		// printf("*****\n");
	}
	shade_triangle(mystruct, &tri2d);
	mlx_put_image_to_window(mystruct->vars.mlx, mystruct->vars.win,
		mystruct->img.img, 0, 0);
}
