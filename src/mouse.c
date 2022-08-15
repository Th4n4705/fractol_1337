/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twakrim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 21:27:55 by twakrim           #+#    #+#             */
/*   Updated: 2019/12/18 21:27:57 by twakrim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	calc_mouse(int x, int y, t_fractol *f)
{
	f->m_re = landmarking(WIDTH, x, f);
	f->m_im = landmarking(HEIGHT, y, f);
}

void	zoomin(t_fractol *f, double m_re, double m_im)
{
	double	homothetie;

	homothetie = 1.0 * 1.1;
	f->re_min = m_re + (f->re_min - m_re) * homothetie;
	f->im_min = m_im + (f->im_min - m_im) * homothetie;
	f->re_max = m_re + (f->re_max - m_re) * homothetie;
	f->im_max = m_im + (f->im_max - m_im) * homothetie;
}

void	zoomout(t_fractol *f, double m_re, double m_im)
{
	double	homothetie;

	homothetie = 1.0 / 1.1;
	f->re_min = m_re + (f->re_min - m_re) * homothetie;
	f->im_min = m_im + (f->im_min - m_im) * homothetie;
	f->re_max = m_re + (f->re_max - m_re) * homothetie;
	f->im_max = m_im + (f->im_max - m_im) * homothetie;
}

int		mouse_move(int x, int y, t_fractol *f)
{
	if ((x >= 0 && x <= 1000) && (y >= 0 && y <= 1000))
	{
		calc_mouse(x, y, f);
		if (f->fract == 2 && f->m_active == true)
		{
			julia(f, f->curcolor);
			mlx_put_image_to_window(f->mlx, f->win, f->img.img_ptr, 0, 0);
		}
	}
	return (0);
}

int		mouse_press(int key, int x, int y, t_fractol *f)
{
	if (key == 4)
	{
		calc_mouse(x, y, f);
		zoomin(f, f->m_re, f->m_im);
		draw(f, f->curcolor);
		mlx_put_image_to_window(f->mlx, f->win, f->img.img_ptr, 0, 0);
	}
	else if (key == 5)
	{
		calc_mouse(x, y, f);
		zoomout(f, f->m_re, f->m_im);
		draw(f, f->curcolor);
		mlx_put_image_to_window(f->mlx, f->win, f->img.img_ptr, 0, 0);
	}
	return (0);
}
