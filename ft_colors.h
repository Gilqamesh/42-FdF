/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 16:53:07 by edavid            #+#    #+#             */
/*   Updated: 2021/07/20 16:13:13 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COLORS_H
# define FT_COLORS_H

extern int	g_mlx_red;
extern int	g_mlx_purple;
extern int	g_mlx_blue;
extern int	g_mlx_cyan;
extern int	g_mlx_green;
extern int	g_mlx_yellow;
extern int	g_mlx_white;
extern int	g_mlx_black;
extern int	g_mlx_blank;

#include "ft_structs.h"
int		get_red_from_hex(int hex);
int		get_green_from_hex(int hex);
int		get_blue_from_hex(int hex);
t_rgba	make_rgba(int red, int green, int blue, int alpha);
t_rgba	hex_to_rgba(int hex);
int		rgba_to_hex(t_rgba rgba);

#endif
