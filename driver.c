/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   driver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 17:24:10 by gilq              #+#    #+#             */
/*   Updated: 2021/07/17 14:09:53 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "ft_structs.h"
#include "ft_error.h"
#include "ft_initialize.h"
#include "ft_utils.h"
#include "ft_test_utils.h"

int main(int argc, char **argv)
{
    t_mystruct  mystruct;

    if (argc != 2)
        ft_error("usage: ./FdF.out <filePath>");
    initialize_struct(&mystruct);
    parse_map(&mystruct, argv);
    print_map(&mystruct);
    mlx_loop(mystruct.vars.mlx);
}
