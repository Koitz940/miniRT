/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 20:42:14 by xwu               #+#    #+#             */
/*   Updated: 2026/03/11 20:42:14 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	move_figure(t_obj type, void *object, t_miniRT *rt)
{
	if (type == PLANE)
		move_plane(object, rt);
	else if (type == SPHERE)
		move_sphere(object, rt);
	else if (type == CYL_BODY || type == CYL_CAP)
		move_cylinder(object, rt);
	else if (type == LIGHT)
		move_light(object, rt);
	rt->mouse_select.obj = NULL;
	rt->mouse_select.type = NONE;
	reset_screen(rt);
}

void	place_figure(t_obj type, void *object, t_miniRT *rt)
{
	if (type == PLANE)
		place_plane(object, rt);
	else if (type == SPHERE)
		place_sphere(object, rt);
	else if (type == CYL_BODY || type == CYL_CAP)
		place_cylinder(object, rt);
	else if (type == LIGHT)
		place_light(object, rt);
	rt->mouse_select.obj = NULL;
	rt->mouse_select.type = NONE;
	reset_screen(rt);
}

void	move_figure_from(t_obj type, void *object, t_miniRT *rt)
{
	if (type == PLANE)
		move_plane_from(object, rt);
	else if (type == SPHERE)
		move_sphere_from(object, rt);
	else if (type == CYL_BODY || type == CYL_CAP)
		move_cylinder_from(object, rt);
	else if (type == LIGHT)
		move_light_from(object, rt);
	rt->mouse_select.obj = NULL;
	rt->mouse_select.type = NONE;
	reset_screen(rt);
}

void	resize_figure(t_obj type, void *obj, t_miniRT *rt)
{
	(void)type;
	(void)obj;
	(void)rt;
}
void	rotate_figure(t_obj type, void *obj, t_miniRT *rt)
{
	(void)type;
	(void)obj;
	(void)rt;
}
