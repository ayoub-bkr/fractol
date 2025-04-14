#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include <X11/keysym.h>

typedef struct	s_mlx_data
{
	void	*mlx_ptr;
	void	*mlx_win;
}			t_mlx_data;

int	ft_strncmp(char *s1, char *s2, int n);