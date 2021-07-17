/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 17:18:04 by gilq              #+#    #+#             */
/*   Updated: 2021/07/17 17:14:35 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCTS_H
# define FT_STRUCTS_H

# define SCREEN_W 1000
# define SCREEN_H 1000
typedef struct  s_point
{
    int x;
    int y;
    int z;
}   t_point;

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

typedef struct  s_mystruct
{
    t_vars  vars;
    t_img  img;
    char    **hyperplane;
    int     height;
	int		width;
    t_point *hyperplane_pts;
}   t_mystruct;

#endif
