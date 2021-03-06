/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suahn <suahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 14:35:01 by suahn             #+#    #+#             */
/*   Updated: 2021/11/11 14:35:04 by suahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

t_complex	ft_multiple_complex(t_complex a, t_complex b)
{
	t_complex	ret;

	ret.r = a.r * b.r + a.i * b.i * -1.0;
	ret.i = a.r * b.i + a.i * b.r;
	return (ret);
}

double	ft_abs_complex(t_complex c)
{
	double	value;

	value = sqrt(c.r * c.r + c.i * c.i);
	return (value);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] == s2[i])
			i++;
		if (s1[i] < s2[i] || s1[i] > s2[i])
			return (s1[i] - s2[i]);
	}
	if (s1[i] != '\0' || s1[i] != '\0')
		return (1);
	return (0);
}

int	ft_strlen(const char *str)
{
	int	size;

	size = 0;
	while (str[size])
	{
		size++;
	}
	return (size);
}
