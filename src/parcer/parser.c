/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:37:36 by rcaraway          #+#    #+#             */
/*   Updated: 2021/02/14 18:32:04 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ultimate.h"
#include <fcntl.h>
#include <stdio.h>

int		parsefile(char *s)
{
	int		fd;
	char	*s1;

	if ((fd = open(s, O_RDONLY)) < 3)
		return (-1);
	while (get_next_line(fd, &s1) > 0)
	{
		if (s1[0] == '\0')
		{
			free(s1);
			continue;
		}
		else if (parseline(s1) == -1)
		{
			free(s1);
			return (-1);
		}
	}
	parseline(s1);
	free(s1);
	return (1);
}

int		parseline(char *s)
{
	if (s[0] == 'R')
		return (parseres(s + 1));
	else if (s[0] == 'A')
		return (parseamb(s + 1));
	else if (s[0] == 'c' && s[1] != 'y')
		return (parsecam(s + 1));
	else if (s[0] == 'l')
		return (parselight(s + 1));
	else if (s[0] == 's' && s[1] == 'p')
		return (parsesphere(s + 2));
	if (s[0] == 'p')
		return (parseplane(s + 2));
	if (s[0] == 's' && s[1] == 'q')
		return (parsesquare(s + 2));
	if (s[0] == 'c' && s[1] == 'y')
		return (parsecylinder(s + 2));
	if (s[0] == 't')
		return (parsetriangle(s + 2));
	return (-1);
}

void	readpoint(t_point *p, char **s)
{
	p->x = ft_atoi_double(s);
	p->y = ft_atoi_double(s);
	p->z = ft_atoi_double(s);
}

void	readvector(t_vector *p, char **s)
{
	p->x = ft_atoi_double(s);
	p->y = ft_atoi_double(s);
	p->z = ft_atoi_double(s);
}

void	readcolor(t_color *c, char **s)
{
	c->r = ft_atoi(s);
	c->g = ft_atoi(s);
	c->b = ft_atoi(s);
}
