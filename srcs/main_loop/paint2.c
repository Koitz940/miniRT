/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 10:55:47 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/03/10 11:03:13 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	get_plane_col(t_plane *plane)
{
	return (plane->r + 256 * (plane->g + 256 * plane->b));
}

int	get_sphere_col(t_sphere *sphere)
{
	return (sphere->r + 256 * (sphere->g + 256 * sphere->b));
}

int	get_cyl_col(t_cylinder *cylinder)
{
	return (cylinder->r + 256 * (cylinder->g + 256 * cylinder->b));
}

int	set_cyl_cap(t_pixel *px, t_cylinder *cyl, double t)
{
	px->t = t;
	px->obj = cyl;
	px->type = CYL_CAP;
	return (1);
}

int	set_cyl_body(t_pixel *px, t_cylinder *cyl, double t)
{
	px->t = t;
	px->obj = cyl;
	px->type = CYL_BODY;
	return (1);
}
