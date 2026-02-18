/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 18:56:07 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/02/18 20:41:22 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	move_plane_from(t_plane *plane, t_vec dir)
{
	t_vec	coefs;

	if (ask_coords(&(coefs.x), &(coefs.y), &(coefs.z)))
		return (MALLOC);
	translate_base(plane->pos, dir, coefs);
	return (SUCCESS);
}

int	move_light(t_light *light)
{
	double	x;
	double	y;
	double	z;

	if (ask_coords(&x, &y, &z))
		return (MALLOC);
	light->pos.x -= x;
	light->pos.y -= y;
	light->pos.z -= z;
	return (SUCCESS);
}

int	place_light(t_light *light)
{
	double	x;
	double	y;
	double	z;

	if (ask_coords(&x, &y, &z))
		return (MALLOC);
	light->pos.x = x;
	light->pos.y = y;
	light->pos.z = z;
	return (SUCCESS);
}

int	move_cylinder(t_cylinder *cylinder)
{
	double	x;
	double	y;
	double	z;

	if (ask_coords(&x, &y, &z))
		return (MALLOC);
	cylinder->pos.x -= x;
	cylinder->pos.y -= y;
	cylinder->pos.z -= z;
	return (SUCCESS);
}

int	place_cylinder(t_cylinder *cylinder)
{
	double	x;
	double	y;
	double	z;

	if (ask_coords(&x, &y, &z))
		return (MALLOC);
	cylinder->pos.x = x;
	cylinder->pos.y = y;
	cylinder->pos.z = z;
	return (SUCCESS);
}
