/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagarri@student.42malaga.com <anagarri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:40:15 by anagarri          #+#    #+#             */
/*   Updated: 2025/05/21 12:04:21 by anagarri@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

/*******Color fractal based in interactions*******/

unsigned int	color_a(double t, double i, double iterations)
{
	unsigned int rgba;

	rgba = 0;
	if(i == iterations)
		return (0x000000FF);
	t = pow(t, 0.3);
	rgba |= ((unsigned int)(sin(t * 6.28318) * 127 + 128) << 24);        // R
	rgba |= ((unsigned int)(sin(t * 6.28318 + 2.094) * 127 + 128) << 16); // G
	rgba |= ((unsigned int)(sin(t * 6.28318 + 4.188) * 127 + 128) << 8);
	rgba |=  255;
	return (rgba);
}


unsigned int	color_b(double t, double i, double iterations)
{
	unsigned int rgba;

	if (i == iterations)
		return 0x000000FF;

	t = pow(t, 0.3);
	t = t * t; // puedes cambiar a t = t * t * t para más contraste
	rgba = 0;
	rgba |= ((unsigned int)(sin(t * 6.28318) * 127 + 128) << 24); // R
	rgba |= ((unsigned int)(sin(t * 6.28318 + 2.094) * 127 + 128) << 16); // G
	rgba |= ((unsigned int)(sin(t * 6.28318 + 4.188) * 127 + 128) << 8); // B
	rgba |= 255;

	return rgba;
}

unsigned int	color_c(double t, double i, double iterations)
{
	unsigned int rgba;

	if (i == iterations)
		return 0x000000FF;
	rgba = 0;
	rgba |= ((unsigned int)(9 * (1 - t) * t * t * t * 255) << 24); // R
	rgba |= ((unsigned int)(15 * (1 - t) * (1 - t) * t * t * 255) << 16); // G
	rgba |= ((unsigned int)(8.5 * (1 - t) * (1 - t) * t * 255) << 8); // B
	rgba |= 255;
	return rgba;
}

unsigned int	color_d(double t, double i, double iterations)
{
	t = t * 1;
	if (i == iterations)
		return 0x000000FF;
	if(i <= iterations && i >= iterations/4)
		return (0x3FD9D9FF);
	else if(i <= iterations/4 && i >= iterations/8)
		return (0x3446D1FF);
	else if(i <= iterations/8 && i >= iterations/12)
		return (0x982CDCFF);
	else if(i <= iterations/12 && i >= iterations/14)
		return (0xDC2CBCFF);
	else if(i <= iterations/14 && i >= iterations/16)
		return (0x000064FF);
	else if(i <= iterations/16 && i >= iterations/20)
		return (0x000032FF);
	else
		return (0x000000FF);
}

unsigned int	get_color_iterations(double i, double iterations)
{
	double t;
	unsigned int rgba;

	t = i/iterations;
	//t = pow(t, 0.3);
	rgba = color_a(t, i, iterations);
	return (rgba);
}

double	calculate_window(int32_t larger, int32_t shorter, double zoom)
{
	return(((double)larger * (+2/zoom)) / (double)shorter);
}

t_complex maintain_proportions(t_fractal *fractal, int x, int y)
{
	t_complex c;
	double new;
	
	if (fractal->height < fractal->width)
	{
		new = calculate_window(fractal->width, fractal->height, fractal->zoom);
		c.y = rescale_map(y, (-2/fractal->zoom), (+2/fractal->zoom), fractal->height);
		c.x = rescale_map(x, -new, +new, fractal->width);
	}
	else
	{
		new = calculate_window(fractal->height, fractal->width, fractal->zoom);
		c.x = rescale_map(x, (-2/fractal->zoom), (+2/fractal->zoom), fractal->width);
		c.y = rescale_map(y, -new, +new, fractal->height);
	}
	return (c);
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
	c.x = maintain_proportions(fractal, x, y).x;
	c.y	= maintain_proportions(fractal, x, y).y;
	while ((i < iterations) && (z.x * z.x + z.y * z.y < 4))
	{
		temp_real = (z.x * z.x) - (z.y * z.y);
		z.y = 2 * z.x * z.y + c.y;
		z.x = temp_real + c.x;
		i++;
	}
	if ((x >= 0 && x < fractal->width) && (y >= 0 && y < fractal->height))
		mlx_put_pixel(fractal->img, x, y, get_color_iterations(i, iterations));
	else
		ft_putstr_fd("Error painting pixels\n", 1);
}
	
/*******julia*******/
	//	f(z) = z^2 + c
	//	z = point
	//	c = constant
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
	z.x = maintain_proportions(fractal, x, y).x;
	z.y	= maintain_proportions(fractal, x, y).y;
	while ((i < iterations) && (z.x * z.x + z.y * z.y < 4))
	{
		temp_real = (z.x * z.x) - (z.y * z.y);
		z.y = 2 * z.x * z.y + c.y;
		z.x = temp_real + c.x;
		i++;
	}
	if ((x >= 0 && x < fractal->width) && (y >= 0 && y < fractal->height))
		mlx_put_pixel(fractal->img, x, y, get_color_iterations(i, iterations));
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
		return (str1[i] - str2[i]);
	return (0);
}

/*******write string*******/
void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if(!s || fd < 0)
		return;
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
