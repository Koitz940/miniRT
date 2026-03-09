/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 20:24:00 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/03/08 19:39:29 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void print_vec(t_vec vec)
{
	printf("%lf %lf %lf\n", vec.x, vec.y, vec.z);
}

void	start(t_miniRT *rt)
{
	print_vec(rt->camera->right);
	print_vec(rt->camera->dir);
	print_vec(rt->camera->up);
	loop(rt);
	mlx_hook(rt->screen->window, 17, 0, free_all, rt);
	mlx_key_hook(rt->screen->window, key_hook, rt);
	mlx_loop(rt->screen->mlx);
}
