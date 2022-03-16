/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fooswyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:53:37 by fooswyn           #+#    #+#             */
/*   Updated: 2022/03/11 18:38:40 by fooswyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractal.h"

t_color	ft_lerp(t_color col1, t_color col2, double delta)
{
	t_color	col;

	col.rgba.r = ft_min((int)col1.rgba.r, (int)col2.rgba.r)
		+(int)(abs(col1.rgba.r - col2.rgba.r) * delta);
	col.rgba.g = ft_min((int)col1.rgba.g, (int)col2.rgba.g)
		+(int)(abs(col1.rgba.g - col2.rgba.g) * delta);
	col.rgba.b = ft_min((int)col1.rgba.b, (int)col2.rgba.b)
		+(int)(abs(col1.rgba.b - col2.rgba.b) * delta);
	col.rgba.a = 0x00;
	return (col);
}

int	ft_color(int i, int max, t_pal *pal)
{
	int		k;
	double	delta;
	t_color	col;

	k = (int)(max / 5);
	delta = (double)(5 * (i % k)) / (double)(max);
	if (i < k)
		col = ft_lerp((t_color)pal->colors[0],
				(t_color)pal->colors[1], delta);
	else if (i < 2 * k)
		col = ft_lerp((t_color)pal->colors[1],
				(t_color)pal->colors[2], delta);
	else if (i < 3 * k)
		col = ft_lerp((t_color)pal->colors[2],
				(t_color)pal->colors[3], delta);
	else if (i < 4 * k)
		col = ft_lerp((t_color)pal->colors[3],
				(t_color)pal->colors[4], delta);
	else if (i < max)
		col = ft_lerp((t_color)pal->colors[4],
				(t_color)FRACT_COLOR, delta);
	else
		return (FRACT_COLOR);
	return (col.value);
}

void	draw(t_data *data, int x, int y, int i)
{
	int		color;
	int		xx;
	int		yy;
	char	*dst;

	color = ft_color(i, data->depthmax, data->pal);
	xx = x * (int)(data->bits_per_pixel * 0.125);
	yy = y * data->line_length;
	dst = data->buf + (xx + yy);
	*(unsigned int *)dst = color;
}
