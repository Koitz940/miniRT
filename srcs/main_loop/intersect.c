/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 17:52:12 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/02/22 18:48:09 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

//needs a LOT more work...
void	set_col(t_pixel *pixel, int r, int g, int b)
{
	
	pixel->r = r;
	pixel->g = g;
	pixel->b = b;
}

int	intersect_plane(t_plane *plane,
		t_vec dir, t_pixel *pixel, t_camera *camera)
{
	double	denom;
	double	t;

	denom = dot_prod(plane->dir, dir);
	if (denom == 0.0)
		return (0);
	t = -dot_prod(plane->dir, points_vec(camera->pos, plane->pos)) / denom;
	if (t < pixel->t && t > TOL)
	{
		pixel->t = t;
		return (1);
	}
	return (0);
}

int	intersect_sphere(t_sphere *sphere, t_vec dir,
		t_pixel *pixel, t_camera *camera)
{
	double	m;
	double	c;
	double	dis;
	double	t;

	m = -dot_prod(dir, points_vec(camera->pos, sphere->pos));
	c = pow(dot_prod(points_vec(camera->pos, sphere->pos),
				points_vec(camera->pos,
					sphere->pos)), 2) - sphere->d * sphere->d;
	dis = m * m - c;
	if (dis < 0)
		return (0);
	dis = sqrt(dis);
	if (m - dis >= TOL)
		t = m - dis;
	else
		t = m + dis;
	if (t < pixel->t && t > TOL)
	{
		pixel->t = t;
		return (1);
	}
	return (0);
}

int	intersect_cylinder(t_cylinder *cylinder, t_vec dir,
		t_pixel *pixel, t_camera *camera)
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
