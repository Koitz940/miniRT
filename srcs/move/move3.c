/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 20:15:37 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/03/11 20:52:47 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	move_sphere(t_sphere *sphere, t_miniRT *rt)
{
	double	x;
	double	y;
	double	z;

	(void)rt;
	if (ask_coords(&x, &y, &z))
		return (MALLOC);
	sphere->pos.x -= x;
	sphere->pos.y -= y;
	sphere->pos.z -= z;
	return (SUCCESS);
}

int	place_sphere(t_sphere *sphere, t_miniRT *rt)
{
	double	x;
	double	y;
	double	z;

	(void)rt;
	if (ask_coords(&x, &y, &z))
		return (MALLOC);
	sphere->pos.x = x;
	sphere->pos.y = y;
	sphere->pos.z = z;
	return (SUCCESS);
}

int	move_light_from(t_light *light, t_miniRT *rt)
{
	t_vec	coefs;

	if (ask_coords(&(coefs.x), &(coefs.y), &(coefs.z)))
		return (MALLOC);
	translate_base(&(light->pos), rt->camera, coefs);
	return (SUCCESS);
}

int	move_cylinder_from(t_cylinder *cylinder, t_miniRT *rt)
{
	t_vec	coefs;

	if (ask_coords(&(coefs.x), &(coefs.y), &(coefs.z)))
		return (MALLOC);
	translate_base(&(cylinder->pos), rt->camera, coefs);
	return (SUCCESS);
}

int	move_sphere_from(t_sphere *sphere, t_miniRT *rt)
{
	t_vec	coefs;

	if (ask_coords(&(coefs.x), &(coefs.y), &(coefs.z)))
		return (MALLOC);
	translate_base(&(sphere->pos), rt->camera, coefs);
	return (SUCCESS);
}
