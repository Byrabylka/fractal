/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fooswyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 19:30:18 by fooswyn           #+#    #+#             */
/*   Updated: 2022/03/13 19:03:49 by fooswyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractal.h"

int	get_iter_julia1(t_data *data, int xx, int yy)
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
		tmp = x * x - y * y - (0.5 * data->mousex / k);
		y = 2 * x * y + (0.5 * data->mousey / k);
		x = tmp;
		i++;
	}
	return (i);
}

int	get_iter_julia2(t_data *data, double xx, double yy)
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
		tmp = x * x * x - 3 * x * y * y - (0.5 * data->mousex / k);
		y = 3 * x * x * y - y * y * y + (0.5 * data->mousey / k);
		x = tmp;
		i++;
	}
	return (i);
}

int	get_iter_julia3(t_data *data, double xx, double yy)
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
		tmp = ft_power(x, 4) - 6 * ft_power(x * y, 2)
			+ ft_power(y, 4) - (0.5 * data->mousex / k);
		y = 4 * ft_power(x, 3) * y - 4 * ft_power(y, 3) * x
			+ (0.5 * data->mousey / k);
		x = tmp;
		i++;
	}
	return (i);
}

int	get_iter_julia(t_data *data, int x, int y)
{
	if (data->choice_julia == 1)
		return (get_iter_julia1(data, x, y));
	if (data->choice_julia == 2)
		return (get_iter_julia2(data, x, y));
	if (data->choice_julia == 3)
		return (get_iter_julia3(data, x, y));
	if (data->choice_julia == 4)
		return (get_iter_julia4(data, x, y));
	if (data->choice_julia == 5)
		return (get_iter_julia5(data, x, y));
	if (data->choice_julia == 6)
		return (get_iter_julia6(data, x, y));
	if (data->choice_julia == 7)
		return (get_iter_julia7(data, x, y));
	if (data->choice_julia == 8)
		return (get_iter_julia8(data, x, y));
	if (data->choice_julia == 9)
		return (get_iter_julia9(data, x, y));
	return (get_iter_julia7(data, x, y));
}

int	julia(t_data *data)
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
			i = get_iter_julia(data, x, y);
			draw(data, x, y, i);
			y++;
		}
		x++;
	}
	return (0);
}
