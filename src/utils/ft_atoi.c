/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 18:50:46 by rcaraway          #+#    #+#             */
/*   Updated: 2020/11/07 15:48:39 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ultimate.h"

int		ft_atoi(char **str)
{
	int			plus;
	long long	num;
	long long	num2;

	plus = 0;
	num = 0;
	num2 = 0;
	while (**str == '\t' || **str == ' ')
		(*str)++;
	if (**str == '+' || **str == '-')
		if (*(*str)++ == '-')
			plus = plus == 0 ? 1 : 0;
	while (**str >= '0' && **str <= '9')
	{
		if (plus == 0 && num2 < num)
			return (-1);
		if (plus == 1 && num2 > num)
			return (0);
		num2 = num;
		num = plus == 0 ? num * 10 - **str + 48 : num * 10 + **str - 48;
		(*str)++;
	}
	(*str)++;
	return (-num);
}
