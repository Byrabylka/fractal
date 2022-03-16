/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fooswyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:12:15 by fooswyn           #+#    #+#             */
/*   Updated: 2022/03/11 19:36:13 by fooswyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractal.h"

int	norm(t_data *data, int x, int y)
{
	double	xx;
	double	yy;
	double	p1;
	double	p2;

	xx = (x * 0.005 * data->zoom - 2 * data->updown * data->zoomx);
	yy = (-y * 0.005 * data->zoom + 1.5 * data->leftright * data->zoomy);
	if (xx * xx + yy * yy <= 0.25 && xx <= 0)
		return (1);
	if (yy >= 2 * xx - 0.5 && yy <= -2 * xx + 0. && xx >= 0)
		return (1);
	if ((xx + 1) * (xx + 1) + yy * yy <= 0.0625)
		return (1);
	p1 = (xx - 0.25) * (xx - 0.25) + yy * yy;
	p2 = 0.5 - 0.5 * cos(atan2(yy, xx - 0.25));
	if (p1 <= p2 * p2)
		return (1);
	return (0);
}

int	get_iter_mandelbrot1(t_data *data, int xx, int yy)
{
	double	x;
	double	y;
	double	tmp;
	int		i;

	x = 0;
	y = 0;
	i = 0;
	if (norm(data, xx, yy))
		return (data->depthmax);
	while (x * x + y * y <= 4 && i < data->depthmax)
	{
		tmp = x * x - y * y + (xx * 0.005 * data->zoom
				- 2 * data->updown * data->zoomx);
		y = 2 * x * y + (yy * 0.005 * data->zoom
				- 1.5 * data->leftright * data->zoomy);
		x = tmp;
		i++;
	}
	return (i);
}

int	get_iter_mandelbrot2(t_data *data, int xx, int yy)
{
	double	x;
	double	y;
	double	tmp;
	int		i;

	x = 0;
	y = 0;
	i = 0;
	while (x * x + y * y <= 4 && i < data->depthmax)
	{
		tmp = x * x * x - 3 * x * y * y + (xx * 0.005 * data->zoom
				- 1.5 * data->updown * data->zoomx);
		y = 3 * x * x * y - y * y * y + (yy * 0.005 * data->zoom
				- 1.5 * data->leftright * data->zoomy);
		x = tmp;
		i++;
	}
	return (i);
}

int	get_iter_mandelbrot_rand(t_data *data, int xx, int yy)
{
	double	x;
	double	y;
	double	tmp;
	int		i;

	x = data->rand1;
	y = data->rand2;
	i = 0;
	while (x * x + y * y <= 4 && i < data->depthmax)
	{
		tmp = x * x - y * y + (xx * 0.005 * data->zoom
				- 2 * data->updown * data->zoomx);
		y = 2 * x * y + (yy * 0.005 * data->zoom
				- 1.5 * data->leftright * data->zoomy);
		x = tmp;
		i++;
	}
	return (i);
}

int	mandelbrot(t_data *data)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	while (x < data->width)
	{
		y = 0;
		while (y < data->length)
		{
			if (data->choice_mandelbrot == 1)
				i = get_iter_mandelbrot1(data, x, y);
			if (data->choice_mandelbrot == 2)
				i = get_iter_mandelbrot2(data, x, y);
			if (data->choice_mandelbrot == 3)
				i = get_iter_mandelbrot_rand(data, x, y);
			draw(data, x, y, i);
			y++;
		}
		x++;
	}
	return (0);
}
