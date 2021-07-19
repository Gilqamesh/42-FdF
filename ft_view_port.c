/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_view_port.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 18:21:30 by edavid            #+#    #+#             */
/*   Updated: 2021/07/19 20:35:00 by edavid           ###   ########.fr       */
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
	keycode += 1;
	g_fTheta += 1.0f * g_fElapsedTime;
	// Rotation Z
	(g_matRotZ.m)[0][0] = cosf(g_fTheta);
	(g_matRotZ.m)[0][1] = sinf(g_fTheta);
	(g_matRotZ.m)[1][0] = -sinf(g_fTheta);
	(g_matRotZ.m)[1][1] = cosf(g_fTheta);
	(g_matRotZ.m)[2][2] = 1;
	(g_matRotZ.m)[3][3] = 1;
	// Rotation X
	(g_matRotX.m)[0][0] = 1;
	(g_matRotX.m)[1][1] = cosf(g_fTheta * 0.5f);
	(g_matRotX.m)[1][2] = sinf(g_fTheta * 0.5f);
	(g_matRotX.m)[2][1] = -sinf(g_fTheta * 0.5f);
	(g_matRotX.m)[2][2] = cosf(g_fTheta * 0.5f);
	(g_matRotX.m)[3][3] = 1;
	draw_map3(mystruct);
}
