/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_view_port.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 18:21:30 by edavid            #+#    #+#             */
/*   Updated: 2021/07/20 11:57:51 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ft_utils.h"
#include "libft/libft.h"
#include "ft_view_port.h"
#include "ft_display.h"

t_mat4x4	g_matRotZ;
t_mat4x4	g_matRotX;
float		g_fTheta;
float		g_fElapsedTime;

void	move_camera_angle(t_mystruct *mystruct, int keycode)
{
	// g_fTheta += 1.0f * g_fElapsedTime;

	// // Rotation Z
	// (g_matRotZ.m)[0][0] = cosf(g_fTheta);
	// (g_matRotZ.m)[0][1] = sinf(g_fTheta);
	// (g_matRotZ.m)[1][0] = -sinf(g_fTheta);
	// (g_matRotZ.m)[1][1] = cosf(g_fTheta);
	// (g_matRotZ.m)[2][2] = 1;
	// (g_matRotZ.m)[3][3] = 1;
	// // Rotation X
	// (g_matRotX.m)[0][0] = 1;
	// (g_matRotX.m)[1][1] = cosf(g_fTheta * 0.5f);
	// (g_matRotX.m)[1][2] = sinf(g_fTheta * 0.5f);
	// (g_matRotX.m)[2][1] = -sinf(g_fTheta * 0.5f);
	// (g_matRotX.m)[2][2] = cosf(g_fTheta * 0.5f);
	// (g_matRotX.m)[3][3] = 1;
	if (keycode == 7)
		mystruct->camera_position.z += 3.0f;
	else if (keycode == 6)
		mystruct->camera_position.z -= 3.0f;
	draw_map3(mystruct);
}

void	move_camera_position(t_mystruct *mystruct, int keycode)
{
	if (keycode == 13)
		mystruct->camera_position.y -= 3.0f;
	else if (keycode == 0)
		mystruct->camera_position.x += 3.0f;
	else if (keycode == 1)
		mystruct->camera_position.y += 3.0f;
	else if (keycode == 2)
		mystruct->camera_position.x -= 3.0f;
	draw_map3(mystruct);
}

void	move_camera_distance(t_mystruct *mystruct, int keycode)
{
	if (keycode == 12)
		mystruct->camera_distance.x += 3.0f;
	else if (keycode == 14)
		mystruct->camera_distance.x -= 3.0f;
	draw_map3(mystruct);
}
