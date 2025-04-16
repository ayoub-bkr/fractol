/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 20:16:00 by aboukent          #+#    #+#             */
/*   Updated: 2025/04/16 20:16:03 by aboukent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	sum(t_complex z1, t_complex z2)
{
	t_complex	res;

	res.x = z1.x + z2.x;
	res.y = z1.y + z2.y;
	return (res);
}

t_complex	square(t_complex z)
{
	t_complex	res;

	res.x = (z.x * z.x) - (z.y * z.y);
	res.y = 2 * z.x * z.y;
	return (res);
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] > s2[i] || s1[i] < s2[i])
			return (1);
		i++;
	}
	return (0);
}

double	ft_atod(char *str)
{
	double	res;
	double	sign;
	double	rat;

	res = 0;
	sign = 1;
	rat = 1;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign *= -1;
	while (*str && *str != '.')
	{
		res = (res * 10) + *str - 48;
		str++;
	}
	if (*str == '.')
		str++;
	while (*str)
	{
		rat /= 10;
		res += (*str++ - 48) * rat;
	}
	return (res * sign);
}
