/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fooswyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:41:54 by fooswyn           #+#    #+#             */
/*   Updated: 2022/03/13 19:07:36 by fooswyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractal.h"

void	init(t_data *data)
{
	data->mlx = mlx_init();
	data_set(data);
	data->pal = &get_pal()[4];
	data->win = mlx_new_window(data->mlx, data->width, data->length, "a)");
	data->img = mlx_new_image(data->mlx, data->width, data->length);
	data->buf = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
}

void	data_set(t_data *data)
{
	data->width = 600;
	data->length = 600;
	data->k_length = 3.0 / data->length;
	data->k_width = 3.0 / data->width;
	data->updown = 1;
	data->leftright = 1;
	data->depthmax = 30;
	data->zoom = 1;
	data->zoomx = 1;
	data->zoomy = 1;
	data->mousex = 1;
	data->mousey = 1;
	data->moovepls = 1;
}

t_pal	*get_pal(void)
{
	static t_pal	tab[10];

	tab[0] = (t_pal){5, {0x070700, 0x353632, 0x646563, \
						0x929595, 0xc1c4c6}};
	tab[1] = (t_pal){5, {0xFFBF60, 0x171070, 0xA0A5FF, \
						0xE0358B, 0xD468ED,}};
	tab[2] = (t_pal){5, {0xFFC346, 0x9BFF34, 0x80E0D8, \
						0x50A1FF, 0xEB56FF,}};
	tab[3] = (t_pal){4, {0x082032, 0x2C394B, 0x334756, \
						0xFF4C29,}};
	tab[4] = (t_pal){4, {0x000000, 0x5800FF, 0xE900FF, \
						0xFFC600,}};
	tab[5] = (t_pal){5, {0x03045E, 0x0077B6, 0x00B4D8, \
						0x90E0EF, 0xCAF0F8,}};
	return (tab);
}

int	pars2(t_data *data, int argc, char *argv[])
{
	if (!ft_strcmp(argv[1], "julia"))
	{
		if (argc == 2)
			data->choice_julia = 1;
		else
			data->choice_julia = (int)(argv[2][0]) - 48;
		data->choice = 2;
		return (1);
	}
	if (!ft_strcmp(argv[1], "thorn"))
	{
		data->choice = 3;
		return (1);
	}
	return (0);
}

int	pars(t_data *data, int argc, char *argv[])
{
	if (argc <= 1)
		return (0);
	if (!ft_strcmp(argv[1], "mandelbrot"))
	{
		if (argc == 2)
			data->choice_mandelbrot = 1;
		else
			data->choice_mandelbrot = (int)(argv[2][0]) - 48;
		if (data->choice_mandelbrot == 3)
		{
			data->rand1 = get_rand1();
			data->rand2 = get_rand2();
		}
		data->choice = 1;
		return (1);
	}
	else
		return (pars2(data, argc, argv));
	return (0);
}
