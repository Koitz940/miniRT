/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 19:58:12 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/01/21 11:40:00 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	parse_cylinder2(t_miniRT *rt, char **nums, char **split,
		t_cylinder cylinder)
{
	double	vec_mod;

	vec_mod = sqrt(mod(cylinder.xdir, cylinder.ydir, cylinder.zdir));
	cylinder.xdir /= vec_mod;
	cylinder.ydir /= vec_mod;
	cylinder.zdir /= vec_mod;
	if (!split[4] || ft_atod(split[4], &(cylinder.h)))
		return (free_split(split), UNKNOWN_SPECIFIER);
	if (cylinder.h < 0)
		return (free_split(split), UNKNOWN_SPECIFIER);
	if (validate_nums(split[5]))
		return (free_split(split), UNKNOWN_SPECIFIER);
	nums = ft_split(split[5], ',');
	if (!nums[0] || !nums[1] || !nums[2] || nums[3]
		|| ft_ft_atoi(nums[0], &(cylinder.r))
		|| ft_ft_atoi(nums[1], &(cylinder.g))
		|| ft_ft_atoi(nums[2], &(cylinder.b)) || split[6])
		return (free_split(split), free_split(nums), UNKNOWN_SPECIFIER);
	free_split(nums);
	free_split(split);
	if (!is_color(cylinder.r, cylinder.g, cylinder.b))
		return (WRONG_SPECIFIER);
	if (add_cylinder(rt->cylinders, cylinder))
		return (MALLOC);
	return (SUCCESS);
}

int	parse_cylinder(t_miniRT *rt, char **split)
{
	char		**nums;
	t_cylinder	cylinder;

	if (validate_nums(split[1]))
		return (free_split(split), UNKNOWN_SPECIFIER);
	nums = ft_split(split[1], ',');
	if (!nums[0] || !nums[1] || !nums[2] || nums[3]
		|| ft_atod(nums[0], &(cylinder.x)) || ft_atod(nums[1], (&cylinder.y))
		|| ft_atod(nums[2], &(cylinder.z)))
		return (free_split(split), free_split(nums), UNKNOWN_SPECIFIER);
	free_split(nums);
	if (validate_nums(split[2]))
		return (free_split(split), UNKNOWN_SPECIFIER);
	nums = ft_split(split[2], ',');
	if (!nums[0] || !nums[1] || !nums[2] || nums[3]
		|| ft_atod(nums[0], &(cylinder.xdir))
		|| ft_atod(nums[1], &(cylinder.ydir))
		|| ft_atod(nums[2], &(cylinder.zdir)))
		return (free_split(split), free_split(nums), UNKNOWN_SPECIFIER);
	free_split(nums);
	if (!split[3] || ft_atod(split[3], &(cylinder.d)))
		return (free_split(split), UNKNOWN_SPECIFIER);
	if (cylinder.d < 0)
		return (free_split(split), UNKNOWN_SPECIFIER);
	return (parse_cylinder2(rt, nums, split, cylinder));
}
