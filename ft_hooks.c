/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 17:55:23 by edavid            #+#    #+#             */
/*   Updated: 2021/07/17 18:07:01 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include "mlx/mlx.h"

int	exit_clicked(t_mystruct *mystruct)
{
	mlx_destroy_window(mystruct->vars.mlx, mystruct->vars.win);
	exit(EXIT_SUCCESS);
	return (0);
}

int	esc_pressed(int keycode, t_mystruct *mystruct)
{
	if (keycode == 53)
		exit_clicked(mystruct);
	return (0);
}

void	register_hooks(t_mystruct *mystruct)
{
	mlx_key_hook(mystruct->vars.win, esc_pressed, mystruct);
	mlx_hook(mystruct->vars.win, 17, (1L << 17), exit_clicked, mystruct);
}
