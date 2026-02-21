/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 12:18:14 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/02/21 12:26:49 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	plus_fov(t_camera *cam)
{
	int	new_fov;

	new_fov = cam->fov + FOV;
	if (new_fov > 180)
		return (SUCCESS);
	cam->fov = new_fov;
	return (SUCCESS);
}

int	minus_fov(t_camera *cam)
{
	int	new_fov;

	new_fov = cam->fov - FOV;
	if (new_fov <= 0)
		return (SUCCESS);
	cam->fov = new_fov;
	return (SUCCESS);
}
