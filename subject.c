/* 
* Julia and Mandelbrot
* Inifite zoom
* Able to take comand line arg to indicate which fractal to render
* Able to take line arg to shape Julia, x, y coordinates
* ESC closes the process with no leaks
* Click on the X windows, closes the process leaks free
* 
* Inputs
*	./fractol mandelbrot
*	./fractol julia <real> <i>
*
*/

/*********** MATHS **************/

/* En el conjunto de Mandelbrot, los puntos que se mantienen cerca del origen (que no se
alejan más allá de distancia 2, es decir, |z| <= 2) pertenecen al conjunto.
Si |z| se hace mayor a 2 → el punto se escapa → no es parte del conjunto
Por eficiencia, usamos:
x^2 + y^2 > 4
*/

/*
From math to code
	1.Setup the MiniLibX library. DONE
		You can find good resources on how to do this here.
		
	2.Create a window, image and all the necessary things in the MiniLibX. DONE
	
	3.Iterate through every pixel of the window.
		See draw_fractal.
		
	4.For every pixel, calculate the complex number it represents and put it into the suite.
		See calculate_mandelbrot for example.
		
	5.If the suite diverges, color the pixel in white.
		If the suite converges, color the pixel in black.
*/


/*********** IMAGEN **************/
/* typedef struct mlx_image
{
	const uint32_t	width;
	const uint32_t	height;
	uint8_t*		pixels;
	mlx_instance_t*	instances;
	size_t			count;
	bool			enabled;
	void*			context;
}	mlx_image_t; 
	
Este campo contiene todos los píxeles de la imagen en formato ARGB, uno tras otro en
memoria (linealmente), 8 bits por canal × 4 canales = 32 bits = 4 bytes por píxel.
*/

/*********** PIXELES **************/
/*
	fractal.img ->pixels;
	Cada píxel ocupa 4 bytes (32 bits → uint32_t).
	En lugar de manipular byte a byte (uint8_t*), es más cómodo trabajar píxel a píxel.
	uint32_t *pixel_buffer = (uint32_t *)img->pixels;
	pixel_buffer[y * img->width + x] = 0xFF0000FF; // Azul opaco

	Dato						¿Dónde se guarda?
	Color de cada píxel			img->pixels (como uint32_t *)
	Variables temporales		(x,y,iter)	Locales en el bucle de render
	Configuración global		(zoom, offset, tipo)	Dentro del t_fractal

*/


/********** ZOOM ***********/
/*
📌 ¿Cómo se usa zoom en el dibujo?
Cuando calcules cada punto del fractal (por ejemplo, mapeando de x, y en pantalla a coordenadas del plano complejo), deberías hacer algo como:

c
Copy
Edit
real = (x - width / 2.0) * scale * fractal->zoom + offset_x;
imag = (y - height / 2.0) * scale * fractal->zoom + offset_y;
Así el zoom afecta cómo de “cerca” estás del fractal.
*/