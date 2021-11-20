/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 17:55:23 by edavid            #+#    #+#             */
/*   Updated: 2021/07/22 11:57:31 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_utils.h"
#include "mlx/mlx.h"
#include "ft_view_port.h"

int	destroy_window(t_mystruct *mystruct)
{
	mlx_destroy_window(mystruct->vars.mlx, mystruct->vars.win);
	exit(EXIT_SUCCESS);
	return (0);
}

// MAC: x - 7, y - 16, z - 6, u - 32
static int	xyzu_pressed(int keycode)
{
	if (keycode == 7 || keycode == 16 || keycode == 6 || keycode == 32)
		return (1);
	return (0);
}

// MAC: w - 13, a - 0, s - 1, d - 2
static int	wasd_pressed(int keycode)
{
	if (keycode == 13 || !keycode || keycode == 1 || keycode == 2)
		return (1);
	return (0);
}

// MAC: q - 12, e - 14, r - 15, t - 17, f - 3, g - 5
static int	qertfg_pressed(int keycode)
{
	if (keycode == 12 || keycode == 14 || keycode == 15 || keycode == 17)
		return (1);
	return (0);
}

// move_camera* function names are placeholders
int	key_press_listener(int keycode, t_mystruct *mystruct)
{
	printf("keycode: %d\n", keycode);
	// MAC: esc - 53
	if (keycode == 53)
		destroy_window(mystruct);
	if (wasd_pressed(keycode))
		move_camera_position(mystruct, keycode);
	if (xyzu_pressed(keycode))
		move_camera_distance(mystruct, keycode);
	if (qertfg_pressed(keycode))
		move_camera_angle(mystruct, keycode);
	return (0);
}

int	update_elapsed_time(t_mystruct *mystruct)
{
	g_fElapsedTime += 0.00001;
	if (g_fElapsedTime > 1000.0f)
		g_fElapsedTime = 0.0f;
	// printf("elapsed time: %f\n", g_fElapsedTime);
	move_camera_angle(mystruct, 0);
	(void)mystruct;
	return (0);
}

void	register_hooks(t_mystruct *mystruct)
{
	mlx_key_hook(mystruct->vars.win, key_press_listener, mystruct);
	// mlx_hook(mystruct->vars.win, 9, (1L << 10), mouse_wheel_listener, mystruct);
	mlx_hook(mystruct->vars.win, 17, (1L << 17), destroy_window, mystruct);
	// mlx_loop_hook(mystruct->vars.mlx, update_elapsed_time, mystruct);
}
