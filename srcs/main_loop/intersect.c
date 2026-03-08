/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 17:52:12 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/03/08 19:15:21 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	intersect_plane(t_plane *plane,
		t_vec dir, t_pixel *pixel, t_camera *camera)
{
	double	denom;
	double	numer;
	double	t;

	denom = dot_prod(plane->dir, dir);
	numer = dot_prod(plane->dir, points_vec(camera->pos, plane->pos));
	if (denom != 0.0)
		t = numer / denom;
	else
		return (0);
	if (t < pixel->t && t > TOL)
	{
		pixel->t = t;
		set_col(pixel, plane->r, plane->g, plane->b);
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
	c = fabs(dot_prod(points_vec(camera->pos, sphere->pos),
			points_vec(camera->pos,
				sphere->pos))) - sphere->d * sphere->d;
	dis = m * m - c;
	if (dis < 0.0)
		return (0);
	dis = sqrt(dis);
	if (m - dis > TOL)
		t = m - dis;
	else
		t = m + dis;
	if (t < pixel->t && t > TOL)
	{
		pixel->t = t;
		set_col(pixel, sphere->r, sphere->g, sphere->b);
		return (1);
	}
	return (0);
}

static int	shell(t_cylinder *cylinder, t_why why, t_pixel *pixel)
{
	double	a;
	double	b;
	double	c;
	double	t;
	double	dis;

	a = mod(why.vt.x, why.vt.y, why.vt.z);
	if (a == 0.0)
		return (0);
	b = 2 * dot_prod(why.vt, why.wt);
	c = mod(why.wt.x, why.wt.y, why.wt.z) - cylinder->d * cylinder->d;
	dis = b * b - 4 * a * c;
	if (dis < 0.0)
		return (0);
	dis = sqrt(dis);
	if (-b - dis > TOL)
		t = -(b + dis) / (2 * a);
	else
		t = (-b + dis) / (2 * a);
	update(&(why.dir), t);
	if (t < pixel->t && t > TOL && cylinder->h / 2.0
		>= norm(points_vec(why.u, add(why.w, why.dir))))
		return (pixel->t = t,
			set_col(pixel, cylinder->r, cylinder->g, cylinder->b), 1);
	return (0);
}

static int	caps(t_cylinder *cylinder, t_why why, t_pixel *pixel)
{
	double	denom;
	double	numer;
	double	t;
	int		check;
	double	old;

	old = pixel->t;
	denom = dot_prod(why.dir, cylinder->dir);
	if (denom == 0.0)
		return (0);
	numer = -dot_prod(why.w, cylinder->dir);
	t = (numer + cylinder->h / 2.0) / denom;
	check = norm(add(why.w, times(why.dir, t))) <= cylinder->d;
	if (check && t < pixel->t && t > TOL)
		pixel->t = t;
	t = (numer - cylinder->h / 2.0) / denom;
	check = norm(add(why.w, times(why.dir, t))) <= cylinder->d;
	if (check && t < pixel->t && t > TOL)
		pixel->t = t;
	if (old != pixel->t)
		set_col(pixel, cylinder->r, cylinder->g, cylinder->b);
	return (old != pixel->t);
}

int	intersect_cylinder(t_cylinder *cylinder, t_vec dir,
		t_pixel *pixel, t_camera *camera)
{
	t_why	why;
	int		check;

	check = 0;
	why.w = points_vec(cylinder->pos, camera->pos);
	why.vt = cylinder->dir;
	why.wt = cylinder->dir;
	update(&(why.vt), dot_prod(dir, cylinder->dir));
	update(&(why.wt), dot_prod(why.w, cylinder->dir));
	why.vt = points_vec(why.vt, dir);
	why.vt = points_vec(why.wt, why.w);
	why.dir = dir;
	why.u = cylinder->dir;
	if (shell(cylinder, why, pixel))
		check = 1;
	if (caps(cylinder, why, pixel))
		check = 1;
	return (check);
}
