/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 17:18:04 by gilq              #+#    #+#             */
/*   Updated: 2021/07/17 15:03:06 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCTS_H
# define FT_STRUCTS_H

typedef struct  s_point
{
    int x;
    int y;
    int z;
}   t_point;

typedef struct  s_data
{
    void    *img;
    char    *addr;
    int     bpp;
    int     ll;
    int     end;
}   t_data;

typedef struct  s_vars
{
    void    *mlx;
    void    *win;
}   t_vars;

typedef struct  s_mystruct
{
    t_vars  vars;
    t_data  img;
    char    **hyperplane;
    int     height;
	int		width;
    t_point *hyperplane_pts;
}   t_mystruct;

#endif
