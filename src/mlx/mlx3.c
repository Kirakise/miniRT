/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:30:25 by rcaraway          #+#    #+#             */
/*   Updated: 2021/02/09 18:31:08 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ultimate.h"

t_vector	computereflected(t_vector vl, t_vector vn)
{
	t_vector	r;
	double		k;

	k = vl.z * vn.z + vl.y + vn.y + vl.x * vn.x;
	r.x = -(vn.x * k - vl.x);
	r.y = -(vn.y * k - vl.y);
	r.z = -(vn.z * k - vl.z);
	return (r);
}

double		addblight(t_vector vv, t_vector vr, double brightness)
{
	double	result;

	return (0);
	result = pow(cos(getangle(&vv, &vr)), 400) * brightness;
	if (result <= 0)
		return (0);
	else
		return (result);
}
