/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotatecord3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:26:23 by rcaraway          #+#    #+#             */
/*   Updated: 2021/02/09 18:26:25 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ultimate.h"

void	rotateline(t_line *l, double angle1, double angle2)
{
	t_vector	v;
	t_point		p;

	v.x = l->xmul;
	v.y = l->ymul;
	v.z = l->zmul;
	p.x = l->xadd;
	p.y = l->yadd;
	p.z = l->zadd;
	rotatexv(&(v), angle1);
	rotateyv(&(v), angle2);
	rotatexp(&(p), angle1);
	rotateyp(&(p), angle2);
	l->xmul = v.x;
	l->xadd = p.x;
	l->ymul = v.y;
	l->yadd = p.y;
	l->zmul = v.z;
	l->zadd = p.z;
}

void	rotatetriangle(t_triangle *t, double angle1, double angle2)
{
	rotatexp(&(t->p1), angle1);
	rotateyp(&(t->p1), angle2);
	rotatexp(&(t->p2), angle1);
	rotateyp(&(t->p2), angle2);
	rotatexp(&(t->p3), angle1);
	rotateyp(&(t->p3), angle2);
}

void	rotateplane(t_plane *p, double angle1, double angle2)
{
	rotatexp(&(p->p), angle1);
	rotateyp(&(p->p), angle2);
	rotatexv(&(p->v), angle1);
	rotateyv(&(p->v), angle2);
}
