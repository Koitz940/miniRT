/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:48:19 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/01/19 18:49:33 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

typedef struct s_sphere
{
	double	x;
	double	y;
	double	z;
	double	d;
	int		r;
	int		g;
	int		b;
}	t_sphere;

typedef struct s_sphere_vec
{
	t_sphere		*spheres;
	unsigned int	capacity;
	unsigned int	length;
}	t_spheres;

void	free_spheres(t_spheres *spheres);

#endif