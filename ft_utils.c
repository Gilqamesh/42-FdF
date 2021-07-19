/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 17:45:28 by gilq              #+#    #+#             */
/*   Updated: 2021/07/19 15:00:33 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
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

double	max_of(double a, double b)
{
	if (a < b)
		return (b);
	return (a);
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

void	multiply_vec3d_m4x4(t_3d_pointf *i, t_3d_pointf *o,
t_mat4x4 *m)
{
	float	w;

	o->x = i->x * (m->m)[0][0] + i->y * (m->m)[1][0] + i->z * (m->m)[2][0]
		+ (m->m)[3][0];
	o->y = i->x * (m->m)[0][1] + i->y * (m->m)[1][1] + i->z * (m->m)[2][1]
		+ (m->m)[3][1];
	o->z = i->x * (m->m)[0][2] + i->y * (m->m)[1][2] + i->z * (m->m)[2][2]
		+ (m->m)[3][2];
	w = i->x * (m->m)[0][3] + i->y * (m->m)[1][3] + i->z * (m->m)[2][3]
		+ (m->m)[3][3];
	if (w != 0.0f)
	{
		o->x /= w;
		o->y /= w;
		o->z /= w;
	}
}
