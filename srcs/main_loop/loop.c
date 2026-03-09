/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 13:05:43 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/03/08 19:28:49 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec	choose_dir(t_pixel *pixel, t_camera *camera)
{
	double	a;
	double	b;
	t_vec	dir;

	a = (((double)pixel->x + 0.5 - (double)WIDTH / 2.0)) / camera->f;
	b = ((-(double)pixel->y - 0.5 + (double)HEIGHT / 2.0)) / camera->f;
	dir.x = a * camera->right.x + b * camera->up.x + camera->dir.x;
	dir.y = a * camera->right.y + b * camera->up.y + camera->dir.y;
	dir.z = a * camera->right.z + b * camera->up.z + camera->dir.z;
	normalise(&dir);
	return (dir);
}

void	choose_color(t_screen *screen, t_pixel *pixel, t_vec dir, t_miniRT *rt)
{
	size_t	i;

	i = -1;
	while (++i < rt->planes->length)
		intersect_plane(rt->planes->planes + i, dir, pixel, rt->camera);
	i = -1;
	while (++i < rt->spheres->length)
		if (intersect_sphere(rt->spheres->spheres + i, dir, pixel, rt->camera))
	i = -1;
	while (++i < rt->cylinders->length)
		intersect_cylinder(rt->cylinders->cylinders + i, dir, pixel, rt->camera);
	//set_col(pixel, rt, dir, rt->light);
	(void)screen;
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
	mlx_put_image_to_window(rt->screen->mlx,
		rt->screen->window, rt->screen->img, 0, 0);
	return (SUCCESS);
}
