/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:56:46 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/01/21 00:12:53 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	ft_atod(char *str, double *x)
{
	(void)str;
	(void)x;
	*x = 1.0;
	return (SUCCESS);
}

int	ft_ft_atoi(char *str, int *n)
{
	(void)str;
	(void)n;
	*n = 1;
	return (SUCCESS);
}

size_t	split_len(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

double	mod(double x, double y, double z)
{
	return (x * x + y * y + z * z);
}

int	is_color(int r, int g, int b)
{
	return (r < 256 && r >= 0 && g < 256
		&& g >= 0 && b < 256 && b >= 0);
}
