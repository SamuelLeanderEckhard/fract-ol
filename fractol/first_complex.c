/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_complex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seckhard <seckhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 21:28:01 by seckhard          #+#    #+#             */
/*   Updated: 2023/12/23 21:32:17 by seckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef struct	s_complex
{
	double	real;
	double	i;	
}

int	main()
{
	t_complex	z;
	t_complex	c;
	
	z.real = 0;
	z.i = 0;

	c.real = 5;
	c.i = 2;

	int i = 0;
	while (i < 42)
		i++;
}