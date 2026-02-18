/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 20:15:37 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/02/18 20:43:10 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	move_sphere(t_sphere *sphere)
{
	double	x;
	double	y;
	double	z;

	if (ask_coords(&x, &y, &z))
		return (MALLOC);
	sphere->pos.x -= x;
	sphere->pos.y -= y;
	sphere->pos.z -= z;
	return (SUCCESS);
}

int	place_sphere(t_sphere *sphere)
{
	double	x;
	double	y;
	double	z;

	if (ask_coords(&x, &y, &z))
		return (MALLOC);
	sphere->pos.x = x;
	sphere->pos.y = y;
	sphere->pos.z = z;
	return (SUCCESS);
}

int	move_light_from(t_light *light, t_vec dir)
{
	t_vec	coefs;

	if (ask_coords(&(coefs.x), &(coefs.y), &(coefs.z)))
		return (MALLOC);
	translate_base(light->pos, dir, coefs);
	return (SUCCESS);
}

int	move_cylinder_from(t_cylinder *cylinder, t_vec dir)
{
	t_vec	coefs;

	if (ask_coords(&(coefs.x), &(coefs.y), &(coefs.z)))
		return (MALLOC);
	translate_base(cylinder->pos, dir, coefs);
	return (SUCCESS);
}

int	move_sphere_from(t_sphere *sphere, t_vec dir)
{
	t_vec	coefs;

	if (ask_coords(&(coefs.x), &(coefs.y), &(coefs.z)))
		return (MALLOC);
	translate_base(sphere->pos, dir, coefs);
	return (SUCCESS);
}