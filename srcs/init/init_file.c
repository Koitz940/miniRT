/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 18:55:16 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/01/19 18:25:23 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	init_camera(t_miniRT *rt, int *flag)
{
	rt->camera = malloc(sizeof(t_camera));
	if (!rt->camera)
		*flag = MALLOC;
	rt->camera->isdef = 0;
}

static void	init_screen(t_screen *screen, int *flag)
{
	screen->screen = malloc(sizeof(t_pixel) * WIDTH * HEIGHT);
	if (!screen)
	{
		*flag = MALLOC;
		return ;
	}
	screen->mlx = mlx_init();
	if (!screen->mlx)
	{
		*flag = MALLOC;
		return ;
	}
	screen->window = mlx_new_window(screen->mlx, WIDTH, HEIGHT, "BALLS");
	if (!screen->window)
		*flag = MALLOC;
	screen->img = mlx_new_image(screen->mlx, WIDTH, HEIGHT);
	if (!screen->img)
	{
		*flag = MALLOC;
		return (screen->img_addr = NULL);
	}
	screen->img_addr = mlx_get_data_addr(screen->img, &(screen->bits_per_pixel),
			&(screen->img_length), &(screen->endian));
	if (!screen->img_addr)
		*flag = MALLOC;
}

static void	init_screen2(t_screen *screen, int *flag)
{
	size_t	i;
	size_t	j;
	size_t	pos;

	j = -1;
	while (++j < HEIGHT)
	{
		i = -1;
		while (++i < WIDTH)
		{
			pos = j * WIDTH + i;
			screen->screen[pos].r = 0;
			screen->screen[pos].g = 0;
			screen->screen[pos].b = 0;
			screen->screen[pos].x = i;
			screen->screen[pos].y = j;
		}
	}
}

static int	init2(t_miniRT *rt, int flag, char *filename)
{
	int		fd;
	char	*line;

	if (flag)
		return (flag);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (FILE_NOT_FOUND);
	line = get_next_line(fd);
	if (!line)
		return (MALLOC);
	while (line)
	{
		if (!line)
			return (flag);
		flag = parse(rt, line);
		free(line);
	}
}

int	init(t_miniRT *rt, char *filename)
{
	int	flag;

	flag = SUCCESS;
	rt = malloc(sizeof(t_miniRT));
	if (!rt)
		return (MALLOC);
	init_cylinders(rt, &flag);
	init_planes(rt, &flag);
	init_spheres(rt, &flag);
	rt->screen = malloc(sizeof(t_screen));
	if (!rt->screen)
		flag = MALLOC;
	init_screen(rt->screen, &flag);
	init_screen2(rt->screen->screen, &flag);
	rt->light = malloc(sizeof(t_light));
	if (!rt->light)
		flag = MALLOC;
	rt->light->isdef = 0;
	rt->ambient_light = malloc(sizeof(t_AmbientLight));
	if (!rt->ambient_light)
		flag = MALLOC;
	rt->light->isdef = 0;
	return (init2(rt, flag, filename));
}

