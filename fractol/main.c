/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seckhard <seckhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 16:31:56 by seckhard          #+#    #+#             */
/*   Updated: 2024/01/20 16:01:30 by seckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if ((argc == 2 && ft_strcmp(argv[1], "mandelbrot") == 0) \
		|| (argc == 4 && ft_strcmp(argv[1], "julia") == 0 \
		&& is_valid_number(argv[2]) && is_valid_number(argv[3])))
	{
		fractal.name = argv[1];
		if (ft_strcmp(fractal.name, "julia") == 0)
		{
			fractal.julia_x = atodbl(argv[2]);
			fractal.julia_y = atodbl(argv[3]);
		}
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_link);
	}
	else
	{
		putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
