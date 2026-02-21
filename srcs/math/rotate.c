/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 20:21:56 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/02/21 11:26:04 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec	rotate_x(t_vec vec, double angle)
{
	t_vec	new;

	new.x = vec.x;
	new.y = vec.y * cos(angle) - vec.z * sin(angle);
	new.z = vec.z * cos(angle) + vec.y * sin(angle);
	return (new);
}

t_vec	rotate_y(t_vec vec, double angle)
{
	t_vec	new;

	new.y = vec.y;
	new.x = vec.x * cos(angle) - vec.z * sin(angle);
	new.z = vec.z * cos(angle) + vec.x * sin(angle);
	return (new);
}

t_vec	rotate_z(t_vec vec, double angle)
{
	t_vec	new;

	new.z = vec.z;
	new.y = vec.y * cos(angle) - vec.x * sin(angle);
	new.x = vec.x * cos(angle) + vec.y * sin(angle);
	return (new);
}

t_vec	rotate_dir(t_vec vec, t_camera *camera, t_vec coefs)
{
	double	c;
	double	s;
	t_vec	new;

	new.x = dot_prod(camera->right, vec);
	new.y = dot_prod(camera->dir, vec);
	new.z = dot_prod(camera->up, vec);
	c = cos(coefs.x);
	s = sin(coefs.x);
	new = apply_x(new, camera, c, s);
	c = cos(coefs.y);
	s = sin(coefs.y);
	new = apply_y(new, camera, c, s);
	c = cos(coefs.z);
	s = sin(coefs.z);
	new = apply_z(new, camera, c, s);
	return (new);
}
