/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 20:24:00 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/03/13 02:29:08 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	print_vec(t_vec vec)
{
	printf("%lf %lf %lf\n", vec.x, vec.y, vec.z);
}

void	start(t_miniRT *rt)
{
	print_vec(rt->camera->right);
	print_vec(rt->camera->dir);
	print_vec(rt->camera->up);
	for (int i = 0; i < WIDTH * HEIGHT; i++)
	{
		if (rt->screen->screen->t < TOL)
			printf("%lf %i %i", rt->screen->screen->t, rt->screen->screen->x, rt->screen->screen->y);
	}
	loop(rt);
	mlx_hooks(rt);
}
