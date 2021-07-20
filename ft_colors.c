/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 16:54:56 by edavid            #+#    #+#             */
/*   Updated: 2021/07/20 19:47:30 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_colors.h"
#include "ft_structs.h"
#include "ft_utils.h"

int	g_mlx_red = 0x00FF0000;
int	g_mlx_purple = 0x00FF00FF;
int	g_mlx_blue = 0x000000FF;
int	g_mlx_cyan = 0x0000FFFF;
int	g_mlx_green = 0x0000FF00;
int	g_mlx_yellow = 0x00FFFF00;
int	g_mlx_white = 0x00FFFFFF;
int	g_mlx_black = 0x00000000;
int	g_mlx_blank = 0x00000000;

int		get_red_from_hex(int hex)
{
	return ((hex & 0x00FF0000) >> 16);
}

int		get_green_from_hex(int hex)
{
	return ((hex & 0x0000FF00) >> 8);
}

int		get_blue_from_hex(int hex)
{
	return (hex & 0x000000FF);
}

t_rgba	make_rgba(int red, int green, int blue, int alpha)
{
	return ((t_rgba){alpha, red, green, blue});
}

t_rgba	hex_to_rgba(int hex)
{
	return ((t_rgba){(hex & 0xFF000000) >> 24, (hex & 0x00FF0000) >> 16,
					(hex & 0x0000FF00) >> 8, hex & 0x000000FF});
}

int		rgba_to_hex(t_rgba rgba)
{
	return (rgba.alpha << 24 | rgba.red << 16 | rgba.green << 8 | rgba.blue);
}

// get color from colors.x to colors.y, 0 <= ratio <= 1
int	get_relative_color(t_2d_point colors, float ratio)
{
	double	new_red;
	double	new_green;
	double	new_blue;

	new_red = (get_red_from_hex(colors.y) - get_red_from_hex(colors.x))
		* ratio + get_red_from_hex(colors.x);
	new_green = (get_green_from_hex(colors.y) - get_green_from_hex(colors.x))
		* ratio + get_green_from_hex(colors.x);
	new_blue = (get_blue_from_hex(colors.y) - get_blue_from_hex(colors.x))
		* ratio + get_blue_from_hex(colors.x);
	return (rgba_to_hex((t_rgba){0, round_to_nearest(new_red),
		round_to_nearest(new_green), round_to_nearest(new_blue)}));
}
