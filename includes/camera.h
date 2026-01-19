/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 21:45:11 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/01/19 18:10:55 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

typedef struct s_camera
{
	double	x;
	double	y;
	double	z;
	double	xdir;
	double	ydir;
	double	zdir;
	double	fov;
	char	isdef;
}	t_camera;

#endif
