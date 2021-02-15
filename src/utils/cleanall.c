/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:44:35 by rcaraway          #+#    #+#             */
/*   Updated: 2021/02/14 18:32:32 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ultimate.h"

void	cleanall(void)
{
	t_obj	*o;
	t_obj	*next;

	o = g_data.objects;
	next = g_data.objects->next;
	while (o->next)
	{
		free(o);
		o = next;
		next = next->next;
	}
	free(o);
	cleanall2();
}

void	cleanall2(void)
{
	t_cam	*cam;
	t_cam	*next;

	cam = g_data.cams;
	next = g_data.cams->next;
	while (cam->next)
	{
		free(cam);
		cam = next;
		next = next->next;
	}
	free(cam);
	cleanall3();
}

void	cleanall3(void)
{
	t_light	*l;
	t_light	*next;

	l = g_data.lights;
	next = g_data.lights->next;
	while (l->next)
	{
		free(l);
		l = next;
		next = next->next;
	}
	free(l);
	if (g_data.mlx.mlx)
		free(g_data.mlx.mlx);
	if (g_data.mlx.win)
		free(g_data.mlx.win);
}

int		checkcolor(t_color c)
{
	if (c.b > 255 || c.b < 0 || c.r > 255 || c.r < 0 ||
	c.g > 255 || c.g < 0)
		return (-1);
	return (0);
}
