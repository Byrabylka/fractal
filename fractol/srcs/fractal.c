/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fooswyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:43:07 by fooswyn           #+#    #+#             */
/*   Updated: 2022/03/13 18:41:41 by fooswyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractal.h"

void	draw_string(t_data *data)
{
	mlx_string_put(data->mlx, data->win, 0, 10, 0xFFFFFF, "Color: 1-6");
	mlx_string_put(data->mlx, data->win, 0, 30, 0xFFFFFF, "Reset: Space");
	if (data->choice == 2)
		mlx_string_put(data->mlx, data->win, 0, 30, 0xFFFFFF, "Pause: P");
	if (data->depthmax <= 10000)
	{
	mlx_string_put(data->mlx, data->win, 110, 50, 0xFFFFFF,
		ft_itoa(data->depthmax));
	}
	else
		mlx_string_put(data->mlx, data->win, 110, 50, 0xFFFFFF, "Blyat', stop!");
	
	mlx_string_put(data->mlx, data->win, 0, 50, 0xFFFFFF, "Max death:");
}

int	frac(t_data *data)
{
	if (data->choice == 1)
		mandelbrot(data);
	else if (data->choice == 2)
		julia(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	draw_string(data);
	return (0);
}
