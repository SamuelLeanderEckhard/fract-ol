/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seckhard <seckhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:04:17 by seckhard          #+#    #+#             */
/*   Updated: 2024/01/15 22:37:45 by seckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
}

int	key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape || keysym == XK_X || keysym == XK_x)
		close_handler(fractal);
	else if (keysym == XK_Left)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keysym == XK_Right)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keysym == XK_Up)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keysym == XK_Down)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (keysym == XK_plus)
		fractal->iterations_definition += 10;
	else if (keysym == XK_minus)
		fractal->iterations_definition -= 10;
	fractal_render(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	double	mouse_x;
	double	mouse_y;
	double	old_zoom;
	double	zoom_ratio;

	mouse_x = (double)x / WIDTH * 3.0 - 2.0;
	mouse_y = 2.0 - (double)y / HEIGHT * 3.0;
	old_zoom = fractal->zoom;
	if (button == Button5)
	{
		fractal->zoom *= 1.05;
	}
	else if (button == Button4)
	{
		fractal->zoom *= 0.95;
	}
	zoom_ratio = fractal->zoom / old_zoom;
	fractal->shift_x = mouse_x - (mouse_x - fractal->shift_x) * zoom_ratio;
	fractal->shift_y = mouse_y - (mouse_y - fractal->shift_y) * zoom_ratio;
	fractal_render(fractal);
	return (0);
}

int	julia_track(int x, int y, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		fractal->julia_x = (map(x, -2, +2, WIDTH) \
			* fractal->zoom) + fractal->shift_x;
		fractal->julia_y = (map(y, +2, -2, HEIGHT) \
			* fractal->zoom) + fractal->shift_y;
		fractal_render(fractal);
	}
	return (0);
}
