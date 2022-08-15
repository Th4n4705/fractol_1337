/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twakrim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:04:33 by twakrim           #+#    #+#             */
/*   Updated: 2019/12/17 18:52:16 by twakrim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

char	*ft_strtolower(char *s)
{
	int		i;
	char	*c;

	i = ft_strlen(s);
	c = (char*)malloc(sizeof(i));
	i = 0;
	while (s[i] != '\0')
	{
		c[i] = ft_tolower(s[i]);
		i++;
	}
	return (c);
}

void	ft_error(t_fractol *f)
{
	ft_putstr("Usage : ./fractol <set name>  \n");
	ft_putstr("            ,,    mandelbrot  \n");
	ft_putstr("            ,,    julia       \n");
	ft_putstr("            ,,    tric        \n");
	ft_putstr("            ,,    ship        \n");
	ft_putstr("            ,,                \n");
	free(f);
	exit(1);
}

double	mod(t_fractol *f)
{
	return (f->z_re * f->z_re + f->z_im * f->z_im);
}

void	coloring(t_fractol *f, t_color c)
{
	if (f->iteration < f->itr_max)
		f->img.data[f->row * WIDTH + f->col] = (c * f->iteration * 2);
	else
		f->img.data[f->row * WIDTH + f->col] = 0;
}

int		main(int ac, char **av)
{
	t_fractol *f;

	f = (t_fractol *)ft_memalloc(sizeof(t_fractol));
	if (ac != 2)
		ft_error(f);
	else if (ft_strcmp(ft_strtolower(av[1]), "mandelbrot") == 0)
		mlx_intilization(f, "mandelbrot Set", 1);
	else if (ft_strcmp(ft_strtolower(av[1]), "julia") == 0)
		mlx_intilization(f, "julia Set", 2);
	else if (ft_strcmp(ft_strtolower(av[1]), "tric") == 0)
		mlx_intilization(f, "tricorn Set", 3);
	else if (ft_strcmp(ft_strtolower(av[1]), "ship") == 0)
		mlx_intilization(f, "burnship Set", 4);
	else
		ft_error(f);
	makingfract(f);
	return (0);
}
