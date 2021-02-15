/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsestring2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:40:21 by rcaraway          #+#    #+#             */
/*   Updated: 2021/02/09 18:40:22 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ultimate.h"
#include <fcntl.h>
#include <stdio.h>

int		parseplane(char *s)
{
	t_plane	*p;
	t_obj	*o;

	p = malloc(sizeof(struct s_plane));
	if (!p)
		return (-1);
	o = g_data.objects;
	while (o->next)
		o = o->next;
	o->next = objconst();
	o = o->next;
	o->obj = p;
	o->type = 2;
	readpoint(&p->p, &s);
	readvector(&p->v, &s);
	p->color.r = ft_atoi(&s);
	p->color.g = ft_atoi(&s);
	p->color.b = ft_atoi(&s);
	if (vectormodule(&p->v) != 1 || checkcolor(p->color))
		return (-1);
	normvector(&p->v);
	return (1);
}

int		parsesquare(char *s)
{
	t_square	*sq;
	t_obj		*o;

	sq = malloc(sizeof(struct s_square));
	if (!sq)
		return (-1);
	o = g_data.objects;
	while (o->next)
		o = o->next;
	o->next = objconst();
	o = o->next;
	o->obj = sq;
	o->type = 3;
	readpoint(&sq->pc, &s);
	readvector(&sq->v, &s);
	if (vectormodule(&sq->v) != 1)
		return (-1);
	normvector(&sq->v);
	sq->side = ft_atoi_double(&s);
	readcolor(&sq->color, &s);
	if (checkcolor(sq->color) || sq->side <= 0)
		return (-1);
	rotatesquareinit(sq);
	return (1);
}

int		parsecylinder(char *s)
{
	t_cylinder	*c;
	t_obj		*o;

	c = malloc(sizeof(struct s_cylinder));
	if (!c)
		return (-1);
	o = g_data.objects;
	while (o->next)
		o = o->next;
	o->next = objconst();
	o = o->next;
	o->type = 4;
	o->obj = c;
	readpoint(&c->p, &s);
	readvector(&c->v, &s);
	if (vectormodule(&c->v) != 1)
		return (-1);
	normvector(&c->v);
	c->radius = ft_atoi_double(&s) / 2;
	c->height = ft_atoi_double(&s);
	readcolor(&c->color, &s);
	if (checkcolor(c->color) || c->height <= 0 || c->radius <= 0)
		return (-1);
	return (1);
}

int		parsetriangle(char *s)
{
	t_triangle	*t;
	t_obj		*o;

	t = malloc(sizeof(struct s_triangle));
	if (!t)
		return (-1);
	o = g_data.objects;
	while (o->next)
		o = o->next;
	o->next = objconst();
	o = o->next;
	o->obj = t;
	o->type = 5;
	readpoint(&t->p1, &s);
	readpoint(&t->p2, &s);
	readpoint(&t->p3, &s);
	readcolor(&t->color, &s);
	if (checkcolor(t->color))
		return (-1);
	return (1);
}
