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

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] > s2[i] || s1[i] < s2[i])
			return (1);
		i++;
	}
	return (0);
}

double	atod_calcul(double *res, double sign, char *str)
{
	double	rat;

	rat = 1;
	if (*str == '.')
		erroring();
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
		{
			rat /= 10;
			*res += (*str++ - 48) * rat;
		}
		else
			erroring();
	}
	if (!(*res * sign < 2 && *res * sign > -2))
		erroring();
	return (*res * sign);
}

double	ft_atod(char *str)
{
	double	res;
	double	sign;

	res = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str == 13))
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign *= -1;
	if (*str == '-' || *str == '+')
		erroring();
	while (*str && *str != '.')
	{
		if (*str >= '0' && *str <= '9')
			res = (res * 10) + *str - 48;
		else
			erroring();
		str++;
	}
	if (*str == '.')
		str++;
	return (atod_calcul(&res, sign, str));
}
