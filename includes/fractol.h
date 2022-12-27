/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:29:24 by asioud            #+#    #+#             */
/*   Updated: 2022/12/27 16:47:50 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../libs/mlx/include/MLX42/MLX42.h"
# include "../libs/libft/includes/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h>

# define WIDTH 500
# define HEIGHT 500

typedef struct mouse
{
	int					(*palette)(int);
	int					(*set)();
	int					depth;
	int					shift;
	double				scale;
	double				xoffset;
	double				yoffset;
	double				cx;
	double				cy;
	mlx_t				*mlx;
	mlx_image_t			*g_img;
}	t_data;

////////////////////////////////////////////////////////
////  				Draw utils	 					////
////////////////////////////////////////////////////////
void		draw_fract(t_data *data);
double		convert_x(int x, t_data *data);
double		convert_y(int y, t_data *data);

////////////////////////////////////////////////////////
////  					Parsing 					////
////////////////////////////////////////////////////////
void		arg_parse(int argc, char **argv, t_data *data);
void		input_error(void);

////////////////////////////////////////////////////////
////  					Colors	 					////
////////////////////////////////////////////////////////
uint32_t	get_rgba(uint32_t r, uint32_t g, uint32_t b, uint32_t a);
uint32_t	get_color(int n, int (*palette)(int), t_data data);
int			palette(int n);
int			red_palette(int n);
int			wiki_palette(int n);

////////////////////////////////////////////////////////
////  					HOOKS 						////
////////////////////////////////////////////////////////
void		zoom_hook(double xdelta, double ydelta, void *param);
void		key_hook(void *param);

////////////////////////////////////////////////////////
////  				Fractal Sets 					////
////////////////////////////////////////////////////////
int			mandelbrot(int x, int y, t_data *data);
int			julia(int x, int y, t_data *data);
int			burning_ship(int x, int y, t_data *data);

#endif
