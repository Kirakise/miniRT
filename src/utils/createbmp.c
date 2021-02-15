/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createbmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 17:58:47 by rcaraway          #+#    #+#             */
/*   Updated: 2021/02/14 17:59:27 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ultimate.h"
#include <fcntl.h>

int	bmp_file(t_image img, int padding_size, int fd)
{
	unsigned char	*header;
	int				size;

	if (!(header = ft_calloc(14, sizeof(unsigned char))))
		return (-1);
	size = 14 + 40 + (img.bits_per_pixel / 8
			* g_data.swidth + padding_size) * g_data.sheight;
	header[0] = (unsigned char)('B');
	header[1] = (unsigned char)('M');
	header[2] = (unsigned char)(size);
	header[3] = (unsigned char)(size >> 8);
	header[4] = (unsigned char)(size >> 16);
	header[5] = (unsigned char)(size >> 24);
	header[10] = (unsigned char)(14 + 40);
	write(fd, header, 14);
	return (0);
}

int	bmp_info(t_image img, int fd)
{
	unsigned char	*header;

	if (!(header = ft_calloc(40, sizeof(unsigned char))))
		return (-1);
	header[0] = (unsigned char)(40);
	header[4] = (unsigned char)(g_data.swidth);
	header[5] = (unsigned char)(g_data.swidth >> 8);
	header[6] = (unsigned char)(g_data.swidth >> 16);
	header[7] = (unsigned char)(g_data.swidth >> 24);
	header[8] = (unsigned char)(g_data.sheight);
	header[9] = (unsigned char)(g_data.sheight >> 8);
	header[10] = (unsigned char)(g_data.sheight >> 16);
	header[11] = (unsigned char)(g_data.sheight >> 24);
	header[12] = (unsigned char)(1);
	header[14] = (unsigned char)(img.bits_per_pixel);
	write(fd, header, 40);
	return (0);
}

int	create_bmp_image(t_image img, char *file_name)
{
	int				i;
	int				fd;
	int				size;
	unsigned char	padding[3];

	i = g_data.sheight;
	padding[0] = 0;
	padding[1] = 0;
	padding[2] = 0;
	if (!(fd = open(file_name, O_CREAT | O_WRONLY | O_TRUNC, 0644)))
		return (-1);
	size = (4 - (g_data.swidth * img.bits_per_pixel / 8) % 4) % 4;
	if (bmp_file(img, size, fd) || bmp_info(img, fd))
		return (-1);
	while (i >= 0)
	{
		write(fd, img.addr + (i * g_data.swidth * img.bits_per_pixel / 8),
				img.line_length);
		write(fd, padding, size);
		i--;
	}
	close(fd);
	return (0);
}
