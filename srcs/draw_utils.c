/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 10:49:49 by asioud            #+#    #+#             */
/*   Updated: 2022/12/27 15:49:09 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	draw_fract(t_data *data)
{
	int32_t		x;
	int32_t		y;
	int			depth;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			depth = data->set(x, y, data);
			mlx_put_pixel(data->g_img, x, y,
				get_color(
					data->set(x, y, data),
					data->palette, *data)
				);
			y++;
		}
		x++;
	}
}

double	convert_x(int x, t_data *data)
{
	return ((double)x / WIDTH * data->scale + -data->scale / 2);
}

double	convert_y(int y, t_data *data)
{
	return ((double)y / HEIGHT * -data->scale + data->scale / 2);
}
