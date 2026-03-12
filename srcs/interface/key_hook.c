/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 19:31:53 by xwu               #+#    #+#             */
/*   Updated: 2026/03/11 19:31:53 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/* KEY SHORTCUTS
- [ESC]	close program
- [BackSpace]	deselect figure
- [l]	select light
- [m] && [obj selected]	move obj (relative)
- [p] && [obj selected]	move obj (absolute)
- [c] && [obj selected]	move obj (relative to camera)
- [r] && [obj selected]	rotate obj
- [s] && [obj selected]	rotate obj
- [m]	move obj (relative)
- [p]	move camera (absolute)
- [c]	move camera (relative to camera)
- [r]	rotate camera
*/

static void	camera_changes(int key_code, t_miniRT *rt)
{
	if ((key_code == XK_c || key_code == XK_C)
		&& rt->mouse_select.type == NONE)
		move_cam_from(rt->camera, rt);
	else if ((key_code == XK_p || key_code == XK_P)
		&& rt->mouse_select.type == NONE)
		place_cam(rt->camera, rt);
	else if ((key_code == XK_m || key_code == XK_M)
		&& rt->mouse_select.type == NONE)
		move_cam(rt->camera, rt);
	else if (key_code == XK_f)
		ask_fov(&rt->camera->fov);
	else if (key_code == XK_F)
		ask_change_fov(&rt->camera->fov);
}

int	key_press(int key_code, t_miniRT *rt)
{
	if (key_code == XK_Left)
		move_by(&rt->camera->pos, rt->camera->right, -SPEED);
	else if (key_code == XK_Right)
		move_by(&rt->camera->pos, rt->camera->right, SPEED);
	else if (key_code == XK_Up)
		move_by(&rt->camera->pos, rt->camera->up, SPEED);
	else if (key_code == XK_Down)
		move_by(&rt->camera->pos, rt->camera->up, -SPEED);
	return (0);
}

int	key_release(int key_code, t_miniRT *rt)
{
	(void)key_code;
	loop(rt);
	return (0);
}

static void	object_changes(int key_code, t_miniRT *rt)
{
	if (rt->mouse_select.type == NONE)
		return ;
	if (key_code == XK_m || key_code == XK_M)
		move_figure(rt->mouse_select.type, rt->mouse_select.obj, rt);
	else if (key_code == XK_p || key_code == XK_P)
		place_figure(rt->mouse_select.type, rt->mouse_select.obj, rt);
	else if (key_code == XK_c || key_code == XK_C)
		move_figure_from(rt->mouse_select.type, rt->mouse_select.obj, rt);
	else if (key_code == XK_F || key_code == XK_f)
		resize_figure(rt->mouse_select.type, rt->mouse_select.obj, rt);
	else if (key_code == XK_r || key_code == XK_R)
		rotate_figure(rt->mouse_select.type, rt->mouse_select.obj, rt);
}

int	key_hook(int key_code, t_miniRT *rt)
{
	if (key_code == XK_Escape)
		free_all(rt);
	else if (key_code == XK_BackSpace)
	{
		rt->mouse_select.obj = NULL;
		rt->mouse_select.type = NONE;
		return (0);
	}
	else if (key_code == XK_l || key_code == XK_L)
	{
		rt->mouse_select.obj = rt->light;
		rt->mouse_select.type = LIGHT;
		current_obj_msg(LIGHT);
	}
	object_changes(key_code, rt);
	camera_changes(key_code, rt);
	loop(rt);
	return (0);
}
