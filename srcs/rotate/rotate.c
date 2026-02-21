/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 20:16:27 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/02/20 21:11:04 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	rotate_cam(t_camera *camera, t_miniRT *rt)
{
	double	x;
	t_vec	new_dir;

	(void)rt;
	ft_putendl_fd("Asking for rotation angle over the x axis: ", 1);
	if (ask_factor(&x))
		return (malloc);
	new_dir = rotate();
}