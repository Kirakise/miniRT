/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:09:24 by rcaraway          #+#    #+#             */
/*   Updated: 2021/02/09 18:09:29 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ultimate.h"

double		distance(t_point *t1, t_point *t2)
{
	return (sqrt(pow(t2->x - t1->x, 2) +
				pow(t2->y - t1->y, 2) + pow(t2->z - t1->z, 2)));
}

t_line		makeline(t_point *p, t_vector *v)
{
	t_line	l;
	double	d;

	l.xmul = v->x;
	l.xadd = p->x;
	l.ymul = v->y;
	l.yadd = p->y;
	l.zmul = v->z;
	l.zadd = p->z;
	d = sqrt(l.xmul * l.xmul + l.ymul * l.ymul + l.zmul * l.zmul);
	l.xmul /= d;
	l.ymul /= d;
	l.zmul /= d;
	return (l);
}

t_line		makelinep(t_point *p1, t_point *p2)
{
	t_line	l;
	double	d;

	l.xmul = p2->x - p1->x;
	l.xadd = p1->x;
	l.ymul = p2->y - p1->y;
	l.yadd = p1->y;
	l.zmul = p2->z - p1->z;
	l.zadd = p1->z;
	d = sqrt(l.xmul * l.xmul + l.ymul * l.ymul + l.zmul * l.zmul);
	l.xmul /= d;
	l.ymul /= d;
	l.zmul /= d;
	return (l);
}

t_point		getpointonline(t_line *l, double t)
{
	t_point	p;

	p.x = l->xmul * t + l->xadd;
	p.y = l->ymul * t + l->yadd;
	p.z = l->zmul * t + l->zadd;
	return (p);
}

void		makecolor(t_color *c, int r, int g, int b)
{
	c->r = r;
	c->b = b;
	c->g = g;
}
