/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 17:52:12 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/02/21 18:50:36 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	intersect_plane(t_plane *plane, t_vec pos)
{
	t_vec	aux;

	aux.x = pos.x - plane->pos.x;
	aux.y = pos.y - plane->pos.y;
	aux.z = pos.z - plane->pos.z;

	return (fasb(dot_prod(aux, plane->dir)) < TOL);
}

int	intersect_sphere(t_sphere *sphere, t_vec pos)
{
	t_vec	aux;

	aux.x = pos.x - sphere->pos.x;
	aux.y = pos.y - sphere->pos.y;
	aux.z = pos.z - sphere->pos.z;
	return (fasb(mod(aux.x, aux.y, aux.z) - sphere->d * sphere->d) < TOL);
}

int	intersect_cylinder(t_cylinder *cylinder, t_vec pos)
{
	t_vec	aux;
	double	height;
	double	r;

	aux.x = pos.x - cylinder->pos.x;
	aux.y = pos.y - cylinder->pos.y;
	aux.z = pos.z - cylinder->pos.z;
	height = dot_prod(aux, cylinder->dir);
	if (cylinder->h / 2.0 - fasb(height) < -TOL)
		return (0);
	move_by(&(aux), cylinder->dir, -height);
	r = sqrt(mod(aux.x, aux.y, aux.z) - cylinder->d);
	if (r < TOL && fabs(cylinder->h / 2.0 - fasb(height)) < TOL)
		return (1);
	else if (fabs(r) < TOL)
		return (1);
	return (0);
}

static int	intersect2(t_vec pos,
		t_miniRT *rt, t_screen *screen, t_pixel *pixel)
{
	size_t	i;

	i = -1;
	while (rt->cylinders + ++i)
	{
		if (intersect_cylinder(rt->cylinders + i, pos))
		{
			paint(screen, pixel);
			return (1);
		}
	}
	return (0);
}

int	intersect(t_vec pos, t_miniRT *rt, t_screen *screen, t_pixel *pixel)
{
	size_t	i;

	i = -1;
	while (rt->planes + ++i)
	{
		if (intersect_plane(rt->planes + i, pos))
		{
			paint(screen, pixel);
			return (1);
		}
	}
	i = -1;
	while (rt->spheres + ++i)
	{
		if (intersect_sphere(rt->spheres + i, pos))
		{
			paint(screen, pixel);
			return (1);
		}
	}
	return (intersect2(pos, rt, screen, pixel));
}
