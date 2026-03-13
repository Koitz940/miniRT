/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 10:55:47 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/03/13 01:49:04 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	get_plane_col(t_plane *plane)
{
	return ((plane->r << 16) | (plane->g << 8) | plane->b);
}

int	get_sphere_col(t_sphere *sphere)
{
	return ((sphere->r << 16) | (sphere->g << 8) | sphere->b);
}

int	get_cyl_col(t_cylinder *cylinder)
{
	return ((cylinder->r << 16) | (cylinder->g << 8) | cylinder->b);
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
