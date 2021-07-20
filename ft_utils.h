/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 17:45:41 by gilq              #+#    #+#             */
/*   Updated: 2021/07/20 15:42:39 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

# include <stdlib.h>
# include "ft_structs.h"
void	*ft_realloc(void *src, size_t size);
void    parse_map(t_mystruct *mystruct, char **argv);
void	convert_to_points(t_mystruct *mystruct);
char	*ft_strchr_v2(const char *s, int c);
int		round_to_nearest(double a);
void	my_mlx_pixel_put(t_img *data, double x, double y, int color);
double	min_of(double a, double b);
void	register_hooks(t_mystruct *mystruct);
int		destroy_window(t_mystruct *mystruct);
int		key_press_listener(int keycode, t_mystruct *mystruct);
double	abs_of(double a);
void	line_put_parametric(t_img *img, t_2d_point A, t_2d_point B, int color);
void	multiply_vec3d_m4x4(t_3d_pointf *i, t_3d_pointf *o,
	t_mat4x4 *m);
double	max_of(double a, double b);
int		update_elapsed_time(t_mystruct *mystruct);
void	draw_map3(t_mystruct *mystruct);
void	convert_to_trigons(t_mystruct *mystruct);
void	draw_triangle(t_mystruct *mystruct, t_tri2d *T);
void	move_camera_position(t_mystruct *mystruct, int keycode);
t_img	get_blank_image(t_mystruct *mystruct);
void	clear_img(t_img *img);
void	move_camera_distance(t_mystruct *mystruct, int keycode);
double	min_of_3(double a, double b, double c);
double	max_of_3(double a, double b, double c);
void	shade_triangle(t_mystruct *mystruct, t_tri2d *tri2d);

#endif
