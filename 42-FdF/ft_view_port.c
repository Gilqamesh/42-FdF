/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_view_port.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 18:21:30 by edavid            #+#    #+#             */
/*   Updated: 2021/07/22 11:58:13 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ft_utils.h"
#include "libft/libft.h"
#include "ft_view_port.h"
#include "ft_display.h"

t_mat4x4	g_matRotZ;
t_mat4x4	g_matRotX;
float		g_fThetaX;
float		g_fThetaY;
float		g_fElapsedTime;

void	move_camera_angle(t_mystruct *mystruct, int keycode)
{
	// g_fThetaX += 1.0f * g_fElapsedTime;

	// This logic is for draw_map3
	// if (keycode == 12)
	// 	g_fThetaX += 0.25f;
	// else if (keycode == 14)
	// 	g_fThetaX -= 0.25f;
	// else if (keycode == 15)
	// 	g_fThetaY += 0.25f;
	// else if (keycode == 17)
	// 	g_fThetaY -= 0.25f;
	// // Rotation Z
	// (g_matRotZ.m)[0][0] = cosf(g_fThetaY);
	// (g_matRotZ.m)[0][1] = sinf(g_fThetaY);
	// (g_matRotZ.m)[1][0] = -sinf(g_fThetaY);
	// (g_matRotZ.m)[1][1] = cosf(g_fThetaY);
	// (g_matRotZ.m)[2][2] = 1;
	// (g_matRotZ.m)[3][3] = 1;
	// // Rotation X
	// (g_matRotX.m)[0][0] = 1;
	// (g_matRotX.m)[1][1] = cosf(g_fThetaX * 0.5f);
	// (g_matRotX.m)[1][2] = sinf(g_fThetaX * 0.5f);
	// (g_matRotX.m)[2][1] = -sinf(g_fThetaX * 0.5f);
	// (g_matRotX.m)[2][2] = cosf(g_fThetaX * 0.5f);
	// (g_matRotX.m)[3][3] = 1;
	// draw_map3(mystruct);

	// draw_map
	if (keycode == 12) // q pressed
		mystruct->rotation_angles.z += 0.2f;
	else if (keycode == 14) // e pressed
		mystruct->rotation_angles.z -= 0.2f;
	else if (keycode == 15) // r pressed
		mystruct->rotation_angles.y += 0.2f;
	else if (keycode == 17) // t pressed
		mystruct->rotation_angles.y -= 0.2f;
	else if (keycode == 3) // f pressed
		mystruct->rotation_angles.x += 0.2f;
	else if (keycode == 5) // g pressed
		mystruct->rotation_angles.x -= 0.2f;
	draw_map(mystruct);
}

void	move_camera_position(t_mystruct *mystruct, int keycode)
{
	if (keycode == 13)
		mystruct->camera_position.y -= 10.0f;
	else if (keycode == 0)
		mystruct->camera_position.x += 10.0f;
	else if (keycode == 1)
		mystruct->camera_position.y += 10.0f;
	else if (keycode == 2)
		mystruct->camera_position.x -= 10.0f;
	draw_map3(mystruct);
}

void	move_camera_distance(t_mystruct *mystruct, int keycode)
{
	// This logic is for draw_map3
	// if (keycode == 7)
	// 	mystruct->camera_position.z += 6.0f;
	// else if (keycode == 6)
	// 	mystruct->camera_position.z -= 6.0f;
	// draw_map3(mystruct);

	// draw_map
	if (keycode == 7) // x pressed
		mystruct->xy_displacement.x += 5;
	else if (keycode == 6) // z pressed
		mystruct->xy_displacement.x -= 5;
	else if (keycode == 16) // y pressed
		mystruct->xy_displacement.y += 5;
	else if (keycode == 32) // u pressed
		mystruct->xy_displacement.y -= 5;
	draw_map(mystruct);
}
