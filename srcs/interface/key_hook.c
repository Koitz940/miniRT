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

static int	camera_changes(int key_code, t_miniRT *rt)
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
	reset_screen(rt);
	loop(rt);
	return (1);
}

static int	object_changes(int key_code, t_miniRT *rt)
{
	if (rt->mouse_select.type == NONE)
		return (1);
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
	else
		return (1);
	reset_screen(rt);
	loop(rt);
	return (0);
}

int	key_hook(int keycode, t_miniRT *rt)
{
	if (keycode == XK_Escape)
		free_all(rt);
	else if (keycode == XK_BackSpace)
	{
		rt->mouse_select.obj = NULL;
		rt->mouse_select.type = NONE;
		return (0);
	}
	else if (keycode == XK_l || keycode == XK_L)
	{
		rt->mouse_select.obj = rt->light;
		rt->mouse_select.type = LIGHT;
		current_obj_msg(LIGHT);
	}
	else if (object_changes(keycode, rt) && camera_changes(keycode, rt))
		rt->mouse_select.y = 1;
	return (0);
}

int	key_press(int keycode, t_miniRT *rt)
{
	printf("%d: Keyhook detected: %d\n", ++(rt->mouse_select.x), keycode);
	if (keycode == XK_Escape)
		free_all(rt);
	else if (keycode == XK_Left)
		move_by(&rt->camera->pos, rt->camera->right, -SPEED);
	else if (keycode == XK_Right)
		move_by(&rt->camera->pos, rt->camera->right, SPEED);
	else if (keycode == XK_Up)
		move_by(&rt->camera->pos, rt->camera->up, SPEED);
	else if (keycode == XK_Down)
		move_by(&rt->camera->pos, rt->camera->up, -SPEED);
	//else if (key_hook(keycode, rt))

	return (0);
}

int	key_release(int key_code, t_miniRT *rt)
{
	(void)key_code;
	reset_screen(rt);
	loop(rt);
	return (0);
}
