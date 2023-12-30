/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_complex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seckhard <seckhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 21:28:01 by seckhard          #+#    #+#             */
/*   Updated: 2023/12/30 17:19:02 by seckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef struct	s_complex
{
	double	real;
	double	i;	
}			t_complex;

int	main()
{
	t_complex	z;
	t_complex	c;
	double	tmp_real;
	
	z.real = 0;
	z.i = 0;

	c.real = 0.25;
	c.i = 0.4;

	int i = 0;
	while (i  < 42)
	{
		tmp_real = (z.real * z.real) - (z.i * z.i);
		z.i = 2 * z.real * z.i;
		z.real = tmp_real;

		z.real += c.real;
		z.i += c.i;
		printf("iteratuion n -> %d real %f imaginary%f\n", i, z.real, z.i);
		i++;
	}
}