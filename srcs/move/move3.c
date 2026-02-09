/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 20:15:37 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/02/09 20:15:56 by gcassi-d         ###   ########.fr       */
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
	sphere->x -= x;
	sphere->y -= y;
	sphere->z -= z;
	return (SUCCESS);
}

int	place_sphere(t_sphere *sphere)
{
	double	x;
	double	y;
	double	z;

	if (ask_coords(&x, &y, &z))
		return (MALLOC);
	sphere->x = x;
	sphere->y = y;
	sphere->z = z;
	return (SUCCESS);
}