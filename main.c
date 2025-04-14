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
int	main(int ac, char **av)
{
	// if (ac == 2 && !ft_strncmp(av[1], "mandelbort", 10))
	// {

	// }

	t_mlx_data	data;


















	
	int bpp = 32;
	int line_len = 8;
	int endian = 0;
	
	data.mlx_ptr = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx_ptr, 200, 200, "Just a window");
	void	*img = mlx_new_image(data.mlx_ptr, 200, 200);
	char	*addr = mlx_get_data_addr(img, &bpp, &line_len, &endian);
	int x = 100;
	int y = 50;
	int color = 0xffffff;
	int offset = y * line_len + x * (bpp / 8);
	*(int *)(addr + offset) = color;
	mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, img, 0, 0);

	// mlx_key_hook(data.mlx_win, printing, &data);
	mlx_loop(data.mlx_ptr);

	// mlx_destroy_display(data.mlx_ptr);
	// mlx_destroy_window(data.mlx_ptr, data.mlx_win);
	// free(data.mlx_win);
	// free(data.mlx_ptr);
}