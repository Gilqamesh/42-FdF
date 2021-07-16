/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilq <gilq@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 17:48:28 by gilq              #+#    #+#             */
/*   Updated: 2021/07/16 18:59:50 by gilq             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_initialize.h"
#include "mlx_linux/mlx.h"

void    initialize_struct(t_mystruct *mystruct)
{
    mystruct->vars.mlx = mlx_init();
    mystruct->vars.win = mlx_new_window(mystruct->vars.mlx, SCREEN_W, SCREEN_H, "FpF");
    mystruct->img.img = mlx_new_image(mystruct->vars.mlx, SCREEN_W, SCREEN_H);
    mystruct->img.addr = mlx_get_data_addr(mystruct->img.img,
        &mystruct->img.bpp, &mystruct->img.ll, &mystruct->img.end);
    mystruct->hyperplane = (char **)0;
}
