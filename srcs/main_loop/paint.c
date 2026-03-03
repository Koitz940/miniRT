/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 17:06:36 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/03/01 14:32:36 by gcassi-d         ###   ########.fr       */
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
	return (pixel->b + 256 * (pixel->g + 256 * pixel->r));
}

void	set_col(t_pixel *pixel, int r, int g, int b)
{
	pixel->r = r;
	pixel->g = g;
	pixel->b = b;
}
