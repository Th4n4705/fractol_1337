/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twakrim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 21:27:45 by twakrim           #+#    #+#             */
/*   Updated: 2019/12/18 21:27:46 by twakrim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	calc(t_fractol *f)
{
	f->c_re = landmarking(WIDTH, f->col, f);
	f->c_im = landmarking(HEIGHT, f->row, f);
	f->z_re = 0;
	f->z_im = 0;
}

void	deal_key4(int key, t_fractol *f)
{
	if (key == 38 && f->fract != 2)
	{
		f->fract = 2;
		draw(f, f->curcolor);
	}
	else if (key == 17 && f->fract != 3)
	{
		f->fract = 3;
		draw(f, f->curcolor);
	}
	else if (key == 1 && f->fract != 4)
	{
		f->fract = 4;
		draw(f, f->curcolor);
	}
	else if (key == 78)
		zoomin_fc(f);
	else if (key == 69)
		zoomout_fc(f);
	else if (key == 15)
		reset(f);
	else if (key == 49 && f->fract == 2)
		mouse_active(f);
}

void	deal_key3(int key, t_fractol *f)
{
	if (key == 89)
	{
		f->curcolor = G;
		draw(f, G);
	}
	else if (key == 91)
	{
		f->curcolor = H;
		draw(f, H);
	}
	else if (key == 92)
	{
		f->curcolor = I;
		draw(f, I);
	}
	else if (key == 46 && f->fract != 1)
	{
		f->fract = 1;
		draw(f, f->curcolor);
	}
	else
		deal_key4(key, f);
}

void	deal_key2(int key, t_fractol *f)
{
	if (key == 85)
	{
		f->curcolor = C;
		draw(f, C);
	}
	else if (key == 86)
	{
		f->curcolor = D;
		draw(f, D);
	}
	else if (key == 87)
	{
		f->curcolor = E;
		draw(f, E);
	}
	else if (key == 88)
	{
		f->curcolor = F;
		draw(f, F);
	}
	else
		deal_key3(key, f);
}

int		deal_key(int key, void *v)
{
	t_fractol *f;

	f = (t_fractol *)v;
	if (key == 53)
	{
		freeall(f);
		exit(1);
	}
	else if (key == 83)
	{
		f->curcolor = A;
		draw(f, A);
	}
	else if (key == 84)
	{
		f->curcolor = B;
		draw(f, B);
	}
	else
		deal_key2(key, f);
	return (0);
}
