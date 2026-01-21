/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 20:24:00 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/01/21 12:21:23 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	start(t_miniRT *rt)
{
	printf("%f %f %f  %f %f %f  %f\n", rt->camera->x, rt->camera->y, rt->camera->z, rt->camera->xdir, rt->camera->ydir, rt->camera->zdir, rt->camera->fov);
	printf("%f %f %f  %i %i %i  %f\n", rt->light->x, rt->light->y, rt->light->z, rt->light->r, rt->light->g, rt->light->b, rt->light->bright);
	printf("%i %i %i  %f\n", rt->ambient_light->r, rt->ambient_light->g, rt->ambient_light->b, rt->ambient_light->bright);
}
