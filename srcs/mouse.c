/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suahn <suahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 14:35:39 by suahn             #+#    #+#             */
/*   Updated: 2021/11/11 14:35:42 by suahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	x = 0;
	y = 0;
	if (button == SCROLL_UP)
		vars->zoom *= 1.2;
	else if (button == SCROLL_DOWN)
		vars->zoom /= 1.2;
	if (vars->type == 1)
		mandelbrot_set(vars);
	else if (vars->type == 2)
		julia_set(vars);
	return (0);
}
