/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 17:55:23 by edavid            #+#    #+#             */
/*   Updated: 2021/07/19 20:36:08 by edavid           ###   ########.fr       */
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

// MAC: x - 7, y - 16, z - 6
static int	xyz_pressed(int keycode)
{
	if (keycode)
		return (1);
	return (0);
}

// MAC: w - 13, a - 0, s - 1, d - 2
// static int	wasd_pressed(int keycode)
// {
// 	if (keycode == 13 || !keycode || keycode == 1 || keycode == 2)
// 		return (1);
// 	return (0);
// }

int	key_press_listener(int keycode, t_mystruct *mystruct)
{
	printf("keycode: %d\n", keycode);
	// MAC: esc - 53
	if (keycode == 53)
		destroy_window(mystruct);
	// if (wasd_pressed(keycode))
	// 	move_camera_position(mystruct);
	if (xyz_pressed(keycode))
		move_camera_angle(mystruct, keycode);
	return (0);
}

int	update_elapsed_time(t_mystruct *mystruct)
{
	g_fElapsedTime += 0.0001;
	if (g_fElapsedTime > 1000.0f)
		g_fElapsedTime = 0.0f;
	// printf("elapsed time: %f\n", g_fElapsedTime);
	move_camera_angle(mystruct, 0);
	return (0);
}

void	register_hooks(t_mystruct *mystruct)
{
	mlx_key_hook(mystruct->vars.win, key_press_listener, mystruct);
	// mlx_hook(mystruct->vars.win, 9, (1L << 10), mouse_wheel_listener, mystruct);
	mlx_hook(mystruct->vars.win, 17, (1L << 17), destroy_window, mystruct);
	// mlx_loop_hook(mystruct->vars.mlx, update_elapsed_time, mystruct);
}
