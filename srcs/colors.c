/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 09:55:26 by asioud            #+#    #+#             */
/*   Updated: 2022/12/27 16:47:44 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

uint32_t	get_rgba(uint32_t r, uint32_t g, uint32_t b, uint32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

uint32_t	get_color(int n, int (*palette)(int), t_data data)
{
	if (n < data.depth && n > 0)
	{
		n += (data.shift / 8);
		return (palette(n));
	}
	return (0xff);
}

int			palette(int n)
{
	uint32_t	palette[10];
	int			i;

	i = 0;
	palette[i++] = get_rgba(3, 50, 112, 255);
	palette[i++] = get_rgba(19, 104, 170, 255);
	palette[i++] = get_rgba(64, 145, 201, 255);
	palette[i++] = get_rgba(157, 206, 226, 255);
	palette[i++] = get_rgba(254, 223, 212, 255);
	palette[i++] = get_rgba(242, 148, 121, 255);
	palette[i++] = get_rgba(242, 106, 79, 255);
	palette[i++] = get_rgba(239, 60, 45, 255);
	palette[i++] = get_rgba(203, 27, 22, 255);
	palette[i] = get_rgba(101, 1, 12, 255);
	return (palette[n % i]);
}

int			red_palette(int n)
{
	uint32_t	palette[20];
	int			i;

	i = 0;
	palette[i++] = get_rgba(255, 0, 0, 255);
	palette[i++] = get_rgba(25, 0, 0, 255);
	palette[i++] = get_rgba(50, 0, 0, 255);
	palette[i++] = get_rgba(75, 0, 0, 255);
	palette[i++] = get_rgba(100, 0, 0, 255);
	palette[i++] = get_rgba(125, 0, 0, 255);
	palette[i++] = get_rgba(150, 0, 0, 255);
	palette[i++] = get_rgba(175, 0, 0, 255);
	palette[i++] = get_rgba(200, 0, 0, 255);
	palette[i++] = get_rgba(225, 0, 0, 255);
	palette[i++] = get_rgba(255, 255, 255, 255);
	return (palette[n % i]);
}

int			wiki_palette(int n)
{
	int			i;
	uint32_t	palette[16];

	i = 0;
	palette[i++] = get_rgba(66, 30, 15, 255);
	palette[i++] = get_rgba(25, 7, 26, 255);
	palette[i++] = get_rgba(9, 1, 47, 255);
	palette[i++] = get_rgba(4, 4, 73, 255);
	palette[i++] = get_rgba(0, 7, 100, 255);
	palette[i++] = get_rgba(12, 44, 138, 255);
	palette[i++] = get_rgba(24, 82, 177, 255);
	palette[i++] = get_rgba(57, 125, 209, 255);
	palette[i++] = get_rgba(134, 181, 229, 255);
	palette[i++] = get_rgba(211, 236, 248, 255);
	palette[i++] = get_rgba(241, 233, 191, 255);
	palette[i++] = get_rgba(248, 201, 95, 255);
	palette[i++] = get_rgba(255, 170, 0, 255);
	palette[i++] = get_rgba(204, 128, 0, 255);
	palette[i++] = get_rgba(153, 87, 0, 255);
	palette[i++] = get_rgba(106, 52, 3, 255);
	return (palette[n % i]);
}
