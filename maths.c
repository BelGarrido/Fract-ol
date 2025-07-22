/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagarri@student.42malaga.com <anagarri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:20:49 by anagarri@st       #+#    #+#             */
/*   Updated: 2025/07/21 18:34:50 by anagarri@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	maintain_proportions(t_fractal *fractal, int x, int y)
{
	t_complex	c;
	double		new;

	if (fractal->height < fractal->width)
	{
		new = calculate_window(fractal->width, fractal->height,
				fractal->zoom);
		c.y = rescale_map(y, (-2 / fractal->zoom),
				(+2 / fractal->zoom), fractal->height);
		c.x = rescale_map(x, -new, +new, fractal->width);
	}
	else
	{
		new = calculate_window(fractal->height, fractal->width,
				fractal->zoom);
		c.x = rescale_map(x, (-2 / fractal->zoom),
				(+2 / fractal->zoom), fractal->width);
		c.y = rescale_map(y, -new, +new, fractal->height);
	}
	return (c);
}

double	calculate_window(int32_t larger, int32_t shorter, double zoom)
{
	return (((double)larger * (+2 / zoom)) / (double)shorter);
}

/*******recale map [0 ... 799] -> [-2 ... 2]*******/
double	rescale_map(double number, double new_min, double new_max,
		double old_max)
{
	double	result;

	result = (new_max - new_min) * (number - 0) / (old_max - 0) + new_min;
	return (result);
}

/*******mandelbrot*******/
	//	f(z) = z^2 + c
	//	z = 0
	//	c = point 
void	build_mandelbrot(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	double		temp_real;
	int			i;
	int			iterations;

	z.x = 0.0;
	z.y = 0.0;
	c.x = maintain_proportions(fractal, x, y).x;
	c.y = maintain_proportions(fractal, x, y).y;
	i = 0;
	iterations = 400;
	while ((i < iterations) && (z.x * z.x + z.y * z.y < 4))
	{
		temp_real = (z.x * z.x) - (z.y * z.y);
		z.y = 2 * z.x * z.y + c.y;
		z.x = temp_real + c.x;
		i++;
	}
	if ((x >= 0 && x < fractal->width) && (y >= 0 && y < fractal->height))
		mlx_put_pixel(fractal->img, x, y,
			get_color_iterations_mandelbrot(i, iterations));
	else
		ft_putstr_fd("Error painting pixels\n", 1);
}

/*******julia*******/
	//	f(z) = z^2 + c
	//	z = point
	//	c = constant
void	build_julia(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	double		temp_real;
	double		i;
	double		iterations;

	iterations = 300;
	i = 0;
	c.x = fractal->julia_cx;
	c.y = fractal->julia_cy;
	z.x = maintain_proportions(fractal, x, y).x;
	z.y = maintain_proportions(fractal, x, y).y;
	while ((i < iterations) && (z.x * z.x + z.y * z.y < 4))
	{
		temp_real = (z.x * z.x) - (z.y * z.y);
		z.y = 2 * z.x * z.y + c.y;
		z.x = temp_real + c.x;
		i++;
	}
	if ((x >= 0 && x < fractal->width) && (y >= 0 && y < fractal->height))
		mlx_put_pixel(fractal->img, x, y,
			get_color_iterations_julia(i, iterations));
	else
		ft_putstr_fd("Error painting pixels\n", 1);
}
