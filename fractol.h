/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagarri@student.42malaga.com <anagarri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:40:26 by anagarri          #+#    #+#             */
/*   Updated: 2025/07/16 12:18:07 by anagarri@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h> // malloc free
# include <unistd.h> // write
# include <math.h>
# include "MLX42.h"

# define WIDTH 800
# define HEIGHT 600

typedef struct s_fractal
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	int32_t		width;
	int32_t		height;
	double		zoom;
	int			type;
	double		julia_cx;
	double		julia_cy;
	//	mandelbrot = 1
	//	julia = 2
}				t_fractal;

	//	eje real
	//	eje imaginario
typedef struct s_complex
{
	double	x;
	double	y;
}				t_complex;

/*string utils*/
int				ft_strncmp(char *s1, char *s2, size_t n);
void			ft_putstr_fd(char *s, int fd);
double			ft_atof(const char *s);

/*math*/
double			rescale_map(double number, double new_min, double new_max,
					double old_max);
void			build_mandelbrot(int x, int y, t_fractal *fractal);
void			build_julia(int x, int y, t_fractal *fractal);

/*hooks*/
void			esc_hook(mlx_key_data_t keydata, void *parameter);
void			resize_hook(int32_t width, int32_t height, void *parameter);
void			zoom_hook(double xdelta, double ydelta, void *parameter);

double			calculate_window(int32_t larger, int32_t shorter, double zoom);
t_complex		maintain_proportions(t_fractal *fractal, int x, int y);
int				draw_fractal(t_fractal *fractal);
unsigned int	get_color_iterations(double i, double iterations);

#endif