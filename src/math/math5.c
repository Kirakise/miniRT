/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:17:32 by rcaraway          #+#    #+#             */
/*   Updated: 2021/02/09 18:19:02 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ultimate.h"

double		checkcylinder(t_line *l, t_cylinder *c)
{
	double		angle1;
	double		angle2;
	int			tmp;
	double		res;
	t_cylinder	ctmp;

	ctmp = *c;
	tmp = 1;
	if (c->v.z < 0)
		tmp = -1;
	angle1 = c->v.y != 0 ? tmp * atan(c->v.y / c->v.z) : 0;
	angle2 = c->v.x != 0 ? tmp * asin((c->v.x) / vectormodule(&(c->v))) : 0;
	foo();
	rotatecylinder(c, angle1, angle2);
	rotateline(l, angle1, angle2);
	res = checkcylinder2(l, c);
	rotatecylinder(c, -angle1, -angle2);
	rotateline(l, -angle1, -angle2);
	return (res);
}

double		checkcylinder2(t_line *l, t_cylinder *c)
{
	double r1;
	double r2;
	double k1;
	double k2;
	double k3;

	k1 = pow(l->xmul, 2) + pow(l->ymul, 2);
	k2 = l->xmul * (l->xadd - c->p.x) + l->ymul * (l->yadd - c->p.y);
	k3 = pow(l->xadd - c->p.x, 2) + pow(l->yadd -
			c->p.y, 2) - pow(c->radius, 2);
	r1 = (-k2 + sqrt(k2 * k2 - k1 * k3)) / k1;
	r2 = (-k2 - sqrt(k2 * k2 - k1 * k3)) / k1;
	return (checkcylinder3(l, c, r1, r2));
}

double		checkcylinder3(t_line *l, t_cylinder *c, double r1, double r2)
{
	t_point p;

	p = getpointonline(l, r1);
	if (p.z >= (-c->height / 2 + c->p.z) &&
		p.z <= (c->height / 2 + c->p.z))
		return (r1);
	p = getpointonline(l, r2);
	if (p.z >= (-c->height / 2 + c->p.z) &&
		p.z <= (c->height / 2 + c->p.z))
		return (r2);
	return (NAN);
}

t_vector	getvectorfromplane(t_plane p)
{
	t_vector	v;

	v.x = p.v.x;
	v.y = p.v.y;
	v.z = p.v.z;
	normvector(&v);
	return (v);
}

t_vector	getcynorm(t_cylinder c, t_point p)
{
	t_line		l;
	t_point		p2;
	t_vector	res;
	double		angle1;
	double		angle2;

	res.x = 1;
	if (c.v.z < 0)
		res.x = -1;
	angle1 = c.v.y != 0 ? res.x * atan(c.v.y / c.v.z) : 0;
	angle2 = c.v.x != 0 ? res.x * asin((c.v.x) / vectormodule(&(c.v))) : 0;
	rotatecylinder(&c, angle1, angle2);
	rotatexp(&p, angle1);
	rotateyp(&p, angle2);
	p2.x = c.p.x;
	p2.y = c.p.y;
	p2.z = p.z;
	l = makelinep(&p, &p2);
	res = getvectorofline(&l);
	rotatecylinder(&c, -angle1, -angle2);
	rotatexp(&p, -angle1);
	rotateyp(&p, -angle2);
	rotatexv(&res, -angle1);
	rotateyv(&res, -angle2);
	return (res);
}
