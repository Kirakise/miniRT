/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotatecord2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:25:24 by rcaraway          #+#    #+#             */
/*   Updated: 2021/02/09 18:25:25 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ultimate.h"

void	rotateall(double angle1, double angle2)
{
	rotatelights(angle1, angle2);
	rotateobjects(angle1, angle2);
	rotatecams(angle1, angle2);
}

void	rotatesquare(t_square *s, double angle1, double angle2)
{
	rotatexp(&(s->p1), angle1);
	rotateyp(&(s->p1), angle2);
	rotatexp(&(s->p2), angle1);
	rotateyp(&(s->p2), angle2);
	rotatexp(&(s->p3), angle1);
	rotateyp(&(s->p3), angle2);
	rotatexp(&(s->p4), angle1);
	rotateyp(&(s->p4), angle2);
	rotatexv(&(s->v), angle1);
	rotateyv(&(s->v), angle2);
}

void	rotatesquareinit(t_square *s)
{
	double	angle1;
	double	angle2;
	int		tmp;

	if ((tmp = 1) && s->v.z < 0)
		tmp = -1;
	angle1 = s->v.y != 0 ? tmp * atan(s->v.y / s->v.z) : 0;
	angle2 = s->v.x != 0 ? tmp * asin((s->v.x) / vectormodule(&(s->v))) : 0;
	rotatexp(&(s->pc), angle1);
	rotateyp(&(s->pc), angle2);
	rotatexv(&(s->v), angle1);
	rotateyv(&(s->v), angle2);
	makepoint(&(s->p1), -s->side / 2 + s->pc.x, -s->side / 2 +
			s->pc.y, s->pc.z);
	makepoint(&(s->p2), -s->side / 2 + s->pc.x, s->side / 2 + s->pc.y, s->pc.z);
	makepoint(&(s->p3), s->side / 2 + s->pc.x, s->side / 2 + s->pc.y, s->pc.z);
	makepoint(&(s->p4), s->side / 2 + s->pc.x, -s->side / 2 + s->pc.y, s->pc.z);
	rotatesquare(s, -angle1, -angle2);
}

void	rotatecylinder(t_cylinder *c, double angle1, double angle2)
{
	rotatexv(&(c->v), angle1);
	rotateyv(&(c->v), angle2);
	rotatexp(&(c->p), angle1);
	rotateyp(&(c->p), angle2);
}

void	rotatecams(double angle1, double angle2)
{
	t_cam *c;

	c = g_data.cams->next;
	while (c)
	{
		rotatecam(angle1, angle2, c);
		c = c->next;
	}
}
