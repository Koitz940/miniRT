/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:22:53 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/01/20 22:49:57 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

char	**ft_reall(char **nums, char *line)
{
	free_split(nums);
	return (ft_split(line, ','));
}

int	parse_camera2(t_miniRT *rt, char **split, char **nums)
{
	double	vec_mod;

	if (!nums[0] || ft_atod(nums[0], &(rt->camera->xdir)))
		return (free_split(nums), free_split(split), UNKNOWN_SPECIFIER);
	if (!nums[1] || ft_atod(nums[1], &(rt->camera->ydir)))
		return (free_split(nums), free_split(split), UNKNOWN_SPECIFIER);
	if (!nums[2] || ft_atod(nums[2], &(rt->camera->zdir)))
		return (free_split(nums), free_split(split), UNKNOWN_SPECIFIER);
	if (nums[3])
		return (free_split(nums), free_split(split), UNKNOWN_SPECIFIER);
	vec_mod = sqrt(mod(rt->camera->xdir, rt->camera->ydir, rt->camera->zdir));
	rt->camera->xdir /= vec_mod;
	rt->camera->ydir /= vec_mod;
	rt->camera->zdir /= vec_mod;
	free_split(nums);
	if (!split[3] || ft_atod(split[3], &(rt->camera->fov)))
		return (free_split(split), UNKNOWN_SPECIFIER);
	if (rt->camera->fov > 180 || rt->camera->fov < 0)
		return (free_split(split), WRONG_SPECIFIER);
	if (split[4])
		return (UNKNOWN_SPECIFIER);
	free_split(split);
	rt->camera->isdef = 1;
	return (SUCCESS);
}

int	parse_camera(t_miniRT *rt, char **split)
{
	char	**nums;
	double	num;

	if (rt->camera->isdef)
		return (free_split(split), MULTIPLE_MANDATORY);
	if (!split[1])
		return (free_split(split), UNKNOWN_SPECIFIER);
	nums = ft_split(split[1], ',');
	if (!nums)
		return (free_split(split), free_split(nums), MALLOC);
	if (!nums[0] || ft_atod(nums[0], &(rt->camera->x)))
		return (free_split(nums), free_split(split), UNKNOWN_SPECIFIER);
	if (!nums[1] || ft_atod(nums[1], &(rt->camera->y)))
		return (free_split(nums), free_split(split), UNKNOWN_SPECIFIER);
	if (!nums[2] || ft_atod(nums[2], &(rt->camera->z)))
		return (free_split(nums), free_split(split), UNKNOWN_SPECIFIER);
	free_split(nums);
	if (nums[3] || !split[2])
		return (free_split(split), UNKNOWN_SPECIFIER);
	nums = ft_split(split[2], ',');
	if (!nums)
		return (free_split(split), MALLOC);
	return (parse_camera2(rt, split, nums));
}
