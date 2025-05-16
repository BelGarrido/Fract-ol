/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagarri <anagarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:40:26 by anagarri          #+#    #+#             */
/*   Updated: 2025/05/16 12:50:50 by anagarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# ifndef FRACTOL_H
# define FRACTOL_H

#include <stdlib.h>
#include <stdio.h> // malloc free
#include <unistd.h> // write
#include <math.h>
#include "MLX42.h"

#define WIDTH 800
#define HEIGHT 800

typedef struct s_fractal
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	int			width;
    int			height;
	double		zoom;
	int 		type;
	double		julia_cx;
	double		julia_cy;
	int32_t 	*monitor_heigth;
	int32_t		*monitor_width;
	//	mandelbrot = 1
	//	julia = 2
	} 			t_fractal;

typedef struct	s_complex 
{	
	//	eje real
	double x;
	//	eje imaginario
	double y;
}				t_complex;

/*string utils*/
int				ft_strncmp(char *s1, char *s2, size_t n);
void			ft_putstr_fd(char *s, int fd);
double			ft_atof(const char *s);

/*math*/
double			rescale_map(double number, double new_min, double new_max, double old_max);
void			build_mandelbrot(int x, int y, t_fractal *fractal);
void			build_julia(int x, int y, t_fractal *fractal);

/*hooks*/
void			esc_hook(mlx_key_data_t keydata, void *parameter);
void			zoom_hook(double xdelta, double ydelta, void *parameter);

int				draw_fractal (t_fractal *fractal);
unsigned int	get_color_iterations(int i, int iterations);
void			fractal_init(t_fractal *fractal);

#endif