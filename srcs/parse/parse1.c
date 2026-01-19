/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 17:55:22 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/01/19 18:25:23 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		if (split[i])
			free(split[i]);
		i++;
	}
	free(split);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && (s1[i] == s2[i]))
		i++;
	return ((int)s1[i] - (int)s2[i]);
}

static int	parse2(t_miniRT *rt, char **split)
{
	int	flag;

	if (!ft_strcmp(split[0], "sp"))
	{
		flag = parse_sphere(rt, split + 1);
		if (flag)
			return (flag);
	}
	else if (!ft_strcmp(split[0], "cy"))
	{
		flag = parse_cylinder(rt, split + 1);
		if (flag)
			return (flag);
	}
	else if (!ft_strcmp(split[0], "pl"))
	{
		flag = parse_plane(rt, split + 1);
		if (flag)
			return (flag);
	}
	return (UNKNOWN_SPECIFIER);
}

int	parse(t_miniRT *rt, char *line)
{
	char	**split;
	int		flag;

	if (line[0] && line[0] == '\n')
		return (SUCCESS);
	split = ft_split(line, ' ');
	if (!ft_strcmp(split[0], "A"))
	{
		flag = parse_ambient_lighting(rt, split + 1);
		if (flag)
			return (flag);
	}
	else if (!ft_strcmp(split[0], "L"))
	{
		flag = parse_light(rt, split + 1);
		if (flag)
			return (flag);
	}
	else if (!ft_strcmp(split[0], "C"))
	{
		flag = parse_light(rt, split + 1);
		if (flag)
			return (flag);
	}
	return (parse2(rt, split));
}

