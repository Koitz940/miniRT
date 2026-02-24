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
		intersect_plane(rt->planes->planes + i, dir, pixel, rt->camera)
	i = -1;
	while (rt->spheres + ++i)
		intersect_sphere(rt->spheres + i, dir, pixel, rt->camera)
	i = -1;
	while (rt->cylinders + ++i)
		intersect_cylinder(rt->cylinders + i, dir, pixel, rt->camera)
	set_col(pixel, rt, dir, rt->light);
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
	mlx_put_image_to_window(rt->screen->mlx, mlx->screen->win, rt->screen->img ...);
	return (SUCCESS);
}
