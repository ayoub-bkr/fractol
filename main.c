#include "fractol.h"

int	mouse_event(int button, int x, int y, t_mlx_data *data)
{
	if (button == 5)
		data->zoom *= 0.9;
	else if (button == 4)
		data->zoom *= 1.1;
	rendering(data);
	return (0);
}

int	closing(t_mlx_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->mlx_img);
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

int	esc_event(int keycode, t_mlx_data	*data)
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

int	main(int ac, char **av)
{
	if (ac == 2 && !ft_strncmp(av[1], "mandelbort", 10))
	{
		t_mlx_data	data;

		data.mlx_ptr = mlx_init();
		data.mlx_win = mlx_new_window(data.mlx_ptr, W, H, TITLE);
		data.mlx_img = mlx_new_image(data.mlx_ptr, W, H);
		data.addr = mlx_get_data_addr(data.mlx_img, &data.bpp, &data.len, &data.endian);
		data.zoom = 1;
		mlx_key_hook(data.mlx_win, esc_event, &data);
		mlx_hook(data.mlx_win, 4, 1L<<2, mouse_event, &data);
		mlx_hook(data.mlx_win, 17, 1L<<17, closing, &data);
		rendering(&data);
		mlx_loop(data.mlx_ptr);
	}
}
