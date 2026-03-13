/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:56:46 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/03/13 12:38:11 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	add_decimals(char *str, size_t dot, double sign, double *x)
{
	double	decimal;
	size_t	i;

	i = ft_strlen(str) - 1;
	printf("%s",str);
	decimal = 0.0;
	while (--i != dot)
	{
		if (str[i] < '0' || str[i] > '9')
			return (UNKNOWN_SPECIFIER);
		decimal = decimal / 10 + str[i] - '0';
	}
	decimal /= 10;
	*x += decimal;
	*x *= sign;
	return (SUCCESS);
}

int	add_wholeparts(char *str, size_t i, double n)
{
	while (str[i] && str[i] != '.')
	{
		if (str[i] < '0' || str[i] > '9')
			return (UNKNOWN_SPECIFIER);
		n= n * 10.0 + (double)(str[i++] - '0');
		if (n == INFINITY)
			return (WRONG_SPECIFIER);
	}
	return (SUCCESS);
}

int	ft_atod(char *str, double *x)
{
	size_t	i;
	double	sign;
	double	n;
	int		status;
	if (!str || !str[0] || !ft_strncmp(".", str, 2)
		|| !ft_strncmp("+.", str, 3) || !ft_strncmp("-.", str, 3))
		return (UNKNOWN_SPECIFIER);
	i = 0;
	sign = 1.0;
	n = 0.0;
	if (str[0] == '+' || str[0] == '-')
	{
		if (str[i++] == '-')
			sign = -1.0;
	}
	status = add_wholeparts(str, i, n);
	if (status)
		return (status);
	*x = n;
	if (str[i])
		return (add_decimals(str, i, sign, x));
	*x *= sign;
	return (SUCCESS);
}

int	ft_ft_atoi(char *str, int *n)
{
	size_t	i;

	*n = 0;
	if (!str || !str[0])
		return (UNKNOWN_SPECIFIER);
	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (UNKNOWN_SPECIFIER);
		*n = *n * 10 + str[i++] - '0';
		if (*n > 255)
			return (WRONG_SPECIFIER);
	}
	return (SUCCESS);
}

int	is_color(int r, int g, int b)
{
	return (r < 256 && r >= 0 && g < 256
		&& g >= 0 && b < 256 && b >= 0);
}
