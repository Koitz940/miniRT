/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 20:24:00 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/01/21 13:45:56 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	start(t_miniRT *rt)
{
	printf("%f %f %f  %f %f %f  %f\n", rt->camera->x, rt->camera->y, rt->camera->z, rt->camera->xdir, rt->camera->ydir, rt->camera->zdir, rt->camera->fov);
	printf("%f %f %f  %i %i %i  %f\n", rt->light->x, rt->light->y, rt->light->z, rt->light->r, rt->light->g, rt->light->b, rt->light->bright);
	printf("%i %i %i  %f\n", rt->ambient_light->r, rt->ambient_light->g, rt->ambient_light->b, rt->ambient_light->bright);
	printf("%u %f %f %i\n", rt->spheres->length, rt->spheres->spheres[0].x, rt->spheres->spheres[1].d, rt->spheres->spheres[2].b);
	printf("%u  %f %f %f  %f %f %f  %i %i %i\n", rt->planes->length, rt->planes->planes[0].x, rt->planes->planes[0].y, rt->planes->planes[0].z, rt->planes->planes[0].xdir, rt->planes->planes[0].ydir, rt->planes->planes[0].zdir, rt->planes->planes[0].r, rt->planes->planes[0].g, rt->planes->planes[0].b);
	printf("%u  %f %f %f  %f %f %f  %f  %f  %i %i %i\n", rt->cylinders->length, rt->cylinders->cylinders[0].x, rt->cylinders->cylinders[0].y, rt->cylinders->cylinders[0].z, rt->cylinders->cylinders[0].xdir, rt->cylinders->cylinders[0].ydir, rt->cylinders->cylinders[0].zdir, rt->cylinders->cylinders[0].d, rt->cylinders->cylinders[0].h, rt->cylinders->cylinders[0].r, rt->cylinders->cylinders[0].g, rt->cylinders->cylinders[0].b);
}
