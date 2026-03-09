/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ask2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 12:32:36 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/03/08 20:22:25 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	write_ask_fov(int *x)
{
	ft_putstr_fd("Write the FOV [Current FOV: ", 1);
	ft_putstr_fd(ft_itoa(*x), 1);
	ft_putendl_fd("]: ", 1);
}

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
