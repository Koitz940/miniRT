/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 11:24:49 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/02/21 11:40:46 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec	apply_x(t_vec vec, t_camera *camera, double c, double s)
{
	t_vec	new;
	t_vec	aux;

	aux.x = camera->right.x;
	aux.y = camera->dir.x * c + camera->up.x * s;
	aux.z = -camera->dir.x * s + camera->up.x * c;
	new.x = dot_prod(aux, vec);
	aux.x = camera->right.y;
	aux.y = camera->dir.y * c + camera->up.y * s;
	aux.z = -camera->dir.y * s + camera->up.y * c;
	new.y = dot_prod(aux, vec);
	aux.x = camera->right.z;
	aux.y = camera->dir.z * c + camera->up.z * s;
	aux.z = -camera->dir.z * s + camera->up.z * c;
	new.z = dot_prod(aux, vec);
	return (new);
}

t_vec	apply_y(t_vec vec, t_camera *camera, double c, double s)
{
	t_vec	new;
	t_vec	aux;

	aux.x = camera->right.x * c + camera->up.x * s;
	aux.y = camera->dir.x;
	aux.z = -camera->right.x * s + camera->up.x * c;
	new.x = dot_prod(aux, vec);
	aux.x = camera->right.y * c + camera->up.y * s;
	aux.y = camera->dir.y;
	aux.z = -camera->right.y * s + camera->up.y * c;
	new.y = dot_prod(aux, vec);
	aux.x = camera->right.z * c + camera->up.z * s;
	aux.y = camera->dir.z;
	aux.z = -camera->right.z * s + camera->up.z * c;
	new.z = dot_prod(aux, vec);
	return (new);
}

t_vec	apply_z(t_vec vec, t_camera *camera, double c, double s)
{
	t_vec	new;
	t_vec	aux;

	aux.x = camera->right.x * c + camera->dir.x * s;
	aux.y = -camera->right.x * s + camera->dir.x * c;
	aux.z = camera->up.x;
	new.x = dot_prod(aux, vec);
	aux.x = camera->right.y * c + camera->dir.y * s;
	aux.y = -camera->right.y * s + camera->dir.y * c;
	aux.z = camera->up.y;
	new.y = dot_prod(aux, vec);
	aux.x = camera->right.z * c + camera->dir.z * s;
	aux.y = -camera->right.z * s + camera->dir.z * c;
	aux.z = camera->up.z;
	new.z = dot_prod(aux, vec);
	return (new);
}
