/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagarri@student.42malaga.com <anagarri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 12:35:43 by anagarri@st       #+#    #+#             */
/*   Updated: 2025/07/16 12:36:48 by anagarri@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	esc_hook(mlx_key_data_t keydata, void *parameter)
{
	t_fractal	*f;

	f = (t_fractal *)parameter;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_delete_image(f->mlx, f->img);
		mlx_close_window(f->mlx);
	}
}

void	zoom_hook(double xdelta, double ydelta, void *parameter)
{
	t_fractal	*f;

	f = (t_fractal *)parameter;
	xdelta = xdelta * 1;
	if (ydelta > 0)
		f->zoom *= 1.1;
	else if (ydelta < 0)
		f->zoom /= 1.1;
	mlx_delete_image(f->mlx, f->img);
	f->img = mlx_new_image(f->mlx, f->width, f->height);
	draw_fractal(f);
	mlx_image_to_window(f->mlx, f->img, 0, 0);
}

void	resize_hook(int32_t width, int32_t height, void *parameter)
{
	t_fractal	*f;

	f = (t_fractal *)parameter;
	f->height = height;
	f->width = width;
	mlx_delete_image(f->mlx, f->img);
	f->img = mlx_new_image(f->mlx, width, height);
	draw_fractal(f);
	mlx_image_to_window(f->mlx, f->img, 0, 0);
}
