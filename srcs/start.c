/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 20:24:00 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/02/21 12:41:41 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	start(t_miniRT *rt)
{
	printf("%f %f %f  %f %f %f  %i\n", rt->camera->pos.x, rt->camera->pos.y, rt->camera->pos.z, rt->camera->dir.x, rt->camera->dir.y, rt->camera->dir.z, rt->camera->fov);
	printf("%f %f %f  %i %i %i  %f\n", rt->light->pos.x, rt->light->pos.y, rt->light->pos.z, rt->light->r, rt->light->g, rt->light->b, rt->light->bright);
	printf("%i %i %i  %f\n", rt->ambient_light->r, rt->ambient_light->g, rt->ambient_light->b, rt->ambient_light->bright);
	printf("%u %f %f %i\n", rt->spheres->length, rt->spheres->spheres[0].pos.x, rt->spheres->spheres[1].d, rt->spheres->spheres[2].b);
	printf("%u  %f %f %f  %f %f %f  %i %i %i\n", rt->planes->length, rt->planes->planes[0].pos.x, rt->planes->planes[0].pos.y, rt->planes->planes[0].pos.z, rt->planes->planes[0].dir.x, rt->planes->planes[0].dir.y, rt->planes->planes[0].dir.z, rt->planes->planes[0].r, rt->planes->planes[0].g, rt->planes->planes[0].b);
	printf("%u  %f %f %f  %f %f %f  %f  %f  %i %i %i\n", rt->cylinders->length, rt->cylinders->cylinders[0].pos.x, rt->cylinders->cylinders[0].pos.y, rt->cylinders->cylinders[0].pos.z, rt->cylinders->cylinders[0].dir.x, rt->cylinders->cylinders[0].dir.y, rt->cylinders->cylinders[0].dir.z, rt->cylinders->cylinders[0].d, rt->cylinders->cylinders[0].h, rt->cylinders->cylinders[0].r, rt->cylinders->cylinders[0].g, rt->cylinders->cylinders[0].b);
}
