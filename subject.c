/* 
* Julia and Mandelbrot
* Inifite zoom
* Able to take comand line arg to indicate which fractal to render
* Able to take line arg to chape Julia, x, y coordinates
* ESC closes the process with no leaks
* Click on the X windows, closes the process leaks free
* 
* Inputs
*	./fractol mandelbrot
*	./fractol julia <real> <i>
*
*/




/*
From math to code
	1.Setup the MiniLibX library.
		You can find good resources on how to do this here.
		
	2.Create a window, image and all the necessary things in the MiniLibX.
	
	3.Iterate through every pixel of the window.
		See draw_fractal.
		
	4.For every pixel, calculate the complex number it represents and put it into the suite.
		See calculate_mandelbrot for example.
		
	5.If the suite diverges, color the pixel in white.
		If the suite converges, color the pixel in black.
*/
