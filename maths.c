/* #include "MLX42.h" */

/* typedef struct	s_complex 
{	
	//	eje x
	double real;
	//	eje y
	double i;
}				t_complex;

int main()
{
	t_complex	z;
	//	point
	t_complex	c;
	double	temp_real;
	int i = 0;

	z.real = 0;
	z.i = 0;

	c.real = 0.25;
	c.i	= 0.4;
	while (i < 42)
	{
		//	f(z) = z^2 + c
		//	z 
		temp_real = (z.real * z.real) - (z.i * z.i);
		z.i = 2 * z.real * z.i;
		z.real = temp_real;
		//	Adding c 
		z.real = z.real + c.real;
		z.i = z.i + c.i;
		printf("iteration nº: %d\n real: %f imaginary: %f\n", i, z.real, z.i);
		i++;
	}
} */
