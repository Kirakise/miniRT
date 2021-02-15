/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:22:04 by rcaraway          #+#    #+#             */
/*   Updated: 2021/02/09 18:22:05 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ultimate.h"

double	getangle(t_vector *v1, t_vector *v2)
{
	double a1;
	double a2;

	a1 = v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
	a2 = sqrt(v1->x * v1->x + v1->y * v1->y + v1->z * v1->z)
		* sqrt(v2->x * v2->x + v2->y * v2->y + v2->z * v2->z);
	return (acos(a1 / a2));
}

void	rotatexv(t_vector *v, double angle)
{
	double y;
	double z;

	y = v->y * cos(angle) + v->z * -sin(angle);
	z = v->y * sin(angle) + v->z * cos(angle);
	v->y = y;
	v->z = z;
}

void	rotateyv(t_vector *v, double angle)
{
	double x;
	double z;

	x = v->x * cos(angle) + v->z * -sin(angle);
	z = v->x * sin(angle) + v->z * cos(angle);
	v->x = x;
	v->z = z;
}

void	rotatezv(t_vector *v, double angle)
{
	double x;
	double y;

	x = v->x * cos(angle) + v->y * sin(angle);
	y = v->x * -sin(angle) + v->y * cos(angle);
	v->x = x;
	v->y = y;
}
