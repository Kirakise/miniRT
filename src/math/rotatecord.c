/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotatecord.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:23:23 by rcaraway          #+#    #+#             */
/*   Updated: 2021/02/09 18:23:28 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ultimate.h"

void	rotatecord(t_cam *c)
{
	double	angle1;
	double	angle2;
	int		tmp;

	tmp = 1;
	if (c->v.z < 0)
		tmp = -1;
	angle1 = c->v.y != 0 ? tmp * atan(c->v.y / c->v.z) : 0;
	angle2 = c->v.x != 0 ? tmp * asin((c->v.x) / vectormodule(&(c->v))) : 0;
	rotateall(angle1, angle2);
}

void	rotatelights(double angle1, double angle2)
{
	t_light *l;

	l = g_data.lights->next;
	while (l)
	{
		rotatexp(&(l->p), angle1);
		rotateyp(&(l->p), angle2);
		l = l->next;
	}
}

void	rotateobjects(double angle1, double angle2)
{
	t_obj *o;

	o = g_data.objects->next;
	while (o)
	{
		if (o->type == 1)
			rotatesphere(angle1, angle2, o->obj);
		else if (o->type == 2)
			rotateplane(o->obj, angle1, angle2);
		else if (o->type == 3)
			rotatesquare(o->obj, angle1, angle2);
		else if (o->type == 4)
			rotatecylinder(o->obj, angle1, angle2);
		else if (o->type == 5)
			rotatetriangle(o->obj, angle1, angle2);
		o = o->next;
	}
}

void	rotatecam(double angle1, double angle2, t_cam *c)
{
	rotatexp(&(c->p), angle1);
	rotateyp(&(c->p), angle2);
	rotatexv(&(c->v), angle1);
	rotateyv(&(c->v), angle2);
}

void	rotatesphere(double angle1, double angle2, t_sphere *s)
{
	rotatexp(&(s->center), angle1);
	rotateyp(&(s->center), angle2);
}
