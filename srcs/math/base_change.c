/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_change.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 20:08:31 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/02/18 20:53:17 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	move_by(t_vec vec, t_vec dir, double coef)
{
	vec.x += coef * dir.x;
	vec.y += coef * dir.y;
	vec.z += coef * dir.z;
}

void	translate_base(t_vec vec, t_vec dir, t_vec coefs)
{
	t_vec	r;
	t_vec	u;

	r = get_left(dir);
	u = vec_prod(r, u);

	move_by(vec, r, coefs.x);
	move_by(vec, dir, coefs.y);
	move_by(vec, u, coefs.z);
}
