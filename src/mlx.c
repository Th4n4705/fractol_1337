/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twakrim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 22:43:58 by twakrim           #+#    #+#             */
/*   Updated: 2019/12/18 22:44:09 by twakrim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	makingfract(t_fractol *f)
{
	draw(f, f->curcolor);
	mlx_put_image_to_window(f->mlx, f->win, f->img.img_ptr, 0, 0);
	menu(f);
	mlx_hook(f->win, 2, 0, deal_key, f);
	mlx_hook(f->win, 4, 0, mouse_press, f);
	mlx_hook(f->win, 6, 0, mouse_move, f);
	mlx_loop(f->mlx);
}

void	reset(t_fractol *f)
{
	f->m_active = false;
	f->re_min = -2.0;
	f->re_max = 2.0;
	f->im_min = -2.0;
	f->im_max = 2.0;
	f->m_lre = -0.75;
	f->m_lim = -0.15;
	draw(f, f->curcolor);
}

void	zoomout_fc(t_fractol *f)
{
	calc_mouse(f->m_re, f->m_im, f);
	zoomout(f, f->m_re, f->m_im);
	draw(f, f->curcolor);
	mlx_put_image_to_window(f->mlx, f->win, f->img.img_ptr, 0, 0);
}

void	zoomin_fc(t_fractol *f)
{
	calc_mouse(f->m_re, f->m_im, f);
	zoomin(f, f->m_re, f->m_im);
	draw(f, f->curcolor);
	mlx_put_image_to_window(f->mlx, f->win, f->img.img_ptr, 0, 0);
}

void	freeall(t_fractol *f)
{
	mlx_destroy_image(f->mlx, f->img.img_ptr);
	mlx_destroy_window(f->mlx, f->win);
	free(f);
}
