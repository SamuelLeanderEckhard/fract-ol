/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seckhard <seckhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 16:56:25 by seckhard          #+#    #+#             */
/*   Updated: 2024/01/20 16:01:19 by seckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (NULL == s1 || NULL == s2 || n <= 0)
		return (0);
	while (n > 0 && *s1 && *s1 == *s2)
	{
		++s1;
		++s2;
		--n;
	}
	if (n == 0)
		return (0);
	return (*s1 - *s2);
}

void	putstr_fd(char *s, int fd)
{
	if (s == NULL || fd < 0)
		return ;
	if (*s != '\0')
	{
		write(fd, s, 1);
		putstr_fd(s + 1, fd);
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

double	atodbl(char *s)
{
	int		integer_part;
	double	fractional_part;
	double	power;
	int		sign;

	integer_part = 0;
	fractional_part = 0;
	sign = +1;
	power = 1;
	while ((*s >= 9 & *s <= 13) || *s == 32)
		++s;
	while (*s == '+' || *s == '-')
		if (*s++ == '-')
			sign = -sign;
	while (*s != '.' && *s)
		integer_part = (integer_part * 10) + (*s++ - 48);
	if (*s == '.')
		++s;
	while (*s)
	{
		power /= 10;
		fractional_part = fractional_part + (*s++ - 48) * power;
	}
	return ((integer_part + fractional_part) * sign);
}

int	is_valid_number(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while ((str[i] == ' ' || str[i] == '-' || str[i] == '+'))
			i++;
		if (str[i] == '\0' || (!((str[i] >= '0' && str[i] <= '9'))))
			return (0);
		while (str[i])
		{
			if ((str[i] >= '0' && str[i] <= '9') || (str[i] == '.'))
				i++;
			else
				return (0);
		}
		break ;
	}
	return (1);
}
