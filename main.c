#include "fractol.h"

int	printing(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Escape)
	{
		printf("FINISH\n");
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(1);
	}
	printf("%d\n", keysym);
	return (0);
}
float	change_range(float num, float new_min, float new_max, float old_min, float old_max)
{
	float	new;
	new = (new_max - new_min) * (num - old_min) / (old_max - old_min) + new_min;
	return (new);
}

unsigned int	coloring(int	iter)
{
	unsigned char red = (iter * 0) % 255;
	unsigned char green = (iter * 40) % 255;
	unsigned char blue = (iter * 0) % 255;
	unsigned int color = (red << 16 | green << 8 | blue);
	return (color);
}

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
void	put_pixel(int x, int y, t_mlx_data *data, int color)
{
	int	offset;

	offset = (y * data->len) + (x * (data->bpp / 8));
	*(unsigned int *)(data->addr + offset) = color;
}

void	equation_checker(int x, int y, t_mlx_data *data)
{
	t_complex	z;
	t_complex	c;
	float		out;
	int			i;
	unsigned int			color;
	float		iter;

	i = 0;
	out = 4;
	iter = 42;
	z.x = 0;
	z.y = 0;
	c.x = change_range((float)x, -2.0, 2.0, 0, W);
	// printf("%f\n", c.x);
	c.y = change_range((float)y, -2.0, 2.0, 0, H);
	// printf("yy %f\n", c.y);
	while (i < iter)
	{
		z = sum(square(z), c);
		if ((z.x * z.x) + (z.y * z.y) > out)
		{
			color = coloring(i);
			// color = change_range(i, 0x000000, 0xffffff, 0, iter);
			put_pixel(x, y, data, color);
			return ;
		}
		i++;
	}
	put_pixel(x, y, data, 0xdddddd);
}

void	rendering(t_mlx_data	*data)
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

int	main(int ac, char **av)
{
	if (ac == 2 && !ft_strncmp(av[1], "mandelbort", 10))
	{
		t_mlx_data	data;
		int			offset;
	
		data.mlx_ptr = mlx_init();
		data.mlx_win = mlx_new_window(data.mlx_ptr, W, H, TITLE);
		data.mlx_img = mlx_new_image(data.mlx_ptr, W, H);
		data.addr = mlx_get_data_addr(data.mlx_img, &data.bpp, &data.len, &data.endian);
	
		rendering(&data);
		mlx_loop(data.mlx_ptr);

	}


	// printf("%d\n%d\n%d\n", data.bpp, data.len, data.endian);
	// int i = 0;
	// int j = 0;
	// while (i < H)
	// {
	// 	j = 0;
	// 	while (j < data.len)
	// 	{
	// 		offset = (i * data.len) + (j * (data.bpp / 8));
	// 		*(int *)(data.addr + offset) = 0x0077c0;
	// 		j++;
	// 	}
	// 	i++;
	// }
	// i = 0;
	// while (i < W)
	// {
	// 	offset = (360 * data.len) + (i * (data.bpp / 8));
	// 	*(int *)(data.addr + offset) = 0xffffff;
	// 	i++;
	// }
	// i = 0;
	// while (i < H)
	// {
	// 	offset = (i * data.len) + (360 * (data.bpp / 8));
	// 	*(int *)(data.addr + offset) = 0xffffff;
	// 	i++;
	// }

	// int bpp = 32;
	// int line_len = 8;
	// int endian = 0;
	
	// data.mlx_ptr = mlx_init();
	// data.mlx_win = mlx_new_window(data.mlx_ptr, 200, 200, "Just a window");
	// void	*img = mlx_new_image(data.mlx_ptr, 200, 200);
	// char	*addr = mlx_get_data_addr(img, &bpp, &line_len, &endian);
	// int x = 100;
	// int y = 50;
	// int color = 0xffffff;
	// int offset = y * line_len + x * (bpp / 8);
	// *(int *)(addr + offset) = color;
	// mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, img, 0, 0);

	// mlx_key_hook(data.mlx_win, printing, &data);
	// mlx_destroy_display(data.mlx_ptr);
	// mlx_destroy_window(data.mlx_ptr, data.mlx_win);
	// free(data.mlx_win);
	// free(data.mlx_ptr);
}