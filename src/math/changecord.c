/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ChangeCord.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:01:51 by rcaraway          #+#    #+#             */
/*   Updated: 2021/02/09 18:03:37 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ultimate.h"

void	changecordsphere(t_sphere *s, double x, double y, double z)
{
	s->center.x -= x;
	s->center.y -= y;
	s->center.z -= z;
}

void	changecordobj(double x, double y, double z)
{
	t_obj *o;

	o = g_data.objects->next;
	while (o)
	{
		if (o->type == 1)
			changecordsphere(o->obj, x, y, z);
		else if (o->type == 2)
			changecordplane(o->obj, x, y, z);
		else if (o->type == 3)
			changecordsquare(o->obj, x, y, z);
		else if (o->type == 4)
			changecordcylinder(o->obj, x, y, z);
		else if (o->type == 5)
			changecordtriangle(o->obj, x, y, z);
		o = o->next;
	}
}

void	changecordlight(double x, double y, double z)
{
	t_light *l;

	l = g_data.lights->next;
	while (l)
	{
		l->p.x -= x;
		l->p.y -= y;
		l->p.z -= z;
		l = l->next;
	}
}

void	changecords(t_cam *c)
{
	double	x;
	double	y;
	double	z;
	t_cam	*tmp;

	tmp = g_data.cams->next;
	x = c->p.x;
	y = c->p.y;
	z = c->p.z;
	changecordobj(c->p.x, c->p.y, c->p.z);
	changecordlight(c->p.x, c->p.y, c->p.z);
	while (tmp)
	{
		tmp->p.x -= x;
		tmp->p.y -= y;
		tmp->p.z -= z;
		tmp = tmp->next;
	}
	rotatecord(c);
}

void	changecordplane(t_plane *p, double x, double y, double z)
{
	p->p.x -= x;
	p->p.y -= y;
	p->p.z -= z;
}
