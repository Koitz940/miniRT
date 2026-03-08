/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ask.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 20:15:39 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/03/08 20:21:28 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	ask_coords3(double *z, char *str)
{
	ft_putendl_fd("Write the z coordinate: ", 1);
	while (1)
	{
		str = get_next_line(0);
		if (ft_atod(str, z))
		{
			if (!str)
				return (MALLOC);
			free(str);
			ft_putendl_fd("Incorrect decimal number, try again:", 1);
		}
		else
		{
			free(str);
			break ;
		}
	}
	return (SUCCESS);
}

static int	ask_coords2(double *y, double *z, char *str)
{
	ft_putendl_fd("Write the y coordinate: ", 1);
	while (1)
	{
		str = get_next_line(0);
		if (ft_atod(str, y))
		{
			if (!str)
				return (MALLOC);
			free(str);
			ft_putendl_fd("Incorrect decimal number, try again:", 1);
		}
		else
		{
			free(str);
			break ;
		}
	}
	return (ask_coords3(z, str));
}

int	ask_coords(double *x, double *y, double *z)
{
	char	*str;

	ft_putendl_fd("Write the x coordinate: ", 1);
	while (1)
	{
		str = get_next_line(0);
		if (ft_atod(str, x))
		{
			if (!str)
				return (MALLOC);
			free(str);
			ft_putendl_fd("Incorrect decimal number, try again:", 1);
		}
		else
		{
			free(str);
			break ;
		}
	}
	return (ask_coords2(y, z, str));
}

int	ask_factor(double *x)
{
	char	*str;

	ft_putendl_fd("Write the factor: ", 1);
	while (1)
	{
		str = get_next_line(0);
		if (ft_atod(str, x))
		{
			if (!str)
				return (MALLOC);
			free(str);
			ft_putendl_fd("Incorrect decimal number, try again: ", 1);
		}
		else
		{
			free(str);
			break ;
		}
	}
	return (SUCCESS);
}

int	ask_fov(int *x)
{
	char	*str;

	write_ask_fov(x);
	while (1)
	{
		str = get_next_line(0);
		if (ft_ft_atoi(str, x))
		{
			if (!str)
				return (MALLOC);
			free(str);
			ft_putendl_fd("Incorrect decimal number, try again: ", 1);
		}
		else
		{
			free(str);
			if (*x > 0 && *x <= 180)
				break ;
			else
				ft_putendl_fd("FOV is a number in\
					 the range [1, 180], try again: ", 1);
		}
	}
	return (SUCCESS);
}
