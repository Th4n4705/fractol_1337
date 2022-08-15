/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twakrim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 21:21:39 by twakrim           #+#    #+#             */
/*   Updated: 2019/12/18 21:23:32 by twakrim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	mandelbrot(t_fractol *f, t_color c)
{
	f->row = 0;
	f->itr_max = 50;
	f->img.data = (int *)mlx_get_data_addr(f->img.img_ptr, &f->img.bpp,
			&f->img.size_l, &f->img.endian);
	while (f->row < HEIGHT)
	{
		f->col = 0;
		while (f->col < WIDTH)
		{
			calc(f);
			f->iteration = 0;
			while (mod(f) <= 4 && f->iteration < f->itr_max)
			{
				f->z_new = f->z_re * f->z_re - f->z_im * f->z_im + f->c_re;
				f->z_im = 2 * f->z_im * f->z_re + f->c_im;
				f->z_re = f->z_new;
				f->iteration++;
			}
			coloring(f, c);
			f->col++;
		}
		f->row++;
	}
}

void	autojulia(t_fractol *f)
{
	if (f->m_active == true)
	{
		f->c_re = f->m_re;
		f->c_im = f->m_im;
	}
	else if (f->m_active == false)
	{
		f->c_re = f->m_lre;
		f->c_im = f->m_lim;
	}
}

void	julia(t_fractol *f, t_color c)
{
	f->row = 0;
	f->itr_max = 50;
	f->img.data = (int *)mlx_get_data_addr(f->img.img_ptr, &f->img.bpp,
			&f->img.size_l, &f->img.endian);
	while (f->row < HEIGHT)
	{
		f->col = 0;
		while (f->col < WIDTH)
		{
			autojulia(f);
			f->z_re = landmarking(WIDTH, f->col, f);
			f->z_im = landmarking(HEIGHT, f->row, f);
			f->iteration = 0;
			while (mod(f) <= 4 && f->iteration < f->itr_max)
			{
				f->z_new = f->z_re * f->z_re - f->z_im * f->z_im + f->c_re;
				f->z_im = 2 * f->z_im * f->z_re + f->c_im;
				f->z_re = f->z_new;
				f->iteration++;
			}
			coloring(f, c);
			f->col++;
		}
		f->row++;
	}
}

void	tricorn(t_fractol *f, t_color c)
{
	f->row = 0;
	f->itr_max = 50;
	f->img.data = (int *)mlx_get_data_addr(f->img.img_ptr, &f->img.bpp,
			&f->img.size_l, &f->img.endian);
	while (f->row < HEIGHT)
	{
		f->col = 0;
		while (f->col < WIDTH)
		{
			calc(f);
			f->iteration = 0;
			while (mod(f) <= 4 && f->iteration < f->itr_max)
			{
				f->z_new = f->z_re * f->z_re - f->z_im * f->z_im + f->c_re;
				f->z_im = -2 * f->z_im * f->z_re + f->c_im;
				f->z_re = f->z_new;
				f->iteration++;
			}
			coloring(f, c);
			f->col++;
		}
		f->row++;
	}
}

void	ship(t_fractol *f, t_color c)
{
	f->row = 0;
	f->itr_max = 50;
	f->img.data = (int *)mlx_get_data_addr(f->img.img_ptr, &f->img.bpp,
			&f->img.size_l, &f->img.endian);
	while (f->row < HEIGHT)
	{
		f->col = 0;
		while (f->col < WIDTH)
		{
			calc(f);
			f->iteration = 0;
			while (mod(f) <= 4 && f->iteration < f->itr_max)
			{
				f->z_new = f->z_re * f->z_re - f->z_im * f->z_im + f->c_re;
				f->z_im = fabs(2 * f->z_im * f->z_re + f->c_im);
				f->z_re = fabs(f->z_new);
				f->iteration++;
			}
			coloring(f, c);
			f->col++;
		}
		f->row++;
	}
}
