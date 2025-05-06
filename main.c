#include "fractol.h"

int	main(int argc, char *argv[])
{
	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
	|| (argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
	{
		//is correct
		//comenzar la aplicación
		t_fractal fractal;
		fractal.mlx = mlx_init(WIDTH, HEIGHT, "Fract-ol", false);
		fractal.img = mlx_new_image(fractal.mlx, WIDTH, HEIGHT);
		fractal.width = WIDTH;
		fractal.height = HEIGHT;
		mlx_image_to_window(fractal.mlx, fractal.img, 0, 0);

	}
	else
	{
		ft_putstr_fd("Please enter:\n \t./fractol mandelbrot\n\tor\n \t./fractol julia valueX valueY", 1);
		exit(EXIT_FAILURE );
	}
}