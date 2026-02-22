/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 13:05:43 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/02/22 18:55:54 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec	choose_dir(t_pixel *pixel, t_camera *camera)
{
	return (camera->dir);
}

void	choose_color(t_screen *screen, t_pixel *pixel, t_vec dir, t_miniRT *rt)
{
	size_t	i;

	i = -1;
	while (rt->cylinders + ++i)
	{
		if (intersect_plane(rt->planes->planes + i, dir, pixel, rt->camera)
			&& should_paint_plane(rt->planes->planes + i, pixel, dir, rt))
			set_col(pixel, rt->planes->planes[i].r,
				rt->planes->planes[i].g, rt->planes->planes[i].b);
	}
	i = -1;
	while (rt->spheres + ++i)
	{
		if (intersect_sphere(rt->spheres + i, dir, pixel, rt->camera)
			&& should_paint_sphere(rt->spheres->spheres + i, pixel, dir, rt))
			set_col_sphere(pixel, rt->spheres + i);
	}
	i = -1;
	while (rt->cylinders + ++i)
	{
		if (intersect_cylinder(rt->cylinders + i, dir, pixel, rt->camera)
			&& should_paint_cylinder(rt->cylinders->cylinders + i, pixel, dir, rt))
			set_col_cylinder(pixel, rt->cylinders->cylinders + i);
	}
	paint(rt, pixel, get_col(pixel));
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
