/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suahn <suahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:25:55 by suahn             #+#    #+#             */
/*   Updated: 2021/11/15 14:25:57 by suahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/fract_ol_bonus.h"

double	julia(t_complex z, t_vars *vars)
{
	double	rr;
	double	ii;
	double	two_ri;
	double	n;

	n = 0;
	while (ft_abs_complex(z) <= 2 && n < MAX_ITER)
	{
		rr = z.r * z.r;
		ii = z.i * z.i;
		two_ri = 2.0 * z.r * z.i;
		z.r = rr - ii + vars->cr;
		z.i = two_ri + vars->ci;
		n++;
	}
	return (n);
}

void	julia_set(t_vars *v)
{
	t_img		img;
	t_complex	z;

	img = init_img(v);
	while (img.x < W_WIDTH)
	{
		img.y = 0;
		while (img.y < W_HEIGHT)
		{
			z.r = (img.x / (double)W_WIDTH) * (R_END_J - R_START_J)
				* v->zoom + v->r_start;
			z.i = (img.y / (double)W_HEIGHT) * (I_END_J - I_START_J)
				* v->zoom + v->i_start;
			img.n = julia(z, v);
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

void	julia_main(t_complex c)
{
	t_vars	vars;

	vars = init_julia(c);
	julia_set(&vars);
	mlx_hook(vars.win, 4, (1L << 2), mouse_hook, &vars);
	mlx_loop(vars.mlx);
}
