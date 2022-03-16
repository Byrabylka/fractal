/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fooswyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:56:50 by fooswyn           #+#    #+#             */
/*   Updated: 2022/03/13 18:40:46 by fooswyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractal.h"

int	closewin(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(EXIT_SUCCESS);
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_data *data)
{
	if (keycode == 4)
	{
		data->zoom -= 0.15 * data->zoom;
		data->zoomx -= 0.15 * x / 300 * data->zoom;
		data->zoomy -= 0.15 * y / 300 * data->zoom;
		data->depthmax += 2;
	}
	if (keycode == 5 && data->zoom < 2)
	{
		data->zoom += 0.15 * data->zoom;
		data->zoomx += 0.15 * x / 300 * data->zoom;
		data->zoomy += 0.15 * y / 300 * data->zoom;
		if (data->depthmax >= 10)
			data->depthmax -= 2;
	}
	frac(data);
	return (0);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 38 && data->depthmax >= 10)
		data->depthmax /= 2;
	if (keycode == 37 && data->deg <= 1000000000)
		data->depthmax *= 2;
	if (keycode == 53)
		closewin(data);
	if (keycode == 49)
		data_set(data);
	if (keycode == 124)
		data->updown -= data->zoom;
	if (keycode == 123)
		data->updown += data->zoom;
	if (keycode == 126)
		data->leftright += data->zoom;
	if (keycode == 125)
		data->leftright -= data->zoom;
	if (keycode >= 18 && keycode <= 23)
		data->pal = &get_pal()[keycode - 18];
	if (keycode == 35 && data->moovepls == 1)
		data->moovepls = 0;
	else if (keycode == 35 && data->moovepls == 0)
		data->moovepls = 1;
	return (frac(data));
}

int	locmouse(int x, int y, t_data *data)
{
	if (x > 0 && x < data->width && y > 0 && y < data->length
		&& data->moovepls == 1)
	{
		data->mousex = x;
		data->mousey = y;
		frac(data);
	}
	return (0);
}
