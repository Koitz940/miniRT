/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 18:07:12 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/01/21 00:19:21 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	validate_file(int ac, char **av)
{
	int	i;

	if (ac != 2)
		return (IN_AM);
	if (ft_strlen(av[1]) < 4)
		return (FILE_NAME);
	i = 0;
	while (av[1][i] && av[1][i] != '.')
		i++;
	if (!av[1][i] || !av[1][i + 1] || !av[1][i + 2] || av[1][i + 1] != 'r'
			|| av[1][i + 2] != 't' || av[1][i + 3])
		return (FILE_NAME);
	return (SUCCESS);
}

int	main(int ac, char **av)
{
	t_miniRT	*rt;
	int			flag;

	flag = validate_file(ac, av);
	rt = ft_calloc(sizeof(t_miniRT), 1);
	if (!rt)
		return (errormsg(flag), 1);
	if (flag)
		return (free_all(rt), errormsg(flag), 1);
	flag = init(rt, av[1]);
	if (flag)
		return (free_all(rt), errormsg(flag), 1);
	start(rt);
	ft_putendl_fd("Finished!\n", 1);
}
