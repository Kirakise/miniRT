/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:22:17 by rcaraway          #+#    #+#             */
/*   Updated: 2021/02/09 18:22:27 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ultimate.h"

void	rotatexp(t_point *v, double angle)
{
	double y;
	double z;

	y = v->y * cos(angle) + v->z * -sin(angle);
	z = v->y * sin(angle) + v->z * cos(angle);
	v->y = y;
	v->z = z;
}

void	rotateyp(t_point *v, double angle)
{
	double x;
	double z;

	x = v->x * cos(angle) + v->z * -sin(angle);
	z = v->x * sin(angle) + v->z * cos(angle);
	v->x = x;
	v->z = z;
}

void	rotatezp(t_point *v, double angle)
{
	double x;
	double y;

	x = v->x * cos(angle) + v->y * sin(angle);
	y = v->x * -sin(angle) + v->y * cos(angle);
	v->x = x;
	v->y = y;
}
