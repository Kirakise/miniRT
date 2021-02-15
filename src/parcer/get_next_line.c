/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:05:54 by rcaraway          #+#    #+#             */
/*   Updated: 2021/01/20 16:02:48 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ultimate.h"

void	ft_bzero2(char *s)
{
	int i;

	i = 0;
	while (i <= BUFFER_SIZE)
		s[i++] = 0;
}

int		get_next_line(int fd, char **line)
{
	static t_str	arr;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line || read(fd, NULL, 0))
		return (-1);
	*line = malloc(1);
	**line = 0;
	return (ft_getline(fd, &(arr), line, 0));
}
