/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suahn <suahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:25:42 by suahn             #+#    #+#             */
/*   Updated: 2021/11/15 14:25:43 by suahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/fract_ol_bonus.h"

double	ft_mandelbrot(t_complex c)
{
	t_complex	z;
	int			n;

	z.r = c.r;
	z.i = c.i;
	n = 1;
	while (ft_abs_complex(z) <= 2 && n < MAX_ITER)
	{
		z = ft_multiple_complex(z, z);
		z.r += c.r;
		z.i += c.i;
		n++;
	}
	return (n);
}

void	mandelbrot_set(t_vars *v)
{
	t_img		img;
	t_complex	c;

	img = init_img(v);
	while (img.x < W_WIDTH)
	{
		img.y = 0;
		while (img.y < W_HEIGHT)
		{
			c.r = (img.x / (double)W_WIDTH) * (R_END_M - R_START_M)
				* v->zoom + v->r_start;
			c.i = (img.y / (double)W_HEIGHT) * (I_END_M - I_START_M)
				* v->zoom + v->i_start;
			img.n = ft_mandelbrot(c);
			img.bright = img.n / (double)MAX_ITER * 10;
			img.bright = sqrt(img.bright) * 255;
			if (img.n == MAX_ITER)
				img.bright = 0;
			img.data[(W_WIDTH * (int)img.y) + (int)img.x]
				= img.bright * 256 * 256 + img.bright * 256 + img.bright;
			img.y++;
		}
		img.x++;
	}
	mlx_put_image_to_window(v->mlx, v->win, img.ptr, 0, 0);
}

int	mandelbrot_main(void)
{
	t_vars	vars;

	vars = init_mandelbrot();
	mandelbrot_set(&vars);
	mlx_hook(vars.win, 4, (1L << 2), mouse_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
