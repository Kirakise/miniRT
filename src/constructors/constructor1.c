/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 17:40:32 by rcaraway          #+#    #+#             */
/*   Updated: 2021/02/09 17:40:34 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ultimate.h"

t_obj	*objconst(void)
{
	t_obj *o;

	if (!(o = malloc(sizeof(struct s_obj))))
		return (0);
	o->obj = 0;
	o->type = 0;
	o->next = 0;
	return (o);
}

t_cam	*camconst(void)
{
	t_cam *c;

	if (!(c = malloc(sizeof(struct s_cam))))
		return (0);
	c->next = 0;
	return (c);
}

t_light	*lightconst(void)
{
	t_light *l;

	if (!(l = malloc(sizeof(struct s_light))))
		return (0);
	l->next = 0;
	return (l);
}
