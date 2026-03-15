/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 21:47:27 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/03/15 13:15:46 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H

typedef struct s_cylinder
{
	t_vec	pos;
	t_vec	dir;
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

typedef struct s_why
{
	t_vec	vt;
	t_vec	wt;
	t_vec	q;
	t_vec	dir;
	t_vec	w;
}	t_why;

void	free_cylinders(t_cylinders *cylinders);

#endif
