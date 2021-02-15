/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:40:45 by rcaraway          #+#    #+#             */
/*   Updated: 2021/02/14 17:58:42 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../../includes/ultimate.h"

void	ft_putstr(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		write(1, s + i, 1);
		i++;
	}
}

int		foo(void)
{
	return (1);
}

void	*ft_calloc(int size1, int size2)
{
	char	*s;
	int		i;

	i = size1 * size2;
	s = malloc(i);
	while (--i >= 0)
		s[i] = 0;
	return (s);
}
