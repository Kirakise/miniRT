/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:10:28 by rcaraway          #+#    #+#             */
/*   Updated: 2021/02/09 18:10:29 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ultimate.h"

int			eqpoint(t_point *p1, t_point *p2)
{
	if (myequal(p1->x, p2->x))
		return (0);
	if (myequal(p1->y, p2->y))
		return (0);
	if (myequal(p1->z, p2->z))
		return (0);
	return (1);
}

int			myequal(double d1, double d2)
{
	if (d1 < d2 - DELTA)
		return (-1);
	if (d1 > d2 + DELTA)
		return (1);
	return (0);
}

t_vector	getvectorofline(t_line *v)
{
	t_vector t;

	t.x = v->xmul;
	t.y = v->ymul;
	t.z = v->zmul;
	normvector(&t);
	return (t);
}

void		makepoint(t_point *p, double x, double y, double z)
{
	p->x = x;
	p->y = y;
	p->z = z;
}

void		normvector(t_vector *v)
{
	double d;

	d = vectormodule(v);
	v->x /= d;
	v->y /= d;
	v->z /= d;
}
