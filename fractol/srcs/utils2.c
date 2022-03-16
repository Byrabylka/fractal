/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fooswyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:04:09 by fooswyn           #+#    #+#             */
/*   Updated: 2022/03/11 21:00:20 by fooswyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractal.h"

double	get_rand1(void)
{
	int	a;
	int	t;
	int	c;
	int	i;

	a = 42;
	t = ((int)time(NULL)) % 131;
	c = 73;
	i = 0;
	while (i < 100)
	{
		t = (a * t + c) % 131;
		i++;
	}
	if (t % 2)
		t *= -1;
	return ((double)t / 131);
}

double	get_rand2(void)
{
	int	a;
	int	t;
	int	c;
	int	i;

	a = 98;
	t = ((int)time(NULL)) % 101;
	c = 11;
	i = 0;
	while (i < 100)
	{
		t = (a * t + c) % 101;
		i++;
	}
	if (t % 2)
		t *= -1;
	return ((double)t / 101);
}
