#include "fractol.h"

/* void build_mandelbrot(int x, int y, t_fractal fractal)
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
} */