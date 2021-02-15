/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx5.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:35:15 by rcaraway          #+#    #+#             */
/*   Updated: 2021/02/09 21:48:23 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ultimate.h"

void	checkres(double *res, t_obj *o, t_line *l)
{
	double tmp;

	if (o->type == 1 && !isnan(tmp = checksphere(l, o->obj))
			&& tmp > 0 && myequal(tmp, *res) == -1)
		*res = tmp;
	else if (o->type == 2 && !isnan(tmp = checkplane(l, o->obj))
			&& tmp > 0 && myequal(tmp, *res) == -1)
		*res = tmp;
	else if (o->type == 3 && !isnan(tmp = checksquare(l, o->obj))
			&& tmp > 0 && myequal(tmp, *res) == -1)
		*res = tmp;
	else if (o->type == 4 && !isnan(tmp = checkcylinder(l, o->obj))
			&& tmp > 0 && myequal(tmp, *res) == -1)
		*res = tmp;
	else if (o->type == 5 && !isnan(tmp = checktriangle(l, o->obj))
			&& tmp > 0 && myequal(tmp, *res) == -1)
		*res = tmp;
}

void	initcres(t_cres *c, t_color co, double bright)
{
	c->rres = bright * co.r / 255;
	c->bres = bright * co.b / 255;
	c->gres = bright * co.g / 255;
}

void	addcres(t_cres *c, t_color co, double brightness)
{
	c->rres += brightness * co.r / 255;
	c->bres += brightness * co.b / 255;
	c->gres += brightness * co.g / 255;
}
