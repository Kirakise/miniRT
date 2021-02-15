/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:43:38 by rcaraway          #+#    #+#             */
/*   Updated: 2021/02/09 18:43:40 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ultimate.h"

double	ft_atoi_double(char **s)
{
	int		i;
	double	d;
	double	drob;
	int		znak;
	int		tmp;

	i = 0;
	d = 0;
	drob = 0;
	znak = 0;
	tmp = 0;
	while (((*s)[i] == ' ' || (*s)[i] == '\t') && (*s)[i])
		i++;
	if ((*s)[i] == '-' && (znak = 1))
		i++;
	while ((*s)[i] != '.' && (*s)[i] != ',' && (*s)[i] && (*s)[i] != ' '
	&& (*s)[i] != '\t')
		d = d * 10 + (*s)[i++] - '0';
	i += (*s)[i] == '.' ? 1 : 0;
	while ((*s)[i] >= '0' && (*s)[i] <= '9' && ++tmp)
		drob = drob * 10 + (*s)[i++] - '0';
	while (tmp-- > 0)
		drob /= 10;
	*s += i + 1;
	return (znak == 1 ? -(d + drob) : (d + drob));
}
