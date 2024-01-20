/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seckhard <seckhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 16:22:55 by seckhard          #+#    #+#             */
/*   Updated: 2024/01/20 16:00:05 by seckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <mlx.h>

# define ERROR_MESSAGE "Please enter \n\t\"./fractol mandelbrot\" \
 or \n\t\"./fractol julia <value_1> <value_2>\"\n"

# define WIDTH	800
# define HEIGHT	800

//***Define color constants
# define BLACK           0x000000
# define WHITE           0xFFFFFF
# define RED             0xFF0000
# define GREEN           0x00FF00
# define BLUE            0x0000FF
# define YELLOW          0xFFFF00
# define MAGENTA         0xFF00FF
# define CYAN            0x00FFFF
# define ORANGE          0xFFA500
# define PURPLE          0x800080
# define PINK            0xFFC0CB

//***Define psychedelic color
# define MAGENTA_BLUE_MIX    0xFF00FF
# define CYAN_YELLOW_MIX     0x00FFFF
# define PURPLE_PINK_MIX		0x9900FF
# define PINK_MAGENTA_MIX	0xFF0099
# define ORANGE_GREEN_MIX	0xFFA500
# define LIME_PURPLE_MIX		0x80FF00
# define TEAL_PINK_MIX		0x008080
# define INDIGO_YELLOW_MIX	0x4B0082

typedef struct s_complex
{
	double	x;
	double	y;
}				t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}			t_img;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_link;
	void	*mlx_window;
	t_img	img;

	double	escape_value;
	int		iterations_definition;
	double	shift_x;
	double	shift_y;
	double	zoom;

	double	julia_x;
	double	julia_y;
}			t_fractal;

//***string utils
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			putstr_fd(char *s, int fd);
int				ft_strcmp(char *s1, char *s2);
double			atodbl(char *s);
int				is_valid_number(const char *str);

//***initialization
void			fractal_init(t_fractal *fractal);

//***render
void			fractal_render(t_fractal *fractal);

//***math utils
double			map(double unscaled_num, double new_min, \
				double new_max, double old_max);
t_complex		sum_complex(t_complex z1, t_complex z2);
t_complex		square_complex(t_complex z);

//***events
int				key_handler(int keysym, t_fractal *fractal);
int				close_handler(t_fractal *fractal);
int				mouse_handler(int button, int x, int y, t_fractal *fractal);
int				julia_sets(int x, int y, t_fractal *fractal);

#endif
