/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 21:55:09 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/02/18 20:56:49 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <math.h>
# include "ambientlighting.h"
# include "camera.h"
# include "cylinder.h"
# include "light.h"
# include "plane.h"
# include "sphere.h"
# include "libft.h"
# include "mlx.h"
# include <X11/keysym.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define WIDTH 800
# define HEIGHT 600
# define CAPACITY 256
# define PI 3.14159265358979323846
# define PI2 1.57079632679489661923
# define PI4 0.78539816339744830962
# define ROTANG 0.00872664625997164788
# define TOL 0.00000000000001
# define SCALE 1.1

enum
{
	SUCCESS,
	IN_AM,
	FILE_NAME,
	FILE_NOT_FOUND,
	MALLOC,
	UNKNOWN_SPECIFIER,
	WRONG_SPECIFIER,
	MULTIPLE_MANDATORY,
	NO_MANDATORY,
	NO_DIR,
	EMPTY,
};

typedef struct s_pixel
{
	int	r;
	int	g;
	int	b;
	int	x;
	int	y;
}	t_pixel;

typedef struct s_screen
{
	t_pixel	*screen;
	void	*mlx;
	void	*window;
	void	*img;
	char	*img_addr;
	int		endian;
	int		img_length;
	int		bits_per_pixel;
}	t_screen;

typedef struct s_miniRT
{
	t_screen		*screen;
	t_AmbientLight	*ambient_light;
	t_camera		*camera;
	t_cylinders		*cylinders;
	t_light			*light;
	t_planes		*planes;
	t_spheres		*spheres;
}	t_miniRT;

typedef struct s_vec
{
	double	x;
	double	y;
	double	z;
}	t_vec;


void	free_all(t_miniRT *rt);
void	free_screen(t_screen *screen);
void	free_split(char **split);

int		init(t_miniRT *rt, char *filename);
void	init_spheres(t_miniRT *rt, int *flag);
void	init_cylinders(t_miniRT *rt, int *flag);
void	init_planes(t_miniRT *rt, int *flag);

int		parse(t_miniRT *rt, char *line);
int		parse_camera(t_miniRT *rt, char **split);
int		parse_ambient_lighting(t_miniRT *rt, char **split);
int		parse_light(t_miniRT *rt, char **split);
int		parse_sphere(t_miniRT *rt, char **split);
int		parse_plane(t_miniRT *rt, char **split);
int		parse_cylinder(t_miniRT *rt, char **split);

int		ft_strcmp(const char *s1, const char *s2);
int		ft_atod(char *str, double *x);
int		ft_ft_atoi(char *str, int *n);
int		is_color(int r, int g, int b);
double	mod(double x, double y, double z);
int		validate_nums(char *nums);
int		validate_dir(double *x, double *y, double *z);

void	errormsg(int flag);
void	start(t_miniRT *rt);

int		add_plane(t_planes *planes, t_plane plane);
int		add_sphere(t_spheres *spheres, t_sphere sphere);
int		add_cylinder(t_cylinders *cylinders, t_cylinder cylinder);

int		move_cam(t_camera *camera);
int		place_cam(t_camera *camera);
int		move_cam_from(t_camera *camera, t_vec dir);
int		move_plane(t_plane *plane);
int		place_plane(t_plane *plane);
int		move_plane_from(t_plane *plane, t_vec dir);
int		move_cylinder(t_cylinder *cylinder);
int		place_cylinder(t_cylinder *cylinder);
int		move_cylinder_from(t_cylinder *cylinder, t_vec dir);
int		move_sphere(t_sphere *sphere);
int		place_sphere(t_sphere *sphere);
int		move_sphere_from(t_sphere *sphere, t_vec dir);
int		move_light(t_light *light);
int		place_light(t_light *light);
int		move_light_from(t_light *light, t_vec dir);

int		ask_coords(double *x, double *y, double *z);
int		ask_factor(double *x);

t_vec	vec_prod(t_vec a, t_vec b);
double	doc_prod(t_vec a, t_vec b);
t_vec	new_vec(double x, double y, double z);
t_vec	get_right(t_vec a);
void	translate_base(t_vec vec, t_vec dir, t_vec coefs);
void	move_by(t_vec vec, t_vec dir, double coef);

#endif