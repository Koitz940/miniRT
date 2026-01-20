/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 22:43:26 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/01/20 22:52:40 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	errormsg(int flag)
{
	if (flag == IN_AM)
		ft_putendl_fd("Error: can only input the name of a single\
				.rt file\n", 2);
	if (flag == FILE_NAME)
		ft_putendl_fd("Error: Input file must have .rt format\n", 2);
	if (flag == FILE_NOT_FOUND)
		ft_putendl_fd("Error: GIven file doesn't exist or could\
			 not be opened\n", 2);
	if (flag == MALLOC)
		ft_putendl_fd("Error: A memory allocation failed\n", 2);
	if (flag == UNKNOWN_SPECIFIER)
		ft_putendl_fd("Error: unknown character given in file\n", 2);
	if (flag == WRONG_SPECIFIER)
		ft_putendl_fd("Error: Some number does not fit in its range\n", 2);
	if (flag == MULTIPLE_MANDATORY)
		ft_putendl_fd("Error: Camera, light or ambient light was defined\
			 more than once\n", 2);
	if (flag == NO_MANDATORY)
		ft_putendl_fd("Error: Camera, light or ambient\
			 light was not defined\n", 2);
}
