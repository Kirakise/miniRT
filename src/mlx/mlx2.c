/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:28:31 by rcaraway          #+#    #+#             */
/*   Updated: 2021/02/09 21:48:42 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ultimate.h"

int		checkinter(t_line *l, t_point *p)
{
	t_obj	*o;
	double	res;
	t_point	p1;

	o = g_data.objects->next;
	res = 200000;
	while (o)
	{
		checkres(&res, o, l);
		o = o->next;
	}
	p1 = getpointonline(l, res);
	if (eqpoint(p, &p1))
		return (1);
	return (0);
}

void	addlight(t_color *c, t_vector v, t_point *p, t_vector vv)
{
	t_light		*l;
	t_line		tmp;
	t_vector	vtmp;
	t_cres		result;

	initcres(&result, g_data.alcolor, g_data.alratio);
	l = g_data.lights->next;
	while (l)
	{
		tmp = makelinep(p, &(l->p));
		vtmp = getvectorofline(&tmp);
		tmp = makelinep(&(l->p), p);
		if (checkinter(&tmp, p) && (cos(getangle(&v, &vtmp)) > 0))
		{
			addcres(&result, l->color, cos(getangle(&v, &vtmp))
					* l->brightness);
			addcres(&result, l->color, addblight(vv, computereflected(vtmp, v),
			l->brightness));
		}
		l = l->next;
	}
	addlightcolor(c, result);
}

void	addlightcolor(t_color *c, t_cres light)
{
	c->b *= light.bres;
	c->g *= light.gres;
	c->r *= light.rres;
	if (c->b > 255)
		c->b = 255;
	if (c->g > 255)
		c->g = 255;
	if (c->r > 255)
		c->r = 255;
	if (c->b < 0)
		c->b = 0;
	if (c->r < 0)
		c->r = 0;
	if (c->g < 0)
		c->g = 0;
}
