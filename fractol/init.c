/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seckhard <seckhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 17:11:39 by seckhard          #+#    #+#             */
/*   Updated: 2024/01/19 23:01:17 by seckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	malloc_error(void)
{
	perror("You got a problem with malloc");
	exit(EXIT_FAILURE);
}

static void	data_init(t_fractal	*fractal)
{
	fractal->escape_value = 4;
	fractal->iterations_definition = 42;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
}

static void	events_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window, KeyPress, KeyPressMask, key_handler, fractal);
	mlx_hook(fractal->mlx_window, ButtonPress, ButtonPressMask, \
			mouse_handler, fractal);
	mlx_hook(fractal->mlx_window, DestroyNotify, \
			StructureNotifyMask, close_handler, fractal);
	mlx_hook(fractal->mlx_window, MotionNotify, \
			PointerMotionMask, julia_sets, fractal);
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_link = mlx_init();
	if (fractal->mlx_link == NULL)
		malloc_error();
	fractal->mlx_window = mlx_new_window(fractal->mlx_link, \
											WIDTH, HEIGHT, fractal->name);
	if (fractal->mlx_window == NULL)
	{
		mlx_destroy_display(fractal->mlx_link);
		free(fractal->mlx_link);
		malloc_error();
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_link, \
											WIDTH, HEIGHT);
	if (fractal->img.img_ptr == NULL)
	{
		mlx_destroy_window(fractal->mlx_link, fractal->mlx_window);
		mlx_destroy_display(fractal->mlx_link);
		free(fractal->mlx_link);
		malloc_error();
	}
	fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr, \
						&fractal->img.bpp, \
						&fractal->img.line_len, &fractal->img.endian);
	events_init(fractal);
	data_init(fractal);
}
