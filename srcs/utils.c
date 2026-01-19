/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:56:46 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/01/19 20:31:16 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	ft_atod(char *str)
{

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
