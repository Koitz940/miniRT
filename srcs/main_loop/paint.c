/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 17:06:36 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/03/10 11:07:02 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	paint(t_miniRT *rt, t_pixel *point, int p)
{
	char	*dst;

	dst = rt->screen->img_addr + (point->y * rt->screen->img_length + point->x
			* (rt->screen->bits_per_pixel / 8));
	*(unsigned int *)dst = p;
}

int	get_col(t_pixel *pixel)
{
	if (!pixel->type)
		return (0);
	else if (pixel->type == PLANE)
		return (get_plane_col((t_plane *)pixel->obj));
	else if (pixel->type == SPHERE)
		return (get_sphere_col((t_sphere *)pixel->obj));
	else if (pixel->type == CYL_BODY || pixel->type == CYL_CAP)
		return (get_cyl_col((t_cylinder *)pixel->obj));
	return (0);
}

void	set_true_col(void);
