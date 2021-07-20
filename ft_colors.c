/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 16:54:56 by edavid            #+#    #+#             */
/*   Updated: 2021/07/20 16:13:00 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_colors.h"
#include "ft_structs.h"

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
