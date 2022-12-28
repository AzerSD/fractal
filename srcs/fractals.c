/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:05:29 by asioud            #+#    #+#             */
/*   Updated: 2022/12/28 22:25:41 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mandelbrot(int x, int y, t_data *fractol)
{
	int			iter;
	t_complex	c;
	t_complex	z;
	t_complex	z2;

	z2 = (t_complex){0, 0};
	z = (t_complex){0, 0};
	c = (t_complex){convert_x(x, fractol) + fractol->xoffset,
		convert_y(y, fractol) + fractol->yoffset};
	iter = 0;
	while (z2.real + z2.imm <= 4 && iter < fractol->depth)
	{
		z.imm = 2 * z.real * z.imm + c.imm;
		z.real = z2.real - z2.imm + c.real;
		z2.real = z.real * z.real;
		z2.imm = z.imm * z.imm;
		iter++;
	}
	return (iter);
}

int	julia(int x, int y, t_data *fractol)
{
	int			iter;
	double		tmp;
	t_complex	z;

	z = (t_complex){
		convert_x(x, fractol) + fractol->xoffset,
		convert_y(y, fractol) + fractol->yoffset};
	iter = 0;
	while (sqr_d(z.real) + sqr_d(z.imm) <= 4 && iter < fractol->depth)
	{
		tmp = sqr_d(z.real) - sqr_d(z.imm);
		z.imm = 2 * z.real * z.imm + fractol->cy;
		z.real = tmp + fractol->cx;
		iter++;
	}
	return (iter);
}

int	burning_ship(int x, int y, t_data *fractol)
{
	int			iter;
	double		temp;
	t_complex	z;

	z = (t_complex){
		convert_x(x, fractol) + fractol->xoffset,
		convert_y(y, fractol) + fractol->yoffset};
	fractol->cx = z.real;
	fractol->cy = z.imm;
	iter = 0;
	while ((sqr_d(z.real) + sqr_d(z.imm)) <= 4 && iter < fractol->depth)
	{
		temp = sqr_d(z.real) - sqr_d(z.imm) + fractol->cx;
		z.imm = fabs(2 * z.real * z.imm) + fractol->cy;
		z.real = temp;
		iter++;
	}
	return (iter);
}
