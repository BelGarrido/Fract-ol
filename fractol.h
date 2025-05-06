# ifndef FRACTOL_H
# define FRACTOL_H

#include <stdlib.h>
#include <stdio.h> // malloc free
#include <unistd.h> // write
#include <math.h>
#include "MLX42.h"

#define WIDTH 256
#define HEIGHT 256


/*FRACTAL
	MLX stuff
	Image
	Hooks values
*/

typedef struct s_fractal
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	int			width;
    int			height;
} 			t_fractal;

typedef struct	s_complex 
{	
	//	eje x
	double real;
	//	eje y
	double i;
}				t_complex;

int	ft_strncmp(char *s1, char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);

#endif