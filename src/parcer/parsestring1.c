/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsestring1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:39:09 by rcaraway          #+#    #+#             */
/*   Updated: 2021/02/09 18:39:10 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ultimate.h"

int		parseres(char *s)
{
	if (g_data.swidth > 0 || g_data.sheight > 0)
		return (-1);
	g_data.swidth = ft_atoi(&s);
	g_data.sheight = ft_atoi(&s);
	if (g_data.swidth < 1 || g_data.sheight < 1)
		return (-1);
	if (g_data.swidth > 1920)
		g_data.swidth = 1920;
	if (g_data.sheight > 1080)
		g_data.sheight = 1080;
	return (1);
}

int		parseamb(char *s)
{
	if (g_data.alratio != -1 || g_data.alcolor.r != -1 ||
		g_data.alcolor.g != -1 || g_data.alcolor.b != -1)
		return (-1);
	g_data.alratio = ft_atoi_double(&s);
	g_data.alcolor.r = ft_atoi(&s);
	g_data.alcolor.g = ft_atoi(&s);
	g_data.alcolor.b = ft_atoi(&s);
	if (g_data.alratio < 0 || g_data.alratio > 1 ||
	checkcolor(g_data.alcolor))
		return (-1);
	return (1);
}

int		parsecam(char *s)
{
	t_cam	*c;

	c = g_data.cams;
	while (c->next)
		c = c->next;
	if (!(c->next = camconst()))
		return (-1);
	c = c->next;
	readpoint(&c->p, &s);
	readvector(&c->v, &s);
	foo();
	c->fow = ft_atoi(&s);
	if (c->fow >= 180 || c->fow < 1)
		return (-1);
	if (vectormodule(&c->v) != 1)
		return (-1);
	normvector(&c->v);
	return (1);
}

int		parselight(char *s)
{
	t_light *l;

	l = g_data.lights;
	while (l->next)
		l = l->next;
	if (!(l->next = lightconst()))
		return (-1);
	l = l->next;
	readpoint(&l->p, &s);
	l->brightness = ft_atoi_double(&s);
	readcolor(&l->color, &s);
	if (l->brightness < 0 || l->brightness > 1 ||
	checkcolor(l->color))
		return (-1);
	return (1);
}

int		parsesphere(char *s)
{
	t_obj		*o;
	t_sphere	*s1;

	o = g_data.objects;
	while (o->next)
		o = o->next;
	if (!(o->next = objconst()))
		return (-1);
	o = o->next;
	o->type = 1;
	if (!(o->obj = malloc(sizeof(struct s_sphere))))
		return (-1);
	s1 = o->obj;
	readpoint(&s1->center, &s);
	s1->radius = ft_atoi_double(&s) / 2;
	readcolor(&s1->color, &s);
	if (checkcolor(s1->color) || s1->radius <= 0)
		return (-1);
	return (1);
}
