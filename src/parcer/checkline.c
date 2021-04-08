/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkline.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 20:49:10 by rcaraway          #+#    #+#             */
/*   Updated: 2021/03/02 20:52:04 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ultimate.h"

int	isarg(char c)
{
	if ((c >= '0' && c <= '9') || c == '.')
		return (1);
	else
		return (0);
}

int	isdoublestr(char *s)
{
	while (*s && isarg(*s))
	{
		if (*s == '.')
			return (1);
		else
			s++;
	}
	return (0);
}

int	bad_atoi(char **str)
{
	int		ret;
	int		prev;

	ret = 0;
	prev = ret;
	while (**str && isarg(**str))
	{
		ret = ret * 10 + (**str - '0');
		if (prev > ret)
			return (-1);
		prev = ret;
		(*str)++;
	}
	return (ret);
}

int	countargs(char *s)
{
	int res;

	res = 0;
	while (*s)
	{
		while (!isarg(*s) && *s)
			s++;
		if (*s)
			res++;
		if (!isdoublestr(s))
			if (bad_atoi(&s) == -1)
				return (-1);
		while (isarg(*s))
			s++;
	}
	return (res);
}
