/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 17:42:54 by rcaraway          #+#    #+#             */
/*   Updated: 2021/02/09 17:44:08 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ultimate.h"
#include <mlx.h>

void	rotateobj(t_obj *o, double angle)
{
	if (o->type == 2)
		rotateplane(o->obj, angle, 0);
	if (o->type == 3)
		rotatesquare(o->obj, angle, 0);
	if (o->type == 4)
		rotatecylinder(o->obj, angle, 0);
}

int		closewin2(int a)
{
	mlx_destroy_window(g_data.mlx.mlx, g_data.mlx.win);
	exit(a);
	return (0);
}
