/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fooswyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:23:26 by fooswyn           #+#    #+#             */
/*   Updated: 2022/03/12 18:57:15 by fooswyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractal.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	if (!pars(&data, argc, argv))
	{
		ft_putstr("Wrong parameter! Avalible parametrs: mandelbrot(1-4),\
			julia(1-8)");
		return (0);
	}
	init(&data);
	frac(&data);
	mlx_hook(data.win, 17, 1L << 2, closewin, &data);
	mlx_hook(data.win, 06, 1L << 6, locmouse, &data);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_mouse_hook(data.win, mouse_hook, &data);
	mlx_loop(data.mlx);
}
