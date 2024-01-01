/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seckhard <seckhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 20:13:02 by seckhard          #+#    #+#             */
/*   Updated: 2024/01/01 21:23:44 by seckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

double map(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
	return (new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min;
}

int	main()
{
	int i = 0;
	while (i < 800)
	{
		printf("%d -> %f\n", i, scale((double)i, -2, +2, 0, 10));
		i++;
	}
}
