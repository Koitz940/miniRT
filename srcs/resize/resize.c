/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 19:16:42 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/02/11 19:36:36 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	resize_sphere(t_sphere *sphere)
{
	double	x;

	ft_putendl_fd("Resizing sphere's diametre, asking for scaling factor", 1);
	if (ask_factor(&x))
		return (MALLOC);
	sphere->d *= x;
	return (SUCCESS);
}

int	resize_cylinder(t_cylinder *cylinder)
{
	double	x;

	ft_putendl_fd("Resizing cylinder's diametre, asking for scaling factor", 1);
	if (ask_factor(&x))
		return (MALLOC);
	cylinder->d *= x;
	ft_putendl_fd("Resizing cylinder's height, asking for scaling factor", 1);
	if (ask_factor(&x))
		return (MALLOC);
	cylinder->h *= x;
	return (SUCCESS);
}

int	resize_cylinder(t_cylinder *cylinder)
{
	double	x;

	ft_putendl_fd("Resizing cylinder's diametre, asking for scaling factor", 1);
	if (ask_factor(&x))
		return (MALLOC);
	cylinder->d *= x;
	ft_putendl_fd("Resizing cylinder's height, asking for scaling factor", 1);
	if (ask_factor(&x))
		return (MALLOC);
	cylinder->h *= x;
	return (SUCCESS);
}
