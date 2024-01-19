/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seckhard <seckhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:04:17 by seckhard          #+#    #+#             */
/*   Updated: 2024/01/19 23:02:13 by seckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_link, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_link, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_link);
	free(fractal->mlx_link);
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
		fractal->iterations_definition += 2;
	else if (keysym == XK_minus)
		fractal->iterations_definition -= 2;
	fractal_render(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	double	mouse_x;
	double	mouse_y;

	mouse_x = (x - WIDTH / 2) / (0.5 * WIDTH * fractal->zoom) \
			+ fractal->shift_x;
	mouse_y = (y - HEIGHT / 2) / (0.5 * HEIGHT * fractal->zoom) \
			+ fractal->shift_y;
	if (button == Button5 || button == Button2)
		fractal->zoom *= 1.2;
	else if (button == Button4 || button == Button1)
		fractal->zoom /= 1.2;
	fractal_render(fractal);
	return (0);
}

int	julia_sets(int x, int y, t_fractal *fractal)
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
