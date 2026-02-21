/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 20:16:27 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/02/21 12:59:02 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	rotate_cam(t_camera *camera, t_miniRT *rt)
{
	double	x;
	t_vec	new_dir;

	(void)rt;
	ft_putendl_fd("Asking for rotation angle over the x axis\n", 1);
	if (ask_factor(&x))
		return (MALLOC);
	new_dir = rotate_x(camera->dir, x);
	ft_putendl_fd("Asking for rotation angle over the y axis\n", 1);
	if (ask_factor(&x))
		return (MALLOC);
	new_dir = rotate_y(new_dir, x);
	ft_putendl_fd("Asking for rotation angle over the y axis\n", 1);
	if (ask_factor(&x))
		return (MALLOC);
	new_dir = rotate_z(new_dir, x);
	camera->dir = new_dir;
	normalise(&new_dir);
	camera->right = get_right(camera->right);
	camera->up = vec_prod(camera->right, camera->dir);
	return (SUCCESS);
}

int	rotate_cam_cam(t_camera *camera, t_miniRT *rt)
{
	t_vec	coefs;
	t_vec	new_dir;

	(void)rt;
	ft_putendl_fd("Asking for rotation angle over the x\
		 axis of the camera\n", 1);
	if (ask_factor(&(coefs.x)))
		return (MALLOC);
	ft_putendl_fd("Asking for rotation angle over the y\
		 axis of the camera\n", 1);
	if (ask_factor(&(coefs.y)))
		return (MALLOC);
	ft_putendl_fd("Asking for rotation angle over the z\
		 axis of the camera\n", 1);
	if (ask_factor(&(coefs.z)))
		return (MALLOC);
	new_dir = rotate_dir(camera->dir, camera, coefs);
	camera->dir = new_dir;
	normalise(&new_dir);
	camera->right = get_right(camera->right);
	camera->up = vec_prod(camera->right, camera->dir);
	return (SUCCESS);
}

int	rotate_plane(t_plane *plane, t_miniRT *rt)
{
	double	x;
	t_vec	new_dir;

	(void)rt;
	ft_putendl_fd("Asking for rotation angle over the x axis\n", 1);
	if (ask_factor(&x))
		return (MALLOC);
	new_dir = rotate_x(plane->dir, x);
	ft_putendl_fd("Asking for rotation angle over the y axis\n", 1);
	if (ask_factor(&x))
		return (MALLOC);
	new_dir = rotate_y(new_dir, x);
	ft_putendl_fd("Asking for rotation angle over the y axis\n", 1);
	if (ask_factor(&x))
		return (MALLOC);
	new_dir = rotate_z(new_dir, x);
	plane->dir = new_dir;
	normalise(&new_dir);
	return (SUCCESS);
}

int	rotate_plane_cam(t_plane *plane, t_miniRT *rt)
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
	new_dir = rotate_dir(plane->dir,rt->camera, coefs);
	plane->dir = new_dir;
	return (SUCCESS);
}
