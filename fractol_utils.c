/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagarri <anagarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:40:15 by anagarri          #+#    #+#             */
/*   Updated: 2025/05/19 12:30:51 by anagarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

/*******Color fractal based in interactions*******/
unsigned int	get_color_iterations(double i, double iterations)
{
	double t;
	unsigned int rgba;

	t = i/iterations;
	rgba = 0;

	rgba |= (((unsigned int)(255 * (9 * (1 - t) * t * t * t)) & 0xFF) << 24); //R 
	rgba |= (((unsigned int)(255 * (15 * (1 - t) * (1 - t) * t * t)) & 0xFF) << 16); //G
	rgba |= (((unsigned int)(255 * (8.5 * (1 - t) * (1 - t) * (1 - t) * t)) & 0xFF) << 8); //B
	rgba |=  255;
	//printf("%u\n", rgba);
	return (rgba);
/* 	if(i <= iterations && i >= iterations/4)
	{
		// Turquesa -- nearest to mandelbrot set
		return (0xFFD9D93F);
	}
	else if(i <= iterations/4 && i >= iterations/8)
	{	
		//Azul oscuro
		return (0xFFD14634);
	}
	else if(i <= iterations/8 && i >= iterations/12)
	{
		// Morado
		return (0xFFDC2C98);
	}
	else if(i <= iterations/12 && i >= iterations/14)
	{
		//Magenta
		return (0xFFBC2CDC);
	}
	else if(i <= iterations/14 && i >= iterations/16)
	{
		//Azul menos oscuro
		return (0xFF640000);
	}
	else if(i <= iterations/16 && i >= iterations/20)
	{
		//Azul oscuro
		return (0xFF320000);
	}
	else
	{
		// Negro -- farest to mandelbrot set
		return (0xFFFFFFFF);
	} */
}

/*******mandelbrot*******/
	//	f(z) = z^2 + c
	//	z = 0
	//	c = point 
void build_mandelbrot(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	double	temp_real;
	int i;
	int iterations;
	
	iterations = 400;
	i = 0;
	z.x = 0.0;
	z.y = 0.0;
	c.x = rescale_map(x, -2, +2, WIDTH);
	c.y	= rescale_map(y, -2, +2, HEIGHT);
	while ((i < iterations) && (z.x * z.x + z.y * z.y < 4))
	{
		temp_real = (z.x * z.x) - (z.y * z.y);
		z.y = 2 * z.x * z.y + c.y;
		z.x = temp_real + c.x;
		i++;
	}
	if ((x >= 0 && x < WIDTH) && (y >= 0 && y < HEIGHT))
	{
		if (i == iterations)
		{
			mlx_put_pixel(fractal->img, x, y, 0x000000FF);

		}
		else
			mlx_put_pixel(fractal->img, x, y, get_color_iterations(i, iterations));
	}
	else
		ft_putstr_fd("Error painting pixels\n", 1);
}
	
/*******mandelbrot*******/
	//	f(z) = z^2 + c
	//	z = 0
	//	c = point
void build_julia(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	double	temp_real;
	double i;
	double iterations;
	
	iterations = 300;
	i = 0;
	c.x = fractal->julia_cx;
	c.y = fractal->julia_cy;

	z.x = rescale_map(x, -2, +2, WIDTH);
	z.y	= rescale_map(y, -2, +2, HEIGHT);
	while ((i < iterations) && (z.x * z.x + z.y * z.y < 4))
	{
		temp_real = (z.x * z.x) - (z.y * z.y);
		z.y = 2 * z.x * z.y + c.y;
		z.x = temp_real + c.x;
		i++;
	}
	if((x >= 0 && x < WIDTH) && (y >= 0 && y < HEIGHT))
	{
		if (i == iterations)
		{
			mlx_put_pixel(fractal->img, x, y, 0x0000FFFF);
		}
		else
			mlx_put_pixel(fractal->img, x, y, get_color_iterations(i, iterations));
	}
	else
		ft_putstr_fd("Error painting pixels\n", 1);
}	

/*******recale map [0 ... 799] -> [-2 ... 2]*******/
double rescale_map(double number, double new_min, double new_max, double old_max)
{
	double result = (new_max - new_min) * (number - 0) / (old_max - 0) + new_min;
	return (result);
}

/*******compare 2 strings**********/
int	ft_strncmp(char *s1, char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (str1[i] != '\0' && str2[i] != '\0' && (i < n))
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	if (i < n)
	{
		return (str1[i] - str2[i]);
	}
	return (0);
}

/*******write string*******/
void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if(!s || fd < 0)
	{
		return;
	}
	i = 0;
	while (s[i] != '\0')
	{
		write (fd, &s[i], 1);
		i++;
	}
}
/*******ascii to int*******/
double	ft_atof(const char *s)
{
	int	i;
	double	neg;
	double	number;
	double decimal;

	decimal= 0.1;
	i = 0;
	neg = 1;
	number = 0;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
		i++;
	if (s [i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			neg = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
		number = number * 10 + s[i++] - '0';
	if (s[i] == '.')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		number = number + (s[i++] - '0') * decimal;
		decimal = decimal * 0.1;
	}
	return (number * neg);
}
