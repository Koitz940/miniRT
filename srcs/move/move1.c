/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 19:58:55 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/02/18 20:38:59 by gcassi-d         ###   ########.fr       */
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
	camera->pos.x -= x;
	camera->pos.y -= y;
	camera->pos.z -= z;
	return (SUCCESS);
}

int	place_cam(t_camera *camera)
{
	double	x;
	double	y;
	double	z;

	if (ask_coords(&x, &y, &z))
		return (MALLOC);
	camera->pos.x = x;
	camera->pos.y = y;
	camera->pos.z = z;
	return (SUCCESS);
}

int	move_cam_from(t_camera *camera, t_vec dir)
{
	t_vec	coefs;

	if (ask_coords(&(coefs.x), &(coefs.y), &(coefs.z)))
		return (MALLOC);
	translate_base(camera->pos, dir, coefs);
	return (SUCCESS);
}

int	move_plane(t_plane *plane)
{
	double	x;
	double	y;
	double	z;

	if (ask_coords(&x, &y, &z))
		return (MALLOC);
	plane->pos.x -= x;
	plane->pos.y -= y;
	plane->pos.z -= z;
	return (SUCCESS);
}

int	place_plane(t_plane *plane)
{
	double	x;
	double	y;
	double	z;

	if (ask_coords(&x, &y, &z))
		return (MALLOC);
	plane->pos.x = x;
	plane->pos.y = y;
	plane->pos.z = z;
	return (SUCCESS);
}
