/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   changecord2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:06:31 by rcaraway          #+#    #+#             */
/*   Updated: 2021/02/09 18:06:37 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ultimate.h"

void	changecordsquare(t_square *s, double x, double y, double z)
{
	makepoint(&(s->p1), s->p1.x - x, s->p1.y - y, s->p1.z - z);
	makepoint(&(s->p2), s->p2.x - x, s->p2.y - y, s->p2.z - z);
	makepoint(&(s->p3), s->p3.x - x, s->p3.y - y, s->p3.z - z);
	makepoint(&(s->p4), s->p4.x - x, s->p4.y - y, s->p4.z - z);
	makepoint(&(s->pc), s->pc.x - x, s->pc.y - y, s->pc.z - z);
}

void	changecordcylinder(t_cylinder *c, double x, double y, double z)
{
	c->p.x -= x;
	c->p.y -= y;
	c->p.z -= z;
}

void	changecordtriangle(t_triangle *s, double x, double y, double z)
{
	makepoint(&(s->p1), s->p1.x - x, s->p1.y - y, s->p1.z - z);
	makepoint(&(s->p2), s->p2.x - x, s->p2.y - y, s->p2.z - z);
	makepoint(&(s->p3), s->p3.x - x, s->p3.y - y, s->p3.z - z);
}
