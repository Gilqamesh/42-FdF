/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilq <gilq@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 17:45:28 by gilq              #+#    #+#             */
/*   Updated: 2021/07/16 18:46:47 by gilq             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include "libft/libft.h"

void	*ft_realloc(void *src, size_t size)
{
	void	*new;

	new = malloc(size);
	if (!new)
		return (src);
	if (!src)
		return (new);
	ft_memmove(new, src, size);
	free(src);
	return (new);
}
