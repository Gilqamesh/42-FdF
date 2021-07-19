/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   driver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 17:24:10 by gilq              #+#    #+#             */
/*   Updated: 2021/07/19 11:58:07 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "ft_structs.h"
#include "ft_error.h"
#include "ft_initialize.h"
#include "ft_utils.h"
#include "ft_test_utils.h"
#include "ft_display.h"
#include <math.h>

int main(int argc, char **argv)
{
    t_mystruct  mystruct;

    if (argc != 2)
        ft_error("usage: ./FdF.out filePath");
    initialize_struct(&mystruct);
    parse_map(&mystruct, argv);
    print_map(&mystruct);
	// print_3d_points(&mystruct);
	draw_map2(&mystruct);
	register_hooks(&mystruct);
    mlx_loop(mystruct.vars.mlx);
}
