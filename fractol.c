/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 20:13:36 by aboukent          #+#    #+#             */
/*   Updated: 2025/04/16 20:13:39 by aboukent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(int x, int y, t_mlx_data *data, int color)
{
	int	offset;

	offset = (y * data->len) + (x * (data->bpp / 8));
	*(unsigned int *)(data->addr + offset) = color;
}

unsigned int	coloring(int i)
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;

	blue = (i * 0) % 255;
	green = (i * 4) % 255;
	red = (i * 0) % 255;
	return (red << 16 | green << 8 | blue);
}

double	mapping(double num, double old_min, double old_max)
{
	double	new;
	double	new_min;
	double	new_max;

	new_min = -2;
	new_max = 2;
	new = (new_max - new_min) * (num - old_min) / (old_max - old_min) + new_min;
	return (new);
}

void	equation_checker(int x, int y, t_mlx_data *data)
{
	t_complex	z;
	t_complex	c;
	int			i;

	i = 0;
	data->out = 4;
	data->iter = 420;
	z.x = mapping(x, 0, W * data->zoom);
	z.y = mapping(y, 0, H * data->zoom);
	m_or_j(&c, &z, data);
	while (i < data->iter)
	{
		z = sum(square(z), c);
		if ((z.x * z.x) + (z.y * z.y) > data->out)
		{
			put_pixel(x, y, data, coloring(i));
			return ;
		}
		i++;
	}
	put_pixel(x, y, data, 0xdddddd);
}

void	rendering(t_mlx_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y++ < H)
	{
		x = 0;
		while (x++ < W)
			equation_checker(x, y, data);
	}
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->mlx_img, 0, 0);
}
