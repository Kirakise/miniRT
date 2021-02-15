/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:10:36 by rcaraway          #+#    #+#             */
/*   Updated: 2021/02/09 18:13:05 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ultimate.h"

t_plane		getplane(t_point p1, t_point p2, t_point p3)
{
	t_plane p;

	p.v.x = (p2.y - p1.y) * (p3.z - p1.z) - (p2.z - p1.z) * (p3.y - p1.y);
	p.v.y = (p3.x - p1.x) * (p2.z - p1.z) - (p3.z - p1.z) * (p2.x - p1.x);
	p.v.z = (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
	p.p = p1;
	return (p);
}

double		checktriangle(t_line *l, t_triangle *t)
{
	t_plane p;
	double	res;
	t_point p1;

	res = NAN;
	p = getplane(t->p1, t->p2, t->p3);
	t->v = p.v;
	res = checkplane(l, &p);
	if (isnan(res))
		return (NAN);
	p1 = getpointonline(l, res);
	if (((t->p1.x - p1.x) * (t->p2.y - t->p1.y) -
			(t->p2.x - t->p1.x) * (t->p1.y - p1.y) >= 0 &&
		(t->p2.x - p1.x) * (t->p3.y - t->p2.y) -
		(t->p3.x - t->p2.x) * (t->p2.y - p1.y) >= 0 &&
		(t->p3.x - p1.x) * (t->p1.y - t->p3.y) -
		(t->p1.x - t->p3.x) * (t->p3.y - p1.y) >= 0)
	|| ((t->p1.x - p1.x) * (t->p2.y - t->p1.y) -
			(t->p2.x - t->p1.x) * (t->p1.y - p1.y) <= 0 &&
		(t->p2.x - p1.x) * (t->p3.y - t->p2.y) -
		(t->p3.x - t->p2.x) * (t->p2.y - p1.y) <= 0 &&
		(t->p3.x - p1.x) * (t->p1.y - t->p3.y) -
		(t->p1.x - t->p3.x) * (t->p3.y - p1.y) <= 0))
		return (res);
	return (NAN);
}
