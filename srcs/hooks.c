/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 07:18:22 by asioud            #+#    #+#             */
/*   Updated: 2022/12/27 16:48:53 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	zoom_hook(double xdelta, double ydelta, void *param)
{
	t_data	*fractol;
	float	cx;
	float	cy;
	int		x;
	int		y;

	(void)xdelta;
	fractol = param;
	mlx_get_mouse_pos(fractol->mlx, &x, &y);
	cx = convert_x(x, fractol);
	cy = convert_y(y, fractol);
	if (ydelta > 0)
		fractol->scale *= 0.9;
	else if (ydelta < 0)
		fractol->scale *= 1.1;
	fractol->xoffset += cx - convert_x(x, fractol);
	fractol->yoffset += cy - convert_y(y, fractol);
}

void	shifting(t_data *fractol)
{
	int	x;
	int	y;

	mlx_get_mouse_pos(fractol->mlx, &x, &y);
	if (mlx_is_mouse_down(fractol->mlx, MLX_MOUSE_BUTTON_LEFT))
	{
		fractol->cx = convert_x(x, fractol);
		fractol->cy = convert_y(y, fractol);
		fractol->shift += 5;
	}
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_ENTER))
	{
		if (fractol->palette == palette)
			fractol->palette = red_palette;
		else if (fractol->palette == red_palette)
			fractol->palette = wiki_palette;
		else
			fractol->palette = palette;
	}
}

void	key_hook(void *param)
{
	t_data	*fractol;

	fractol = param;
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fractol->mlx);
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_RIGHT))
		fractol->xoffset -= 0.1 * (fractol->scale / 4);
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_LEFT))
		fractol->xoffset += 0.1 * (fractol->scale / 4);
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_UP))
		fractol->yoffset -= 0.1 * (fractol->scale / 4);
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_DOWN))
		fractol->yoffset += 0.1 * (fractol->scale / 4);
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_MINUS))
		fractol->depth -= 10;
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_EQUAL))
		fractol->depth += 10;
	shifting(fractol);
	draw_fract(fractol);
}
