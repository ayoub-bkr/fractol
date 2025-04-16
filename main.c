/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 20:15:33 by aboukent          #+#    #+#             */
/*   Updated: 2025/04/16 20:15:34 by aboukent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_event(int keycode, int x, int y, t_mlx_data *data)
{
	(void)x;
	(void)y;
	if (keycode == 5)
		data->zoom *= 0.9;
	else if (keycode == 4)
		data->zoom *= 1.1;
	rendering(data);
	return (0);
}

int	x_event(t_mlx_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->mlx_img);
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

int	esc_event(int keycode, t_mlx_data *data)
{
	if (keycode == 65307)
	{
		mlx_destroy_image(data->mlx_ptr, data->mlx_img);
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(0);
	}
	return (0);
}

void	m_or_j(t_complex *c, t_complex *z, t_mlx_data *data)
{
	if (data->type == 'm')
	{
		c->x = z->x;
		c->y = z->y;
	}
	else
	{
		c->x = data->julia_x;
		c->y = data->julia_y;
	}
}

int	main(int ac, char **av)
{
	t_mlx_data	data;

	if ((ac == 2 && !ft_strncmp(av[1], "mandelbort", 10)) || (ac == 4
			&& !ft_strncmp(av[1], "julia", 5)))
	{
		data.mlx_ptr = mlx_init();
		data.mlx_win = mlx_new_window(data.mlx_ptr, W, H, TITLE);
		data.mlx_img = mlx_new_image(data.mlx_ptr, W, H);
		data.addr = mlx_get_data_addr(data.mlx_img, &data.bpp, &data.len,
				&data.endian);
		mlx_key_hook(data.mlx_win, esc_event, &data);
		mlx_hook(data.mlx_win, 4, 1L << 2, mouse_event, &data);
		mlx_hook(data.mlx_win, 17, 1L << 17, x_event, &data);
		data.zoom = 1;
		if (!ft_strncmp(av[1], "mandelbort", 10))
			data.type = 'm';
		else
		{
			data.type = 'j';
			data.julia_x = ft_atod(av[2]);
			data.julia_y = ft_atod(av[3]);
		}
		rendering(&data);
		mlx_loop(data.mlx_ptr);
	}
}
