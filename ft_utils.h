/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 17:45:41 by gilq              #+#    #+#             */
/*   Updated: 2021/07/17 15:13:37 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

# include <stdlib.h>
# include "ft_structs.h"
void	*ft_realloc(void *src, size_t size);
void    parse_map(t_mystruct *mystruct, char **argv);
void	convert_to_points(t_mystruct *mystruct);
char	*ft_strchr_v2(const char *s, int c);

#endif
