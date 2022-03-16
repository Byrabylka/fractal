/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fooswyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:25:39 by fooswyn           #+#    #+#             */
/*   Updated: 2022/03/11 18:30:00 by fooswyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractal.h"

int	ft_min(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	ft_strcmp(char *a, char *b)
{
	int	i;

	i = 0;
	while (a[i] && b[i] && a[i] == b[i])
		i++;
	return (b[i] - a[i]);
}

double	ft_power(double x, int deg)
{
	if (deg == 0)
		return (1);
	else
		return (x * ft_power(x, deg - 1));
}
