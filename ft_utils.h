/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilq <gilq@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 17:45:41 by gilq              #+#    #+#             */
/*   Updated: 2021/07/16 18:46:29 by gilq             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

# include <stdlib.h>
# include "ft_structs.h"
void	*ft_realloc(void *src, size_t size);
void    parse_map(t_mystruct *mystruct, char **argv);

#endif
