/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 13:05:43 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/02/21 17:52:25 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec	choose_dir(t_pixel *pixel, t_camera *camera)
{
	return (camera->dir);
}

int	intersect(t_vec pos, t_miniRT *rt, t_screen *screen, t_pixel *pixel)
{
	size_t	i;

	i = -1;
	while (rt->planes + ++i)
	{
		if (intersect_plane(rt->planes + i, pixel))
		{
			paint(screen, pixel);
			return (1);
		}
	}
	i = -1;
	while (rt->spheres + ++i)
	{
		if (intersect_sphere(rt->spheres + i, pixel))
		{
			paint(screen, pixel);
			return (1);
		}
	}
	return (intersect2());
}

void	choose_color(t_screen *screen, t_pixel *pixel, t_vec dir, t_miniRT *rt)
{
	size_t	i;
	t_vec	pos;

	i = -1;
	pos = rt->camera->pos;
	while (++i < MAX_ITERS)
	{
		move_by(&pos, dir, TOL);
		if (intersect(pos, rt, screen, pixel))
			break ;
	}
	paint(screen, pixel);
}

int	loop(t_miniRT *rt)
{
	int	i;
	int	j;

	j = 0;
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
			choose_color(rt->screen, rt->screen->screen
				+ (WIDTH * j + i), choose_dir(rt->screen->screen
					+ (WIDTH * j + i), rt->camera), rt);
			i++;
		}
		j++;
	}
	return (SUCCESS);
}
