/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 17:48:28 by gilq              #+#    #+#             */
/*   Updated: 2021/07/20 13:28:08 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "libft/libft.h"
#include "ft_initialize.h"
#include "ft_view_port.h"
#include "ft_structs.h"
#include "mlx/mlx.h"
#include "ft_utils.h"
#include "ft_colors.h"

static void	initialize_global_vars(void)
{
	g_fElapsedTime = 0.0f;
	g_fThetaX = 0.0f;
	g_fThetaY = 0.0f;
	ft_bzero(&g_matRotZ, sizeof(g_matRotZ));
	ft_bzero(&g_matRotX, sizeof(g_matRotX));
	// Rotation Z
	(g_matRotZ.m)[0][0] = cosf(g_fThetaY);
	(g_matRotZ.m)[0][1] = sinf(g_fThetaY);
	(g_matRotZ.m)[1][0] = -sinf(g_fThetaY);
	(g_matRotZ.m)[1][1] = cosf(g_fThetaY);
	(g_matRotZ.m)[2][2] = 1;
	(g_matRotZ.m)[3][3] = 1;
	// Rotation X
	(g_matRotX.m)[0][0] = 1;
	(g_matRotX.m)[1][1] = cosf(g_fThetaX * 0.5f);
	(g_matRotX.m)[1][2] = sinf(g_fThetaX * 0.5f);
	(g_matRotX.m)[2][1] = -sinf(g_fThetaX * 0.5f);
	(g_matRotX.m)[2][2] = cosf(g_fThetaX * 0.5f);
	(g_matRotX.m)[3][3] = 1;
}

static void	initialize_proj_matr(t_mystruct *mystruct)
{
	float	fNear = 0.1f;
	float	fFar = 100.0f;
	float	fFov = 90.0f;
	// float	fAspectRatio = (float)SCREEN_H / (float)SCREEN_W;
	float	fFovRad = 1.0f / tanf(fFov * 0.5f / 180.0f * 3.14159f);

	ft_bzero(&mystruct->projection_mat, sizeof(mystruct->projection_mat));
	// (mystruct->projection_mat.m)[0][0] = fAspectRatio * fFovRad;
	// (mystruct->projection_mat.m)[1][1] = fFovRad;
	// (mystruct->projection_mat.m)[2][2] = fFar / (fFar - fNear);
	// (mystruct->projection_mat.m)[3][2] = (-fFar * fNear) / (fFar - fNear);
	// (mystruct->projection_mat.m)[2][3] = 1.0f;
	// (mystruct->projection_mat.m)[3][3] = 0.0f;
	(mystruct->projection_mat.m)[0][0] = fFovRad;
	(mystruct->projection_mat.m)[1][1] = fFovRad;
	(mystruct->projection_mat.m)[2][2] = -fFar / (fFar - fNear);
	(mystruct->projection_mat.m)[3][2] = (-fFar * fNear) / (fFar - fNear);
	(mystruct->projection_mat.m)[2][3] = -1.0f;
	(mystruct->projection_mat.m)[3][3] = 0.0f;
}

t_img	get_blank_image(t_mystruct *mystruct)
{
	t_img	blank;
	int		y;
	int		x;

	blank.img = mlx_new_image(mystruct->vars.mlx, SCREEN_W, SCREEN_H);
	blank.addr = mlx_get_img_addr(blank.img, &blank.bpp, &blank.ll, &blank.end);
	y = -1;
	while (++y < SCREEN_H)
	{
		x = -1;
		while (++x < SCREEN_W)
			my_mlx_pixel_put(&blank, x, y, g_mlx_blank);
	}
	return (blank);
}

void    initialize_struct(t_mystruct *mystruct)
{
	ft_bzero(mystruct, sizeof(*mystruct));
    mystruct->vars.mlx = mlx_init();
    mystruct->vars.win = mlx_new_window(mystruct->vars.mlx, SCREEN_W, SCREEN_H, "FpF");
    mystruct->img.img = mlx_new_image(mystruct->vars.mlx, SCREEN_W, SCREEN_H);
    mystruct->img.addr = mlx_get_img_addr(mystruct->img.img,
        &mystruct->img.bpp, &mystruct->img.ll, &mystruct->img.end);
    mystruct->hyperplane = (char **)0;
	mystruct->trigons = (t_tri *)0;
	mystruct->blank_img = get_blank_image(mystruct);
	mystruct->camera_position = (t_3d_pointf){0.0f, 0.0f, 0.0f};
	initialize_proj_matr(mystruct);
	initialize_global_vars();
}
