/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 17:18:04 by gilq              #+#    #+#             */
/*   Updated: 2021/07/22 11:52:40 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCTS_H
# define FT_STRUCTS_H

# define SCREEN_W 1000
# define SCREEN_H 1000
# define MAX_Z 1.5f

typedef struct	s_rgba
{
	unsigned char	alpha;
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
}				t_rgba;

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

typedef struct	s_mat3x3
{
	float	m[3][3];
}	t_mat3x3;

typedef struct	s_tri
{
	t_3d_pointf	p[3];
}	t_tri;

typedef struct	s_tri2d
{
	t_2d_point	p[3];
}	t_tri2d;

typedef struct	s_quad
{
	t_3d_pointf	p[4];
}	t_quad;

typedef struct	s_extrema
{
	int	min;
	int	max;
}	t_extrema;

typedef struct	s_line
{
	t_3d_pointf	p[2];
}	t_line;

// camera_position and camera_distance are placeholders
typedef struct  s_mystruct
{
    t_vars  	vars;
    t_img  		img;
    char    	**hyperplane;
    int     	height;
	int			width;
    t_3d_pointf *hyperplane_pts;
	t_2d_point	*screen_pts;
	// 1 displayed, 0 not displayed screen point
	int			*screen_index;
	t_mat4x4	projection_mat;
	t_img		blank_img;
	t_tri		*trigons;
	t_tri		*projected_trigons;
	// 1 displayed, 0 not displayed triangle
	int			*projected_trigons_index;
	int			n_of_trigons;
	t_3d_pointf	camera_position;
	t_2d_pointf	maxima_Z;
	// control camera for draw_map
	t_2d_point	xy_displacement;
	t_3d_pointf	rotation_angles;
	// X, Y and Z rotation matrices
	t_mat3x3	rotation_matrices[3];
}   t_mystruct;

#endif