/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagarri <anagarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:39:58 by anagarri          #+#    #+#             */
/*   Updated: 2025/05/16 12:52:09 by anagarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int draw_fractal(t_fractal *fractal)
{
	int y;
	int x;
	
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
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

void fractal_init(t_fractal *fractal)
{
	fractal->zoom = 1.0;
	fractal->mlx = mlx_init(WIDTH, HEIGHT, "Fract-ol", true);
	if (!fractal->mlx)
	{
		ft_putstr_fd("Error: mlx could not be initialised\n", 2);
		exit(EXIT_FAILURE);
	}
	fractal->img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (!fractal->img)
	{
		ft_putstr_fd("Error: image could not be created\n", 2);
		exit(EXIT_FAILURE);
	}
	/* fractal->monitor_heigth;
	fractal->monitor_width;
	mlx_get_monitor_size(0, fractal->monitor_width, fractal->monitor_heigth);
	fractal->width = WIDTH; */
	fractal->height = HEIGHT;
	//mlx_image_to_window(fractal->mlx, fractal->img, 0, 0);
}

int	main(int argc, char *argv[])
{
	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
	|| (argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
	{
		t_fractal	fractal;
		
		if (!ft_strncmp(argv[1], "mandelbrot", 10))
			fractal.type = 1;
		else if (!ft_strncmp(argv[1], "julia", 5))
		{
			fractal.type = 2;
			fractal.julia_cx = ft_atof(argv[2]);
			fractal.julia_cy = ft_atof(argv[3]);
		}
		
		fractal_init(&fractal);
		draw_fractal (&fractal);
		/* int pos_x = (*fractal.monitor_width - fractal.img->width) / 2;
		int pos_y = (*fractal.monitor_heigth - fractal.img->height) / 2;
		mlx_image_to_window(fractal.mlx, fractal.img, pos_x, pos_y); */
		mlx_key_hook(fractal.mlx, esc_hook, &fractal);
		mlx_scroll_hook(fractal.mlx, zoom_hook, &fractal);
		mlx_loop(fractal.mlx);
		mlx_terminate(fractal.mlx);
	}
	else
	{
		ft_putstr_fd("Please enter:\n \t./fractol mandelbrot\n\tor\n \t./fractol julia valueX valueY", 1);
		exit(EXIT_FAILURE );
	}
}

void esc_hook(mlx_key_data_t keydata, void *parameter)
{
	t_fractal *f = parameter;
	if(keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(f->mlx);
}

void zoom_hook(double xdelta, double ydelta, void *parameter)
{
	t_fractal *f = (t_fractal *)parameter;

	xdelta = xdelta * 1;
	if (ydelta > 0)
		 f->zoom *= 1.1;
    else if (ydelta < 0)
		f->zoom /= 1.1;
	draw_fractal (f);
}