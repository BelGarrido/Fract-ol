/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagarri <anagarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:39:58 by anagarri          #+#    #+#             */
/*   Updated: 2025/05/19 14:27:36 by anagarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int draw_fractal (t_fractal *fractal)
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
	return 0;
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
		printf("x: %f // y: %f\n", fractal.julia_cx, fractal.julia_cy);
		fractal.zoom = 1.0;
		fractal.mlx = mlx_init(WIDTH, HEIGHT, "Fract-ol", true);
		fractal.img = mlx_new_image(fractal.mlx, WIDTH, HEIGHT);
		if (!fractal.img)
		{
			ft_putstr_fd("Error: no se pudo crear la imagen\n", 2);
			exit(EXIT_FAILURE);
		}
		fractal.width = WIDTH;
		fractal.height = HEIGHT;
		mlx_image_to_window(fractal.mlx, fractal.img, 0, 0);
		draw_fractal (&fractal);
		mlx_key_hook(fractal.mlx, esc_hook, &fractal);
		// zoom
		mlx_scroll_hook(fractal.mlx, zoom_hook, &fractal);
		//mlx_resize_hook(mlx_t* mlx, mlx_resizefunc func, void* param);
		//mlx_loop_hook(fractal.mlx, render_frame, &fractal);
		mlx_loop(fractal.mlx);
	}
	else
	{
		ft_putstr_fd("Please enter:\n \t./fractol mandelbrot\n\tor\n \t./fractol julia valueX valueY", 1);
		exit(EXIT_FAILURE );
	}
}

/* ESC debe cerrar la ventana y salir del programa de manera limpia.
	1- escribir la función que maneja la tecla ESC
	* Callback function used to handle keypresses.
	* 
	* @param[in] keydata The callback data, contains info on key, action, ...
	* @param[in] parameter s un puntero que pasas tú (en este caso, al struct t_fractal)..
	*/
void esc_hook(mlx_key_data_t keydata, void *parameter)
{
	t_fractal *f = (t_fractal *)parameter;
	if(keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(f->mlx);
}

void zoom_hook(double xdelta, double ydelta, void *parameter)
{
	t_fractal *f = parameter;

	xdelta = xdelta * 1;
	if (ydelta > 0)
		 f->zoom *= 1.1;
    else if (ydelta < 0)
		f->zoom /= 1.1;
	draw_fractal(f);
}


/**
 * This function sets the resize callback, which is called when the window is
 * resized
 * 
 * @param[in] mlx The MLX instance handle.
 * @param[in] func The resize callback function.
 * @param[in] param An additional optional parameter.

void mlx_resize_hook(mlx_t* mlx, mlx_resizefunc func, void* param); */

/* void zoom_hook(double xdelta, double ydelta, void *parameter)
{
	t_fractal *f = (t_fractal *)parameter;

	xdelta = xdelta * 1;
	if (ydelta > 0)
	{
		 f->zoom *= 1.1;
	}
    else if (ydelta < 0)
	{
		f->zoom /= 1.1;
	}
	uint32_t *pixel_buffer = (uint32_t *)f->img->pixels;
	draw_square(*f, pixel_buffer);
	redraw_fractal(f); // TODO
} */