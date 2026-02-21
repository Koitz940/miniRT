/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 13:05:43 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/02/21 13:28:25 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	choose_color(t_screen *screen, t_pixel *pixel, t_camera *camera)
{

}

int	loop(t_miniRT *rt)
{
	int	i;
	int	j;

	j = 0;
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
			choose_color(rt->screen, rt->screen->screen
				+ (WIDTH * j + i), rt->camera);
			i++;
		}
		j++;
	}
	return (SUCCESS);
}
