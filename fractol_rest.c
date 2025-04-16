/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_rest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 23:09:36 by aboukent          #+#    #+#             */
/*   Updated: 2025/04/16 23:09:40 by aboukent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	erroring(void)
{
	write(1, "Invalid input! Try this:\n", 26);
	write(1, "./fractol mandelbort\n", 22);
	write(1, "./fractol julia <real> <imaginer> [-2, 2]", 42);
	exit(1);
}

void	initialising(t_mlx_data *data)
{
	data->zoom = 1;
	data->mlx_ptr = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx_ptr, W, H, TITLE);
	data->mlx_img = mlx_new_image(data->mlx_ptr, W, H);
	data->addr = mlx_get_data_addr(data->mlx_img, &data->bpp, &data->len,
			&data->endian);
}
