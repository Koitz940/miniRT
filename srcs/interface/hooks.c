/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 17:24:33 by xwu               #+#    #+#             */
/*   Updated: 2026/03/14 02:28:15 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	current_obj_msg(t_obj type)
{
	ft_putstr_fd("Current figure type: ", 1);
	if (type == PLANE)
		ft_putendl_fd("PLANE", 1);
	else if (type == SPHERE)
		ft_putendl_fd("SPHERE", 1);
	else if (type == LIGHT)
		ft_putendl_fd("LIGHT", 1);
	else if (type == CYL_BODY || type == CYL_CAP)
		ft_putendl_fd("CYLINDER", 1);
	ft_putendl_fd("[m] Move figure by (x,y,z)\n[p] Place figure to (x,y,z)\n\
[c] Place figure in relation to the camera\nRight click to deselect", 1);
}

void	reset_screen(t_miniRT *rt)
{
	size_t	i;
	size_t	j;

	j = -1;
	while (++j < HEIGHT)
	{
		i = -1;
		while (++i < WIDTH)
		{
			rt->screen->screen[j * WIDTH + i].obj = NULL;
			rt->screen->screen[j * WIDTH + i].type = NONE;
			rt->screen->screen[j * WIDTH + i].t = INFINITY;
		}
	}
}

void	mlx_hooks(t_miniRT *rt)
{
	mlx_hook(rt->screen->window, ON_DESTROY, 0, free_all, rt);
	mlx_hook(rt->screen->window, ON_KEYDOWN, 1L << 0, key_press, rt);
	mlx_hook(rt->screen->window, ON_KEYUP, 1L << 1, key_release, rt);
	mlx_loop(rt->screen->mlx);
}
