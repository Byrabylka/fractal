/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fooswyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:06:49 by fooswyn           #+#    #+#             */
/*   Updated: 2022/03/16 13:25:01 by fooswyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H
# include	<stdlib.h>
# include "mlx.h"
# include <stdlib.h>
# include <math.h>
# include <stdio.h> 
# include <unistd.h>
# include <time.h>

# define FRACT_COLOR 0x090909

typedef struct s_pal
{
	unsigned char	count;
	int				colors[16];
}						t_pal;

typedef struct s_rgba
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;
}	t_rgba;

typedef union s_color {
	t_rgba	rgba;
	int		value;
}	t_color;

typedef struct data
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*buf;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				width;
	int				length;
	int				mousex;
	int				mousey;
	int				depthmax;
	double			leftright;
	double			updown;
	double			zoom;
	double			zoomx;
	double			zoomy;
	double			k_length;
	double			k_width;
	int				choice;
	int				choice_julia;
	int				choice_mandelbrot;
	double			rand1;
	double			rand2;
	int				deg;
	int				moovepls;
	int				i;
	int				j;
	t_pal			*pal;
}				t_data;

void	init(t_data *data);
void	data_set(t_data *data);
t_pal	*get_pal(void);
int		pars(t_data *data, int argc, char *argv[]);

int		frac(t_data *data);
int		mandelbrot(t_data *data);
int		julia(t_data *data);
int		get_iter_julia4(t_data *data, double xx, double yy);
int		get_iter_julia5(t_data *data, double xx, double yy);
int		get_iter_julia6(t_data *data, double xx, double yy);
int		get_iter_julia7(t_data *data, double xx, double yy);
int		get_iter_julia8(t_data *data, double xx, double yy);
int		get_iter_julia9(t_data *data, double xx, double yy);

void	draw(t_data *data, int x, int y, int i);

int		closewin(t_data *data);
int		locmouse(int x, int y, t_data *data);
int		mouse_hook(int keycode, int x, int y, t_data *data);
int		key_hook(int keycode, t_data *data);

int		ft_min(int a, int b);
void	ft_putstr(char *str);
int		ft_strcmp(char *a, char *b);
char	*ft_itoa(int nb);
double	ft_power(double x, int deg);
double	get_rand1(void);
double	get_rand2(void);

#endif