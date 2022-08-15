/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twakrim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 21:21:48 by twakrim           #+#    #+#             */
/*   Updated: 2019/12/18 21:21:50 by twakrim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	landmarking(int max, int x_point, t_fractol *f)
{
	double ret;

	ret = x_point * (f->re_max - f->re_min) / max + f->re_min;
	return (ret);
}

void	mlx_intilization(t_fractol *f, char *s, int a)
{
	f->fract = a;
	f->m_active = false;
	f->re_min = -2.0;
	f->re_max = 2.0;
	f->im_min = -2.0;
	f->im_max = 2.0;
	f->m_lre = -0.75;
	f->m_lim = -0.15;
	f->curcolor = A;
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIDTH + WIDTH_MENU_BAR,
		HEIGHT + HEIGHT_MENU, s);
	f->img.img_ptr = mlx_new_image(f->mlx, WIDTH, HEIGHT);
}

void	draw(t_fractol *f, t_color c)
{
	if (f->fract == 1)
		mandelbrot(f, c);
	if (f->fract == 2)
		julia(f, c);
	if (f->fract == 3)
		tricorn(f, c);
	if (f->fract == 4)
		ship(f, c);
	mlx_put_image_to_window(f->mlx, f->win, f->img.img_ptr, 0, 0);
}

void	menu(t_fractol *f)
{
	mlx_string_put(f->mlx, f->win, 1050, 25, 16777215, "CHANGE FRACTALS :");
	mlx_string_put(f->mlx, f->win, 1075, 55, 16777215, "Mandelbrot :'M'");
	mlx_string_put(f->mlx, f->win, 1075, 80, 16777215, "Julia :     'J'");
	mlx_string_put(f->mlx, f->win, 1075, 105, 16777215, "Tricorn :   'T'");
	mlx_string_put(f->mlx, f->win, 1075, 130, 16777215, "Burnship :  'S'");
	mlx_string_put(f->mlx, f->win, 1050, 225, 16777215, "CHANGE COLOR :");
	mlx_string_put(f->mlx, f->win, 1050, 255, 16777215, "Number pad(1 - 9)");
	mlx_string_put(f->mlx, f->win, 1050, 285, 16777215, "/ '+' & '-'");
	mlx_string_put(f->mlx, f->win, 1050, 340, 16777215, "RESET : 'R'");
	mlx_string_put(f->mlx, f->win, 1050, 435, 16777215, "ZOOM : 'scroll'");
	mlx_string_put(f->mlx, f->win, 1050, 530, 16777215, "PAUSE THE MOUSE :");
	mlx_string_put(f->mlx, f->win, 1075, 560, 16777215, "'space key'");
	mlx_string_put(f->mlx, f->win, 1050, 950, 16777215, "EXIT : 'ESC'");
	mlx_string_put(f->mlx, f->win, 50, 1015, 16777215,
		"FRACTALS EXP : mandelbrot, julia, tri, ship");
}

void	mouse_active(t_fractol *f)
{
	if (f->m_active == true)
	{
		f->m_lre = f->m_re;
		f->m_lim = f->m_im;
		f->m_active = false;
	}
	else if (f->m_active == false)
	{
		f->m_active = true;
	}
}
