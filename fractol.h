#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include <X11/keysym.h>

#define W 1080
#define	H 720
#define TITLE "Fract-ol"

typedef struct	s_complex
{
	float	x;
	float	y;
}		t_complex;
typedef struct	s_mlx_data
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		len;
	int		endian;
	float	zoom;
}			t_mlx_data;

int	ft_strncmp(char *s1, char *s2, int n);