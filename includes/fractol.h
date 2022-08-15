/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twakrim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 17:28:10 by twakrim           #+#    #+#             */
/*   Updated: 2019/11/28 17:28:11 by twakrim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include "../libft/libft.h"
# define WIDTH 1000
# define HEIGHT 1000
# define WIDTH_MENU_BAR 250
# define HEIGHT_MENU 50

typedef enum		e_color
{
	A = 131072,
	B = 512,
	C = 2,
	D = 131584,
	E = 131074,
	F = 514,
	G = 66816,
	H = 328708,
	I = 66820
}					t_color;

typedef enum		e_boolean
{
	true = 1,
	false = 0
}					t_bool;

typedef struct		s_img
{
	void			*img_ptr;
	int				*data;
	int				size_l;
	int				bpp;
	int				endian;
}					t_img;

typedef struct		s_fractol
{
	void			*mlx;
	void			*win;
	int				itr_max;
	int				row;
	int				col;
	int				curcolor;
	int				iteration;
	int				fract;
	int				juliaforward;
	double			m_re;
	double			m_im;
	double			m_lre;
	double			m_lim;
	double			c_re;
	double			c_im;
	double			z_re;
	double			z_im;
	double			z_new;
	double			re_max;
	double			im_max;
	double			re_min;
	double			im_min;
	t_bool			m_active;
	t_img			img;
}					t_fractol;

double				landmarking(int max, int x_point, t_fractol *f);

void				mlx_intilization(t_fractol *f, char *s, int a);

void				draw(t_fractol *f, t_color c);

void				menu(t_fractol *f);

int					mouse_press(int key, int x, int y, t_fractol *f);

int					mouse_move(int x, int y, t_fractol *f);

void				zoomout(t_fractol *f, double m_re, double m_im);

void				zoomin(t_fractol *f, double m_re, double m_im);

double				homothetie_fc(double start, double end, double homothétie);

int					deal_key(int key, void *v);

void				mandelbrot(t_fractol *f, t_color c);

void				julia(t_fractol *f, t_color c);

void				tricorn(t_fractol *f, t_color c);

void				ship(t_fractol *f, t_color c);

void				coloring(t_fractol *f, t_color c);

double				mod(t_fractol *f);

void				ft_error();

char				*ft_strtolower(char *s);

void				calc(t_fractol *f);

void				calc_mouse(int x, int y, t_fractol *f);

void				mouse_active(t_fractol *f);

void				makingfract(t_fractol *f);

void				reset(t_fractol *f);

void				zoomout_fc(t_fractol *f);

void				zoomin_fc(t_fractol *f);

void				freeall(t_fractol *f);
#endif
