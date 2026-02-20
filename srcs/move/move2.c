/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 18:56:07 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/02/20 19:51:03 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	move_plane_from(t_plane *plane, t_miniRT *rt)
{
	t_vec	coefs;

	if (ask_coords(&(coefs.x), &(coefs.y), &(coefs.z)))
		return (MALLOC);
	translate_base(plane->pos, rt->camera, coefs);
	return (SUCCESS);
}

int	move_light(t_light *light, t_miniRT *rt)
{
	double	x;
	double	y;
	double	z;

	(void)rt;
	if (ask_coords(&x, &y, &z))
		return (MALLOC);
	light->pos.x -= x;
	light->pos.y -= y;
	light->pos.z -= z;
	return (SUCCESS);
}

int	place_light(t_light *light, t_miniRT *rt)
{
	double	x;
	double	y;
	double	z;

	(void)rt;
	if (ask_coords(&x, &y, &z))
		return (MALLOC);
	light->pos.x = x;
	light->pos.y = y;
	light->pos.z = z;
	return (SUCCESS);
}

int	move_cylinder(t_cylinder *cylinder, t_miniRT *rt)
{
	double	x;
	double	y;
	double	z;

	(void)rt;
	if (ask_coords(&x, &y, &z))
		return (MALLOC);
	cylinder->pos.x -= x;
	cylinder->pos.y -= y;
	cylinder->pos.z -= z;
	return (SUCCESS);
}

int	place_cylinder(t_cylinder *cylinder, t_miniRT *rt)
{
	double	x;
	double	y;
	double	z;

	(void)rt;
	if (ask_coords(&x, &y, &z))
		return (MALLOC);
	cylinder->pos.x = x;
	cylinder->pos.y = y;
	cylinder->pos.z = z;
	return (SUCCESS);
}
