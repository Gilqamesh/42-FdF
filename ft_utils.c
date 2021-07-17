/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 17:45:28 by gilq              #+#    #+#             */
/*   Updated: 2021/07/17 18:29:19 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
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

// returns pointer to null char instead of null in case character was not found
char	*ft_strchr_v2(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return ((char *)s);
}

int	round_to_nearest(double a)
{
	if ((int)(a * 10) % 10 < 5)
		return ((int)a);
	return ((int)(a + 1));
}

// x and y gets rounded to nearest integer
void	my_mlx_pixel_put(t_img *data, double x, double y, int color)
{
	char	*dst;
	int		a;
	int		b;

	a = round_to_nearest(x);
	b = round_to_nearest(y);
	dst = data->addr + (b * data->ll + a * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

double	min_of(double a, double b)
{
	if (a < b)
		return (a);
	return (b);
}

double	abs_of(double a)
{
	if (a < 0)
		return (-a);
	return (a);
}

// uses parametric equation of line segment
void	line_put_parametric(t_img *data, t_2d_point A, t_2d_point B, int color)
{
	double	t;
	double	increment;

	t = 0;
	increment = 1 / sqrt(pow(abs_of(A.x - B.x), 2) + pow(abs_of(A.y - B.y), 2));
	while (t <= 1)
	{
		my_mlx_pixel_put(data, t * A.x + (1 - t) * B.x, t * A.y + (1 - t) * B.y,
			color);
		t += increment;
	}
}
