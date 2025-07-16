/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagarri@student.42malaga.com <anagarri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:39:58 by anagarri          #+#    #+#             */
/*   Updated: 2025/06/04 12:26:10 by anagarri@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int draw_fractal(t_fractal *fractal)
{
	int y;
	int x;
	
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
	return 0;
}

/* void init_(t_fractal *fractal)
{
	fractal->zoom = 1.0;
	fractal->width = WIDTH;
	fractal->height = HEIGHT;
	fractal->mlx = mlx_init(fractal->width, fractal->height, "Fract-ol", true);
	if (!fractal->mlx)
	{
		ft_putstr_fd("Error: no se pudo crear la imagen\n", 2);
		exit(EXIT_FAILURE);
	}	
	fractal->img = mlx_new_image(fractal->mlx, fractal->width, fractal->height);
	if (!fractal->img)
	{
		ft_putstr_fd("Error: no se pudo crear la imagen\n", 2);
		exit(EXIT_FAILURE);
	}
} */

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
		fractal.zoom = 1.0;
		fractal.width = WIDTH;
		fractal.height = HEIGHT;
		fractal.mlx = mlx_init(fractal.width, fractal.height, "Fract-ol", true);
		fractal.img = mlx_new_image(fractal.mlx, fractal.width, fractal.height);
		if (!fractal.img)
		{
			ft_putstr_fd("Error: no se pudo crear la imagen\n", 2);
			exit(EXIT_FAILURE);
		}
		mlx_image_to_window(fractal.mlx, fractal.img, 0, 0);
		draw_fractal (&fractal);
		mlx_key_hook(fractal.mlx, esc_hook, &fractal);
		// zoom
		mlx_scroll_hook(fractal.mlx, zoom_hook, &fractal);
		mlx_resize_hook(fractal.mlx, resize_hook, &fractal);
		mlx_loop(fractal.mlx);
		mlx_delete_image(fractal.mlx, fractal.img);   // liberar la última imagen
		mlx_terminate(fractal.mlx);
	}
	else
	{
		ft_putstr_fd("Please enter:\n \t./fractol mandelbrot\n\tor\n \t./fractol julia valueX valueY", 1);
		exit(EXIT_FAILURE);
	}
}

void esc_hook(mlx_key_data_t keydata, void *parameter)
{
	t_fractal *f = (t_fractal *)parameter;
	if(keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_delete_image(f->mlx, f->img);   // liberar la última imagen
		mlx_close_window(f->mlx);
	}	
}

void zoom_hook(double xdelta, double ydelta, void *parameter)
{
	t_fractal *f;
	
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

void resize_hook(int32_t width, int32_t height, void* parameter)
{
	t_fractal *f;
	//printf("resize function\n");
	f = (t_fractal *)parameter;
	f->height = height;
	f->width = width;
	mlx_delete_image(f->mlx, f->img);
	f->img = mlx_new_image(f->mlx, width, height);
	draw_fractal(f);
	mlx_image_to_window(f->mlx, f->img, 0, 0);
}
