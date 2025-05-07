#include "fractol.h"

int	main(int argc, char *argv[])
{
	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
	|| (argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
	{
		//is correct
		//comenzar la aplicación
		t_fractal fractal;
		// 1. Inicialización de la ventana
		// false: tamaño predeterminado / true: pantalla completa (?)
		fractal.mlx = mlx_init(WIDTH, HEIGHT, "Fract-ol", true);
		/* 
		2. Creación y manipulación de imágenes
		Para acceder y modificar los píxeles de la imagen:
			uint32_t* pixels = (uint32_t*)image->pixels;
			pixels[y * image->width + x] = color;
			Nota: Asegúrate de calcular correctamente la posición del píxel
			utilizando la fórmula y * width + x.
		*/
		fractal.img = mlx_new_image(fractal.mlx, WIDTH, HEIGHT);
		
		fractal.width = WIDTH;
		fractal.height = HEIGHT;
		/*
		3. Mostrar la imagen en la ventana
			mlx: Puntero a la instancia de MLX.
			image: Puntero a la imagen a mostrar.
			x: Posición horizontal en la ventana.
			y: Posición vertical en la ventana.
		Retorna: Un identificador de la imagen en la ventana.
		*/
		mlx_image_to_window(fractal.mlx, fractal.img, 0, 0);
		uint32_t *pixel_buffer = (uint32_t *)fractal.img->pixels;
		int y = 0;
		int x = 0;
		while (y < 100)
		{
			x = 0;
			while(x < 100)
			{
				//										0xAARRGGBB
				pixel_buffer[y * fractal.img->width + x] = 0xFF6600FF;
				x++;
			}
			y++;
		}
		int z;
		y = 0;
		while (y < 100)
		{
			z = 100;
			while(z < 200)
			{
				//										0xAARRGGBB
				pixel_buffer[y * fractal.img->width + z] = 0xFF1100FF;
				z++;
			}
			y++;
		}
		/*
		4. Mantener
		*/ 
		mlx_loop(fractal.mlx);
	}
	else
	{
		ft_putstr_fd("Please enter:\n \t./fractol mandelbrot\n\tor\n \t./fractol julia valueX valueY", 1);
		exit(EXIT_FAILURE );
	}
}