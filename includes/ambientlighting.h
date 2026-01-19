/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambientLighting.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 21:42:04 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/01/19 18:10:59 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMBIENTLIGHTING_H
# define AMBIENTLIGHTING_H

typedef struct s_AmbientLight
{
	double	bright;
	int		r;
	int		g;
	int		b;
	char	isdef;
}	t_AmbientLight;

#endif
