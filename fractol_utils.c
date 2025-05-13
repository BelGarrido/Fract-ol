#include "fractol.h"

/*recale map [0 ... 799] -> [-2 ... 2]*/
double rescale_map(double number, double new_min, double new_max, double old_max)
{
	double result = (new_max - new_min) * (number - 0) / (old_max - 0) + new_min;
	return (result);
}
/*mandelbrot*/
void build_mandelbrot(int x, int y, t_fractal fractal)
{
	//	f(z) = z^2 + c
	//	z 
	t_complex	z;
	//	point
	t_complex	c;
	double	temp_real;
	int i = 0;

	z.x = 0.0;
	z.y = 0.0;

	c.x = rescale_map(x, -2, +2, WIDTH);;
	c.y	= rescale_map(y, +2, -1, HEIGHT);;

	while (i < 42)
	{
		temp_real = (z.x * z.x) - (z.y * z.y);
		z.y = 2 * z.x * z.y;
		z.x = temp_real;
		//	Addyng c 
		z.x = z.x + c.x;
		z.y = z.y + c.y;

		uint32_t *pixel_buffer = (uint32_t *)fractal.img->pixels;
		if ((z.x > -1.5 && z.x < +0.5) && (z.y > -1 && z.y < +1))
		{
			pixel_buffer[y * fractal.img->width + x] = 0xFF6600FF;
			printf("iteration nº: %d\n real: %f imaginary: %f\n", i, z.x, z.y);
		}
		i++;
	}
}

/*compare 2 strings*/
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

/*write string*/
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