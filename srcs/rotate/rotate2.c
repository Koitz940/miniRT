/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 12:54:02 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/02/21 12:54:36 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	rotate_cylinder(t_cylinder *cylinder, t_miniRT *rt)
{
	double	x;
	t_vec	new_dir;

	(void)rt;
	ft_putendl_fd("Asking for rotation angle over the x axis\n", 1);
	if (ask_factor(&x))
		return (MALLOC);
	new_dir = rotate_x(cylinder->dir, x);
	ft_putendl_fd("Asking for rotation angle over the y axis\n", 1);
	if (ask_factor(&x))
		return (MALLOC);
	new_dir = rotate_y(new_dir, x);
	ft_putendl_fd("Asking for rotation angle over the y axis\n", 1);
	if (ask_factor(&x))
		return (MALLOC);
	new_dir = rotate_z(new_dir, x);
	cylinder->dir = new_dir;
	normalise(&new_dir);
	return (SUCCESS);
}

int	rotate_cylinder_cam(t_cylinder *cylinder, t_miniRT *rt)
{
	t_vec	coefs;
	t_vec	new_dir;

	(void)rt;
	ft_putendl_fd("Asking for rotation angle over the x\
		 axis of the camera\n", 1);
	if (ask_factor(&(coefs.x)))
		return (MALLOC);
	ft_putendl_fd("Asking for rotation angle over the y\
		 axis of the camra\n", 1);
	if (ask_factor(&(coefs.y)))
		return (MALLOC);
	ft_putendl_fd("Asking for rotation angle over the z\
		 axis of the camera\n", 1);
	if (ask_factor(&(coefs.z)))
		return (MALLOC);
	new_dir = rotate_dir(cylinder->dir, cylinder, coefs);
	cylinder->dir = new_dir;
	return (SUCCESS);
}
