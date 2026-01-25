/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ask.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 20:15:39 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/01/25 20:22:04 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	ask_coords3(double *z, char *str)
{
	ft_putendl_fd("Write the z coordinate:", 1);
	while (1)
	{
		str = get_next_line(0);
		if (ft_atod(str, z))
		{
			if (str)
				free(str);
			ft_putendl_fd("Incorrect decimal number, try again:", 1);
		}
		else
			break ;
	}
	return (SUCCESS);
}

static int	ask_coords2(double *y, double *z, char *str)
{
	ft_putendl_fd("Write the y coordinate:", 1);
	while (1)
	{
		str = get_next_line(0);
		if (ft_atod(str, y))
		{
			if (str)
				free(str);
			ft_putendl_fd("Incorrect decimal number, try again:", 1);
		}
		else
			break ;
	}
	return (ask_coords3(z, str));
}

int	ask_coords(double *x, double *y, double *z)
{
	char	*str;

	ft_putendl_fd("Write the x coordinate:", 1);
	while (1)
	{
		str = get_next_line(0);
		if (ft_atod(str, x))
		{
			if (str)
				free(str);
			ft_putendl_fd("Incorrect decimal number, try again:", 1);
		}
		else
			break ;
	}
	ask_coords2(y, z, str);
}
