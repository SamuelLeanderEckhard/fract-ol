/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seckhard <seckhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:04:17 by seckhard          #+#    #+#             */
/*   Updated: 2024/01/03 17:56:37 by seckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection,
					fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection,
						fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
}


int	key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape || keysym == XK_X || keysym == XK_x)
		close_handler(fractal);
	else if (keysym == XK_Left)
		fractal->shift_x += 0.5;
	else if (keysym == XK_Right)
		fractal->shift_x -= 0.5;
	else if (keysym == XK_Up)
		fractal->shift_y -= 0.5;
	else if (keysym == XK_Down)
		fractal->shift_y += 0.5;
	else if (keysym == XK_plus)
		fractal->iterations_definition += 10;
	else if (keysym == XK_minus)
		fractal->iterations_definition -= 10;
	fractal_render(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	if (button == Button5)
	{
		
	}
	else if (button == Button4)
	{

	}
	printf("%d\n", button);
	fractal_render(fractal);
	return (0);
}