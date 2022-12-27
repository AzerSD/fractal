/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:06:36 by asioud            #+#    #+#             */
/*   Updated: 2022/12/27 12:46:32 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	arg_parse(int argc, char **argv, t_data *fractol)
{
	if (argc == 2)
	{
		if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
			fractol->set = &mandelbrot;
		else if (ft_strncmp(argv[1], "burning_ship", 12) == 0)
		{
			fractol->set = &burning_ship;
			fractol->depth = 20;
		}
		else
		{
			input_error();
			exit(EXIT_FAILURE);
		}
	}
	else if (argc == 4
		&& ft_strncmp(argv[1], "julia", 5) == 0
		&& ft_isfloat(argv[2]) && ft_isfloat(argv[3]))
	{
		fractol->set = &julia;
		fractol->cx = ft_atof(argv[2]);
		fractol->cy = ft_atof(argv[3]);
	}
	else
	{
		input_error();
		exit(EXIT_FAILURE);
	}
}

void	input_error(void)
{
	write(2, "!!! Input Error !!!\n\n", 21);
	write(1, "$ ./fract [ set ] optional:[ real imaginairy ]", 46);
	write(1, "\ne.g:", 5);
	write(1, "\t$ ./fract mandelbrot\n", 22);
	write(1, "\t$ ./fract julia -0.811 -0.174\n", 31);
	write(1, "\t$ ./fract burning_ship\n", 24);
	write(1, "\nAvailable sets: mandelbrot, julia, burning_ship\n\n", 50);
	exit(EXIT_FAILURE);
}
