/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suahn <suahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 14:33:49 by suahn             #+#    #+#             */
/*   Updated: 2021/11/11 14:33:59 by suahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include <math.h>
# include "../mlx/mlx.h"
# include <unistd.h>
# include <stdlib.h>

# define MAX_ITER 110
# define W_WIDTH 900
# define W_HEIGHT 600
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define R_START_M -2
# define R_END_M 2
# define I_START_M -1
# define I_END_M 1
# define R_START_J -2
# define R_END_J 2
# define I_START_J -1
# define I_END_J 1

typedef struct s_complex
{
	double	r;
	double	i;
}				t_complex;

typedef struct s_vars
{
	int		type;
	void	*mlx;
	void	*win;
	double	r_start;
	double	r_end;
	double	i_start;
	double	i_end;
	double	zoom;
	double	cr;
	double	ci;
}				t_vars;

typedef struct s_img
{
	void	*ptr;
	int		*data;
	int		bpp;
	int		size_line;
	int		endian;
	double	bright;
	double	n;
	double	x;
	double	y;
}				t_img;

t_img		init_img(t_vars *vars);
t_vars		init_julia(t_complex c);
t_vars		init_mandelbrot(void);

void		julia_main(t_complex c);
void		julia_set(t_vars *vars);
double		julia(t_complex z, t_vars *vars);

void		error_detected_exit(char *msg);

int			mandelbrot_main(void);
void		mandelbrot_set(t_vars *vars);
double		ft_mandelbrot(t_complex c);

t_complex	ft_multiple_complex(t_complex a, t_complex b);
double		ft_abs_complex(t_complex c);
int			ft_strcmp(char *s1, char *s2);
int			ft_strlen(const char *str);

double		atof_operation(int j, double tmp, double num);
double		atof_operator(const char *str, int i, double num);
double		ft_atof(const char *str, int type);

int			mouse_hook(int button, int x, int y, t_vars *vars);
void		render(t_vars *vars);

#endif
