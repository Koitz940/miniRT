/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 21:47:27 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/01/14 22:28:28 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H

typedef struct s_cylinder
{
	double	x;
	double	y;
	double	z;
	double	xdir;
	double	ydir;
	double	zdir;
	double	d;
	double	h;
	int		r;
	int		g;
	int		b;
}	t_cylinder;

typedef struct s_cylinder_vec
{
	t_cylinder		*cylinders;
	unsigned int	capacity;
	unsigned int	length;
}	t_cylinders;

void	free_cylinders(t_cylinders *cylinders);

#endif
