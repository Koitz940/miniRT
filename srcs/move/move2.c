/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 18:56:07 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/02/09 20:18:04 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	move_light(t_light *light)
{
	double	x;
	double	y;
	double	z;

	if (ask_coords(&x, &y, &z))
		return (MALLOC);
	light->x -= x;
	light->y -= y;
	light->z -= z;
	return (SUCCESS);
}

int	place_light(t_light *light)
{
	double	x;
	double	y;
	double	z;

	if (ask_coords(&x, &y, &z))
		return (MALLOC);
	light->x = x;
	light->y = y;
	light->z = z;
	return (SUCCESS);
}

int	move_cylinder(t_cylinder *cylinder)
{
	double	x;
	double	y;
	double	z;

	if (ask_coords(&x, &y, &z))
		return (MALLOC);
	cylinder->x -= x;
	cylinder->y -= y;
	cylinder->z -= z;
	return (SUCCESS);
}

int	place_cylinder(t_cylinder *cylinder)
{
	double	x;
	double	y;
	double	z;

	if (ask_coords(&x, &y, &z))
		return (MALLOC);
	cylinder->x = x;
	cylinder->y = y;
	cylinder->z = z;
	return (SUCCESS);
}
