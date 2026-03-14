/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ask2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 12:32:36 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/03/14 01:51:04 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	write_ask(char *msg, double *x)
{
	ft_putstr_fd(msg, 1);
	ft_putstr_fd(" [Current value: ", 1);
	ft_putstr_fd(ft_itoa(*x), 1);
	ft_putendl_fd("]: ", 1);
}

void	remove_nl(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (str + i != str)
	{
		if (str[i] == '\n')
			str[i] = '\0';
		i--;
	}
	if (str[i] == '\n')
		str[i] = '\0';
}
int	ask_change_fov(int *x)
{
	char	*str;

	write_ask("Write the FOV change", (double *)x);
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
