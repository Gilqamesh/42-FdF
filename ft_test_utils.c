/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilq <gilq@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 18:33:43 by gilq              #+#    #+#             */
/*   Updated: 2021/07/16 18:47:06 by gilq             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_structs.h"

void    print_map(t_mystruct *mystruct)
{
    int y;
    int x;

    y = -1;
    while (++y < mystruct->height)
    {
        x = -1;
        while (++x < mystruct->width)
            printf("%c", *(*(mystruct->hyperplane + y) + x));
        printf("\n");
    }
}
