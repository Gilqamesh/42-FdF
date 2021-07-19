/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 17:48:28 by gilq              #+#    #+#             */
/*   Updated: 2021/07/19 11:39:23 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "ft_initialize.h"
#include "mlx/mlx.h"

static void	initialize_proj_matr(t_mystruct *mystruct)
{
	float	fNear = 0.1f;
	float	fFar = 1000.0f;
	float	fFov = 90.0f;
	float	fAspectRatio = (float)SCREEN_H / (float)SCREEN_W;
	float	fFovRad = 1.0f / tanf(fFov * 0.5f / 180.0f * 3.14159f);

	(mystruct->projection_mat.m)[0][0] = fAspectRatio * fFovRad;
	(mystruct->projection_mat.m)[1][1] = fFovRad;
	(mystruct->projection_mat.m)[2][2] = fFar / (fFar - fNear);
	(mystruct->projection_mat.m)[3][2] = (-fFar * fNear) / (fFar - fNear);
	(mystruct->projection_mat.m)[2][3] = 1.0f;
	(mystruct->projection_mat.m)[3][3] = 0.0f;
}

void    initialize_struct(t_mystruct *mystruct)
{
    mystruct->vars.mlx = mlx_init();
    mystruct->vars.win = mlx_new_window(mystruct->vars.mlx, SCREEN_W, SCREEN_H, "FpF");
    mystruct->img.img = mlx_new_image(mystruct->vars.mlx, SCREEN_W, SCREEN_H);
    mystruct->img.addr = mlx_get_img_addr(mystruct->img.img,
        &mystruct->img.bpp, &mystruct->img.ll, &mystruct->img.end);
    mystruct->hyperplane = (char **)0;
	initialize_proj_matr(mystruct);
}
