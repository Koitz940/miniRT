/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross-product.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 19:05:02 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/02/18 20:49:39 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec	vec_prod(t_vec a, t_vec b)
{
	t_vec	new;
	double	norm;

	new.x = a.y * b.z - a.z * b.y;
	new.y = a.z * b.x - a.x * b.z;
	new.z = a.x * b.y - a.y * b.x;
	norm = sqrt(mod(new.x, new.y, new.z));
	new.x /= norm;
	new.y /= norm;
	new.z /= norm;
	return (new);
}

double	doc_prod(t_vec a, t_vec b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vec	new_vec(double x, double y, double z)
{
	t_vec	new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}

t_vec	get_right(t_vec a)
{
	t_vec	worldup;

	worldup.x = 0;
	worldup.y = 0;
	worldup.z = 0;
	if (!a.x && !a.z)
		worldup.z = 1;
	else
		worldup.y = 1;
	return (vec_prod(a, worldup));
}
