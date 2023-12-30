/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seckhard <seckhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 16:22:55 by seckhard          #+#    #+#             */
/*   Updated: 2023/12/30 17:10:02 by seckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "minilibx-linux/mlx.h"

#define ERROR_MESSAGE "Please enter \n\t\"./fractol mandelbrot\" or \n\t\"./fractol julia <value_1> <value_2>\"\n"

// typedef struct s_img
// {
// 	void	*img_ptr;
// 	char	*pixels_ptr;
// 	int		bpp;
// 	int		endian;
// 	int		line_len;/* data */
// }			t_img;

// typedef struct	s_fractal
// {
// 	void	*mlx_connection;
// 	void	*mlx_win;
// 	t_img	img;
// }			t_fractal;

int		ft_strncmp(char *s1, char *s2, int n);
void	putstr_fd(char *s, int fd);

#endif