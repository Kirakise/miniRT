/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:35:01 by rcaraway          #+#    #+#             */
/*   Updated: 2021/03/15 15:30:35 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ultimate.h"

t_vector	mulvec(int i, t_vector v)
{
	v.x *= i;
	v.y *= i;
	v.z *= i;
	normvector(&v);
	return (v);
}

int			getangle2(t_vector *v1, t_vector *v2)
{
	double a1;
	double a2;

	a1 = v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
	a2 = sqrt(v1->x * v1->x + v1->y * v1->y + v1->z * v1->z)
		* sqrt(v2->x * v2->x + v2->y * v2->y + v2->z * v2->z);
	return (a1 / a2 > 0 ? 1 : -1);
}

int			checkobjects(t_line *l)
{
	t_obj		*o;
	t_result	res;
	t_point		p;
	t_cres		c;

	initcres(&c, g_data.alcolor, g_data.alratio);
	makecolor(&res.color, 0, 0, 0);
	res.res = INFINITY;
	o = g_data.objects->next;
	while (o)
	{
		checkobjects2(l, o, &res);
		o = o->next;
	}
	if (!isnan(res.res) && (res.color.b > 0
				|| res.color.g > 0 || res.color.r > 0))
	{
		p = getpointonline(l, res.res);
		addlight(&res.color, res.v, &p, getvectorofline(l));
	}
	else
		addlightcolor(&res.color, c);
	return (color_to_int(&res.color));
}

void		checkobjects2(t_line *l, t_obj *o, t_result *res)
{
	double	tmp;
	t_line	l1;
	t_point	p;

	if (o->type == 1 && !isnan(tmp = checksphere(l, o->obj))
	&& tmp > 60 / g_data.camcur->fow && myequal(tmp, res->res)
	== -1 && (res->res = tmp))
	{
		p = getpointonline(l, res->res);
		l1 = makelinep(&((t_sphere *)o->obj)->center, &p);
		res->v = getvectorofline(&l1);
		res->color = ((t_sphere *)o->obj)->color;
	}
	else if (o->type == 2 && !isnan(tmp = checkplane(l, o->obj))
	&& tmp > 60 / g_data.camcur->fow && myequal(tmp, res->res)
	== -1 && (res->res = tmp))
	{
		res->v = getnormplane(((t_plane *)o->obj)->v, l);
		res->color = ((t_plane *)o->obj)->color;
	}
	else
		checkobjects3(l, o, res);
}

void		checkobjects3(t_line *l, t_obj *o, t_result *res)
{
	double	tmp;

	if (o->type == 4 && !isnan(tmp = checkcylinder(l, o->obj))
	&& tmp > 60 / g_data.camcur->fow && myequal(tmp, res->res)
	== -1 && (res->res = tmp))
	{
		res->v = getcynorm(*(t_cylinder *)o->obj, getpointonline(l, res->res));
		res->color = ((t_cylinder *)o->obj)->color;
	}
	else if (o->type == 5 && !isnan(tmp = checktriangle(l, o->obj))
	&& tmp > 60 / g_data.camcur->fow && myequal(tmp, res->res)
	== -1 && (res->res = tmp))
	{
		res->v = getnormplane(((t_triangle *)o->obj)->v, l);
		res->color = ((t_triangle *)o->obj)->color;
	}
	else if (o->type == 3 && !isnan(tmp = checksquare(l, o->obj))
			&& tmp > 60 / g_data.camcur->fow && myequal(tmp, res->res)
			== -1 && (res->res = tmp))
	{
		res->v = getnormplane(((t_square *)o->obj)->v, l);
		res->color = ((t_square *)o->obj)->color;
	}
}
