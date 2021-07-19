/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_view_port.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 18:34:10 by edavid            #+#    #+#             */
/*   Updated: 2021/07/19 18:56:01 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VIEW_PORT_H
# define FT_VIEW_PORT_H

#include "ft_structs.h"
extern t_mat4x4	g_matRotZ;
extern t_mat4x4	g_matRotX;
extern float	g_fTheta;
extern float	g_fElapsedTime;
void	move_camera_angle(t_mystruct *mystruct, int keycode);

#endif
