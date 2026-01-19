/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 21:52:18 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/01/14 22:27:35 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_H
# define PLANE_H

typedef struct s_plane
{
	double	x;
	double	y;
	double	z;
	double	xdir;
	double	ydir;
	double	zdir;
	int		r;
	int		g;
	int		b;
}	t_plane;

typedef struct s_plane_vec
{
	t_plane			*planes;
	unsigned int	capacity;
	unsigned int	length;
}	t_planes;

void	free_planes(t_planes *planes);

#endif
