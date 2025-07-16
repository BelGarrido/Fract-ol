/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagarri@student.42malaga.com <anagarri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:18:54 by anagarri@st       #+#    #+#             */
/*   Updated: 2025/07/16 11:20:57 by anagarri@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*******Color fractal based in interactions*******/

unsigned int	color_a(double t, double i, double iterations)
{
	unsigned int rgba;

	rgba = 0;
	if(i == iterations)
		return (0x000000FF);
	t = pow(t, 0.3);
	rgba |= ((unsigned int)(sin(t * 6.28318) * 127 + 128) << 24);        // R
	rgba |= ((unsigned int)(sin(t * 6.28318 + 2.094) * 127 + 128) << 16); // G
	rgba |= ((unsigned int)(sin(t * 6.28318 + 4.188) * 127 + 128) << 8);
	rgba |=  255;
	return (rgba);
}


unsigned int	color_b(double t, double i, double iterations)
{
	unsigned int rgba;

	if (i == iterations)
		return 0x000000FF;

	t = pow(t, 0.3);
	t = t * t; // puedes cambiar a t = t * t * t para más contraste
	rgba = 0;
	rgba |= ((unsigned int)(sin(t * 6.28318) * 127 + 128) << 24); // R
	rgba |= ((unsigned int)(sin(t * 6.28318 + 2.094) * 127 + 128) << 16); // G
	rgba |= ((unsigned int)(sin(t * 6.28318 + 4.188) * 127 + 128) << 8); // B
	rgba |= 255;

	return rgba;
}

unsigned int	color_c(double t, double i, double iterations)
{
	unsigned int rgba;

	if (i == iterations)
		return 0x000000FF;
	rgba = 0;
	rgba |= ((unsigned int)(9 * (1 - t) * t * t * t * 255) << 24); // R
	rgba |= ((unsigned int)(15 * (1 - t) * (1 - t) * t * t * 255) << 16); // G
	rgba |= ((unsigned int)(8.5 * (1 - t) * (1 - t) * t * 255) << 8); // B
	rgba |= 255;
	return rgba;
}

unsigned int	color_d(double t, double i, double iterations)
{
	t = t * 1;
	if (i == iterations)
		return 0x000000FF;
	if(i <= iterations && i >= iterations/4)
		return (0x3FD9D9FF);
	else if(i <= iterations/4 && i >= iterations/8)
		return (0x3446D1FF);
	else if(i <= iterations/8 && i >= iterations/12)
		return (0x982CDCFF);
	else if(i <= iterations/12 && i >= iterations/14)
		return (0xDC2CBCFF);
	else if(i <= iterations/14 && i >= iterations/16)
		return (0x000064FF);
	else if(i <= iterations/16 && i >= iterations/20)
		return (0x000032FF);
	else
		return (0x000000FF);
}