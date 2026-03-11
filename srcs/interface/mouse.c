/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 00:35:06 by xwu               #+#    #+#             */
/*   Updated: 2026/03/11 02:04:07 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	put_msg(t_obj type)
{
	ft_putstr_fd("Current figure type: ", 1);
	if (type == PLANE)
		ft_putendl_fd("PLANE", 1);
	else if (type == SPHERE)
		ft_putendl_fd("SPHERE", 1);
	else if (type == CYL_BODY || type == CYL_CAP)
		ft_putendl_fd("CYLINDER", 1);
	ft_putstr_fd("[m] Move figure by (x,y,z)\n[p] Place figure to (x,y,z)
[c] Place figure in relation to the camera\nLeft click to deselect", 1);
}

int	mouse_hook(int key, int x, int y, t_miniRT *rt)
{
	t_obj	type;
	void	*object;

	if (key == RIGHT_CLICK)
	{
		type = rt->screen.screen[WIDTH * y + x].type;
		object = rt->screen.screen[WIDTH * y + x].obj;
		if (type == NONE)
			return (0);
		rt->mouse_select.obj = object;
		rt->mouse_select.type = type;
		put_msg(type);
	}
	else if (key == LEFT_CLICK)
	{
		rt->mouse_select.obj = NULL;
		rt->mouse_select.type = NONE;
	}

	return (0);
}
