/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:07:57 by rcaraway          #+#    #+#             */
/*   Updated: 2021/02/09 18:07:58 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ultimate.h"
#include <math.h>

double	checksphere(t_line *l, t_sphere *s)
{
	double		k1;
	double		k2;
	double		k3;
	double		r1;
	double		r2;

	k1 = pow(l->xmul, 2) + pow(l->ymul, 2) + pow(l->zmul, 2);
	k2 = l->xmul * (l->xadd - s->center.x) + l->ymul *
		(l->yadd - s->center.y) + l->zmul * (l->zadd - s->center.z);
	k3 = pow(l->xadd - s->center.x, 2) + pow(l->yadd - s->center.y, 2)
		+ pow(l->zadd - s->center.z, 2) - pow(s->radius, 2);
	r1 = (-k2 + sqrt(k2 * k2 - k1 * k3)) / k1;
	r2 = (-k2 - sqrt(k2 * k2 - k1 * k3)) / k1;
	return (r1 < r2 && r1 > 0 ? r1 : r2);
}

double	checkplane(t_line *l, t_plane *p)
{
	double		d;
	double		r;
	double		k1;

	d = p->v.x * p->p.x + p->v.y * p->p.y + p->v.z * p->p.z;
	k1 = p->v.x * l->xmul + p->v.y * l->ymul + p->v.z * l->zmul;
	r = d - p->v.x * l->xadd - p->v.y * l->yadd - p->v.z * l->zadd;
	return (r / k1);
}

double	vectormodule(t_vector *t)
{
	return (sqrt(t->x * t->x + t->y * t->y + t->z * t->z));
}

double	trunc(double d)
{
	d = floor(d / DELTA) * DELTA;
	return (d);
}
