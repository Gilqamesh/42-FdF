/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilq <gilq@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 17:32:59 by gilq              #+#    #+#             */
/*   Updated: 2021/07/16 17:33:12 by gilq             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"
#include <stdio.h>
#include <stdlib.h>

void	ft_error(char *msg)
{
	perror("Error\n");
	perror(msg);
	exit(EXIT_FAILURE);
}
