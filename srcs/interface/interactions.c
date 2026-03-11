/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 17:24:33 by xwu               #+#    #+#             */
/*   Updated: 2026/03/11 02:29:18 by xwu              ###   ########.fr       */
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
}

void	place_figure(t_obj type, void *object, t_miniRT *rt)
{
	if (type == PLANE)
		place_plane(object, rt);
	else if (type == SPHERE)
		place_sphere(object, rt);
	else if (type == CYL_BODY || type == CYL_CAP)
		place_cylinder(object, rt);
}

void	move_figure_from(t_obj type, void *object, t_miniRT *rt)
{
	if (type == PLANE)
		move_plane_from(object, rt);
	else if (type == SPHERE)
		move_sphere_from(object, rt);
	else if (type == CYL_BODY || type == CYL_CAP)
		move_cylinder_from(object, rt);
}

int	key_hook(int key_code, t_miniRT *rt)
{
	if (key_code == XK_Escape)
		exit_rt(rt);
	if (key_code == XK_f)
		ask_fov(&rt->camera.fov);
	else if (key_code == XK_F)
		ask_change_fov(&rt->camera.fov);
	else if (key_code == XK_z || key_code == XK_Z)
		ask_factor(&rt->camera.f);
	else if ((key_code == XK_m || key_code == XK_M)
		&& rt->mouse_select.type != NONE)
		move_figure(rt->mouse_select.type, rt->mouse_select.obj, rt);
	else if ((key_code == XK_p || key_code == XK_P)
		&& rt->mouse_select.type != NONE)
		place_figure(rt->mouse_select.type, rt->mouse_select.obj, rt);
	else if ((key_code == XK_c || key_code == XK_C)
		&& rt->mouse_select.type != NONE)
		move_figure_from(rt->mouse_select.type, rt->mouse_select.obj, rt);
	loop(rt);
	return (0);
}

int	key_press(int key_code, t_miniRT *rt)
{
	return (0);
}

int	key_release(int key_code, t_miniRT *rt)
{
	return (0);
}

int	mlx_hooks(t_miniRT *rt)
{
	mlx_hook(rt->screen->window, ON_DESTROY, 0, free_all, rt);
	mlx_hook(rt->screen->window, ON_KEYDOWN, 1L << 0, key_press, rt);
	mlx_hook(rt->screen->window, ON_KEYUP, 1L << 1, key_release, rt);
	mlx_key_hook(rt->screen->window, key_hook, rt);
	mlx_mouse_hook(rt->screen->window, mouse_hook, rt);
	mlx_loop(rt->screen->mlx);
}
