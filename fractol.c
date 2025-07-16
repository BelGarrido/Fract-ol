/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagarri@student.42malaga.com <anagarri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:39:58 by anagarri          #+#    #+#             */
/*   Updated: 2025/07/16 12:46:50 by anagarri@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	draw_fractal(t_fractal *fractal)
{
	int	y;
	int	x;

	y = 0;
	while (y < fractal->height)
	{
		x = 0;
		while (x < fractal->width)
		{
			if (fractal->type == 1)
				build_mandelbrot(x, y, fractal);
			else if (fractal->type == 2)
				build_julia(x, y, fractal);
			x++;
		}
		y++;
	}
	return (0);
}

void	init_fractal(t_fractal *fractal)
{
	fractal->zoom = 1.0;
	fractal->width = WIDTH;
	fractal->height = HEIGHT;
	fractal->mlx = mlx_init(fractal->width, fractal->height, "Fract-ol", true);
	if (!fractal->mlx)
	{
		ft_putstr_fd("Error: error initializing mlx\n", 2);
		exit(EXIT_FAILURE);
	}
	fractal->img = mlx_new_image(fractal->mlx, fractal->width, fractal->height);
	if (!fractal->img)
	{
		ft_putstr_fd("Error: error initializing img\n", 2);
		exit(EXIT_FAILURE);
	}
}

void	generate_fractal(t_fractal *fractal)
{
	mlx_image_to_window(fractal->mlx, fractal->img, 0, 0);
	draw_fractal (fractal);
	mlx_key_hook(fractal->mlx, esc_hook, fractal);
	mlx_scroll_hook(fractal->mlx, zoom_hook, &fractal);
	mlx_resize_hook(fractal->mlx, resize_hook, &fractal);
	mlx_loop(fractal->mlx);
	mlx_delete_image(fractal->mlx, fractal->img);
	mlx_terminate(fractal->mlx);
}

int	main(int argc, char *argv[])
{
	t_fractal	fractal;

	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
		|| (argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
	{
		if (!ft_strncmp(argv[1], "mandelbrot", 10))
			fractal.type = 1;
		else if (!ft_strncmp(argv[1], "julia", 5))
		{
			fractal.type = 2;
			fractal.julia_cx = ft_atof(argv[2]);
			fractal.julia_cy = ft_atof(argv[3]);
		}
		init_fractal(&fractal);
		generate_fractal(&fractal);
	}
	else
	{
		ft_putstr_fd("Please enter:\n", 1);
		ft_putstr_fd("\t./fractol mandelbrot\n", 1);
		ft_putstr_fd("\tor\n", 1);
		ft_putstr_fd("\t./fractol julia valueX valueY\n", 1);
		exit(EXIT_FAILURE);
	}
}
