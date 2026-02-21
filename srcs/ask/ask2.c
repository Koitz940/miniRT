/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ask2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 12:32:36 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/02/21 12:33:23 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	ask_change_fov(int *x)
{
	char	*str;

	ft_putendl_fd("Write the fov: ", 1);
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
			break ;
		}
	}
	return (SUCCESS);
}
