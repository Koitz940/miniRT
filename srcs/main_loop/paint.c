/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 17:06:36 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/02/21 19:28:58 by gcassi-d         ###   ########.fr       */
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
