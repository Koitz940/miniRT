/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 19:58:55 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/02/11 19:16:16 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	move_cam(t_camera *camera)
{
	double	x;
	double	y;
	double	z;

	if (ask_coords(&x, &y, &z))
		return (MALLOC);
	camera->x -= x;
	camera->y -= y;
	camera->z -= z;
	return (SUCCESS);
}

int	place_cam(t_camera *camera)
{
	double	x;
	double	y;
	double	z;

	if (ask_coords(&x, &y, &z))
		return (MALLOC);
	camera->x = x;
	camera->y = y;
	camera->z = z;
	return (SUCCESS);
}

int	move_plane(t_plane *plane)
{
	double	x;
	double	y;
	double	z;

	if (ask_coords(&x, &y, &z))
		return (MALLOC);
	plane->x -= x;
	plane->y -= y;
	plane->z -= z;
	return (SUCCESS);
}

int	place_plane(t_plane *plane)
{
	double	x;
	double	y;
	double	z;

	if (ask_coords(&x, &y, &z))
		return (MALLOC);
	plane->x = x;
	plane->y = y;
	plane->z = z;
	return (SUCCESS);
}
