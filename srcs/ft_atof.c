/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suahn <suahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 14:34:17 by suahn             #+#    #+#             */
/*   Updated: 2021/11/11 14:36:33 by suahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

double	atof_operation(int j, double tmp, double num)
{
	while (j > 0)
	{
		tmp *= 0.1;
		j--;
	}
	num += tmp;
	return (num);
}

double	atof_operator(const char *str, int i, double num)
{
	int	dot;

	dot = 0;
	while (str[i])
	{
		if (dot == 0 && str[i] == '.')
			dot = i;
		else if (str[i] < '0' || str[i] > '9')
			error_detected_exit("Julia set : non digit\n");
		else if (str[i] >= '0' && str[i] <= '9')
		{
			if (dot)
				num = atof_operation(i - dot, str[i] - '0', num);
			else
				num = num * 10 + str[i] - '0';
		}
		i++;
	}
	return (num);
}

double	ft_atof(const char *str, int type)
{
	int		i;
	int		sign;
	double	num;

	i = 0;
	sign = 1;
	num = 0;
	if (!str[i])
		error_detected_exit("Julia set : non digit\n");
	if (str[i] == '-')
	{
		sign = -1;
		i++;
		if (!str[i] || (str[i] < '0' || str[i] > '9'))
			error_detected_exit("Julia set : non digit\n");
	}
	num = atof_operator(str, i, num);
	if ((type == 1 && num > R_END_J) || (type == 2 && num > I_END_J))
		error_detected_exit("Overflow digit(s). Try diffrent numbers(s)\n");
	return (sign * num);
}
