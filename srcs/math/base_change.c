/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_change.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 20:08:31 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/02/21 18:50:42 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	move_by(t_vec *vec, t_vec dir, double coef)
{
	vec->x += coef * dir.x;
	vec->y += coef * dir.y;
	vec->z += coef * dir.z;
}

void	translate_base(t_vec *pos, t_camera *cam, t_vec coefs)
{
	move_by(&pos, cam->right, coefs.x);
	move_by(&pos, cam->dir, coefs.y);
	move_by(&pos, cam->up, coefs.z);
}

void	normalise(t_vec *vec)
{
	double	norm;

	norm = sqrt(mod(vec->x, vec->y, vec->z));
	vec->x /= norm;
	vec->y /= norm;
	vec->z /= norm;
}
