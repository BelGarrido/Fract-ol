/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagarri@student.42malaga.com <anagarri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:40:15 by anagarri          #+#    #+#             */
/*   Updated: 2025/07/16 12:02:22 by anagarri@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//t = pow(t, 0.3);

unsigned int	get_color_iterations_julia(double i, double iterations)
{
	double			t;
	unsigned int	rgba;

	t = i / iterations;
	rgba = color_c(t, i, iterations);
	return (rgba);
}

unsigned int	get_color_iterations_mandelbrot(double i, double iterations)
{
	double			t;
	unsigned int	rgba;

	t = i / iterations;
	rgba = color_a(t, i, iterations);
	return (rgba);
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

	if (!s || fd < 0)
		return ;
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
	int		i;
	double	neg;
	double	number;
	double	decimal;

	decimal = 0.1;
	i = 0;
	neg = 1;
	number = 0;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
		i++;
	if (s[i] == '+')
		i++;
	else if (s[i++] == '-')
		neg = -1;
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
