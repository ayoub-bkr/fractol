/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 20:15:20 by aboukent          #+#    #+#             */
/*   Updated: 2025/04/16 20:15:23 by aboukent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#define W 1080
#define H 720
#define TITLE "Fract-ol"

typedef struct s_complex
{
	double		x;
	double		y;
}				t_complex;

typedef struct s_mlx_data
{
	void		*mlx_ptr;
	void		*mlx_win;
	void		*mlx_img;
	char		*addr;
	int			bpp;
	int			len;
	int			endian;
	int			iter;
	double		out;
	double		zoom;
	char		type;
	double		julia_x;
	double		julia_y;
}				t_mlx_data;

// fractol.c
void			put_pixel(int x, int y, t_mlx_data *data, int color);
unsigned int	coloring(int i);
double			mapping(double num, double old_min, double old_max);
void			equation_checker(int x, int y, t_mlx_data *data);
void			rendering(t_mlx_data *data);

// main.c
int				mouse_event(int keycode, int x, int y, t_mlx_data *data);
int				x_event(t_mlx_data *data);
int				esc_event(int keycode, t_mlx_data *data);
void			m_or_j(t_complex *c, t_complex *z, t_mlx_data *data);

// util.c
t_complex		sum(t_complex z1, t_complex z2);
t_complex		square(t_complex z);
int				ft_strncmp(char *s1, char *s2, int n);
double			ft_atod(char *str);
