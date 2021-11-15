/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suahn <suahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:24:30 by suahn             #+#    #+#             */
/*   Updated: 2021/11/15 14:24:32 by suahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/fract_ol_bonus.h"

void	error_detected_exit(char *msg)
{
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
	exit(0);
}

int	main(int argc, char **argv)
{
	t_complex	c;

	if (argc < 2)
		error_detected_exit("Type a fractal set : 'mandelbrot' / 'julia'.\n");
	else if (ft_strcmp(argv[1], "mandelbrot") && ft_strcmp(argv[1], "julia"))
		error_detected_exit("Type a fractal set : 'mandelbrot' / 'julia'.\n");
	else if (!ft_strcmp(argv[1], "julia"))
	{
		if (argc != 4)
			error_detected_exit("Needs a complex number. [ex] Julia 0 0\n");
	}
	else if (!ft_strcmp(argv[1], "mandelbrot"))
	{
		if (argc != 2)
			error_detected_exit("Too many arguments. Type only 'mandelbrot'.\n");
	}
	if (argc == 4 && !ft_strcmp(argv[1], "julia"))
	{
		c.r = ft_atof(argv[2], 1);
		c.i = ft_atof(argv[3], 2);
		julia_main(c);
	}
	else if (argc == 2 && !ft_strcmp(argv[1], "mandelbrot"))
		mandelbrot_main();
	return (0);
}
