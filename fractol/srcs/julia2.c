/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fooswyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 23:29:31 by fooswyn           #+#    #+#             */
/*   Updated: 2022/03/13 19:12:01 by fooswyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractal.h"

int	get_iter_julia4(t_data *data, double xx, double yy)
{
	double	x;
	double	y;
	double	tmp;
	int		i;
	double	k;

	x = xx * 0.01667 * data->zoom - 5 * data->zoomx * data->updown;
	y = yy * 0.01667 * data->zoom - 5 * data->zoomy * data->leftright;
	i = 0;
	k = data->width / 2;
	while (x * x + y * y <= 25 && i < data->depthmax)
	{
		tmp = cosh(x) * cos(y) - (0.5 * data->mousex / k);
		y = sinh(x) * sin(y) + (0.5 * data->mousey / k);
		x = tmp;
		i++;
	}
	return (i);
}

int	get_iter_julia5(t_data *data, double xx, double yy)
{
	double	x;
	double	y;
	double	tmp;
	int		i;
	double	k;

	x = xx * 0.01667 * data->zoom - 5 * data->zoomx * data->updown;
	y = yy * 0.01667 * data->zoom - 5 * data->zoomy * data->leftright;
	i = 0;
	k = data->width / 2;
	while (x * x + y * y <= 60 && i < data->depthmax)
	{
		tmp = -sin(2 * x) / (cos(2 * x) - cosh(2 * y))
			- (0.5 * data->mousex / k);
		y = sinh(2 * y) / (cos(2 * x) - cosh(2 * y)) + (0.5 * data->mousey / k);
		x = tmp;
		i++;
	}
	return (i);
}

int	get_iter_julia6(t_data *data, double xx, double yy)
{
	double	x;
	double	y;
	double	tmp;
	int		i;
	double	k;

	x = xx * 0.01667 * data->zoom - 5 * data->zoomx * data->updown;
	y = yy * 0.01667 * data->zoom - 5 * data->zoomy * data->leftright;
	i = 0;
	k = data->width / 2;
	while (x * x + y * y <= 25 && i < data->depthmax)
	{
		tmp = x / (x * x + y * y) - (1.5 * data->mousex / k);
		y = -1 * y / (x * x + y * y) + (1.5 * data->mousey / k);
		x = tmp;
		i++;
	}
	return (i);
}

int	get_iter_julia7(t_data *data, double xx, double yy)
{
	double	x;
	double	y;
	double	tmp;
	int		i;
	double	k;

	x = xx * 0.01667 * data->zoom - 5 * data->zoomx * data->updown;
	y = yy * 0.01667 * data->zoom - 5 * data->zoomy * data->leftright;
	i = 0;
	k = data->width / 2;
	while (x * x + y * y <= 25 && i < data->depthmax)
	{
		tmp = x * ft_power(sin(x), 3) - (2.5 * data->mousex / k);
		y = -1 * x * y * ft_power(cos(y), 3) + (2.5 * data->mousey / k);
		x = tmp;
		i++;
	}
	return (i);
}

int	get_iter_julia8(t_data *data, double xx, double yy)
{
	double	x;
	double	y;
	double	tmp;
	int		i;
	double	k;

	x = xx * 0.0065 * data->zoom - 2 * data->zoomx * data->updown;
	y = yy * 0.0065 * data->zoom - 2 * data->zoomy * data->leftright;
	i = 0;
	k = data->width / 2;
	while (x * x + y * y <= 9 && i < data->depthmax)
	{
		tmp = x * x * x - 3 * x * y * y + x + 1
			+ x * x - y * y - (1.5 * data->mousex / k);
		y = 3 * x * x * y - y * y * y
			+ 2 * x * y + y + (1.5 * data->mousey / k);
		x = tmp;
		i++;
	}
	return (i);
}

int	get_iter_julia9(t_data *data, double xx, double yy)
{
	double	x;
	double	y;
	double	tmp;
	int		i;
	double	k;

	x = xx * 0.0065 * data->zoom - 2 * data->zoomx * data->updown;
	y = yy * 0.0065 * data->zoom - 2 * data->zoomy * data->leftright;
	i = 0;
	k = data->width / 2;
	while (x * x + y * y <= 4 && i < data->depthmax)
	{
		tmp = x * x * tan(y) - y * y * atan(x)- (0.5 * data->mousex / k);
		y = 1.17 * x * y * log(x * y) + (0.5 * data->mousey / k);
		x = tmp;
		i++;
	}
	return (i);
}