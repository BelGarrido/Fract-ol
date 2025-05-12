#include "fractol.h"

int	main(int argc, char *argv[])
{
	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
	|| (argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
	{
		//is correct
		//comenzar la aplicación
		t_fractal fractal;
		fractal.zoom = 1.0; /*inicializacion de la variable zoom*/
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

		// ESC make the program to finish
		mlx_key_hook(fractal.mlx, esc_hook, &fractal);
		// zoom
		mlx_scroll_hook(fractal.mlx, zoom_hook, &fractal);
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
	t_fractal *f = (t_fractal *)parameter;
	xdelta = xdelta * 1;
	if (ydelta > 0)
        f->zoom *= 1.1;
    else if (ydelta < 0)
        f->zoom /= 1.1;
	/*redraw_fractal(f); // TODO*/
}

/* int draw_fractal (t_fractal *fractal)
{
	int y;
	int x;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (ft_strncmp("mandelbrot"))
			{
				build_mandelbrot(fractal, x,y); //TO DO
			}
			else if (ft_strncmp("julia"))
			{
				build_julia(fractal, x, y); //TO DO
			}
			x++;
		}
		y++;
	}
} */