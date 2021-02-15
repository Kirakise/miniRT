/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:27:34 by rcaraway          #+#    #+#             */
/*   Updated: 2021/02/14 17:57:46 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ultimate.h"
#include <mlx.h>

int		color_to_int(t_color *c)
{
	return ((c->r << 16) + (c->g << 8) + c->b);
}

void	mlx_put_color(int c, int x, int y)
{
	mlx_pixel_put(g_data.mlx.mlx, g_data.mlx.win, x, y, c);
}

t_image	makeimage(void)
{
	t_image	img;

	img.img = mlx_new_image(g_data.mlx.mlx, g_data.swidth, g_data.sheight);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	return (img);
}

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	if (y >= g_data.sheight - 1)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	get_image(t_cam *c)
{
	int		h;
	int		w;
	t_line	l;
	t_point	p;
	t_image img;

	g_data.tmp = g_data.swidth > g_data.sheight
		? g_data.swidth : g_data.sheight;
	img = makeimage();
	changecords(c);
	h = 0;
	while (h++ < g_data.sheight && !(w = 0))
	{
		while (w++ < g_data.swidth)
		{
			p.x = (w - g_data.swidth / 2.0) / g_data.tmp;
			p.y = (g_data.sheight / 2.0 - h) / g_data.tmp;
			p.z = c->v.z * (180 / c->fow);
			l = makelinep(&(c->p), &p);
			my_mlx_pixel_put(&img, w, h, checkobjects(&l));
		}
	}
	mlx_put_image_to_window(g_data.mlx.mlx, g_data.mlx.win, img.img, 0, 0);
	if (g_data.save)
		create_bmp_image(img, "file.bmp");
}
