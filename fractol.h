#include <mlx.h>
#include <stdlib.h>

#define W 1080
#define	H 720
#define TITLE "Fract-ol"

typedef struct	s_complex
{
	double	x;
	double	y;
}			t_complex;

typedef struct	s_mlx_data
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		len;
	int		endian;
	int		iter;
	double	out;
	double	zoom;
}			t_mlx_data;

//fractol.c
void			put_pixel(int x, int y, t_mlx_data *data, int color);
unsigned int	coloring(int i);
double			change_range(double num, double new_min, double new_max, double old_min, double old_max);
void			equation_checker(int x, int y, t_mlx_data *data);
void			rendering(t_mlx_data	*data);

// main.c
int	mouse_event(int button, int x, int y, t_mlx_data *data);
int	closing(t_mlx_data *data);
int	esc_event(int keycode, t_mlx_data	*data);

// util.c
t_complex	sum(t_complex z1, t_complex z2);
t_complex	square(t_complex z);
int			ft_strncmp(char *s1, char *s2, int n);
double		ft_atod(char *str);