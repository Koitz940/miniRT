/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 17:24:33 by xwu               #+#    #+#             */
/*   Updated: 2026/03/08 19:52:42 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	key_hook(int key_code, t_miniRT *rt)
{
	if (key_code == XK_Escape)
		exit_rt(rt);
	if (key_code == XK_f || key_code == XK_F)
		
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

int	mouse_hook(int keycode, int x, int y, t_miniRT *rt)
{
	return (0);
}

int	mlx_hooks(t_miniRT *rt)
{
	mlx_hook(rt->screen->window, ON_DESTROY, 0, exit_rt, rt);
	mlx_hook(rt->screen->window, ON_KEYDOWN, 1L << 0, key_press, rt);
	mlx_hook(rt->screen->window, ON_KEYUP, 1L << 1, key_release, rt);
	mlx_mouse_hook(rt->screen->window, mouse_hook, rt);
	mlx_loop(rt->screen->mlx);
}
