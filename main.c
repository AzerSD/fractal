/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 08:52:17 by asioud            #+#    #+#             */
/*   Updated: 2022/12/27 16:42:21 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

int	init_data(t_data *data)
{
	if (data->depth != 20)
		data->depth = 50;
	data->palette = &palette;
	data->scale = 4;
	data->shift = 0;
	data->xoffset = 0;
	data->yoffset = 0;
	data->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", false);
	if (!(data->mlx))
		return (0);
	data->g_img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!(data->g_img))
		return (0);
	mlx_image_to_window(data->mlx, data->g_img, 0, 0);
	return (1);
}

int32_t	main(int argc, char **argv)
{
	t_data	data;
	arg_parse(argc, argv, &data);
	if (!(init_data(&data)))
		return (EXIT_FAILURE);
	mlx_loop_hook(data.mlx, &key_hook, &data);
	mlx_scroll_hook(data.mlx, &zoom_hook, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	return (EXIT_SUCCESS);
}
