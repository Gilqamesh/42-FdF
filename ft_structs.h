/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 17:18:04 by gilq              #+#    #+#             */
/*   Updated: 2021/07/19 11:56:04 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCTS_H
# define FT_STRUCTS_H

# define SCREEN_W 1000
# define SCREEN_H 1000
typedef struct  s_3d_point
{
    int x;
    int y;
    int z;
}   t_3d_point;

typedef struct	s_2d_point
{
	int	x;
	int	y;
}	t_2d_point;

typedef struct  s_img
{
    void    *img;
    char    *addr;
    int     bpp;
    int     ll;
    int     end;
}   t_img;

typedef struct  s_vars
{
    void    *mlx;
    void    *win;
}   t_vars;

typedef struct	s_3d_pointf
{
	double	x;
	double	y;
	double	z;
}	t_3d_pointf;

typedef struct	s_2d_pointf
{
	double	x;
	double	y;
}	t_2d_pointf;

typedef struct	s_mat4x4
{
	float	m[4][4];
}	t_mat4x4;

typedef struct	s_tri
{
	t_3d_pointf	p[3];
}	t_tri;

typedef struct  s_mystruct
{
    t_vars  	vars;
    t_img  		img;
    char    	**hyperplane;
    int     	height;
	int			width;
    t_3d_point 	*hyperplane_pts;
	t_2d_point	*screen_pts;
	t_mat4x4	projection_mat;
}   t_mystruct;

#endif
