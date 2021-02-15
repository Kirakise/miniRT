/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:51:25 by rcaraway          #+#    #+#             */
/*   Updated: 2021/02/14 17:55:16 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include "my_math.h"
# include <mlx.h>

# define DIST 0.1

typedef struct		s_obj
{
	void			*obj;
	int				type;
	struct s_obj	*next;
}					t_obj;

typedef struct		s_light
{
	t_point			p;
	double			brightness;
	t_color			color;
	struct s_light	*next;
}					t_light;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
}					t_mlx;

typedef struct		s_data{
	t_obj			*objects;
	t_cam			*camcur;
	t_obj			*objcur;
	t_cam			*cams;
	t_light			*lights;
	t_mlx			mlx;
	double			alratio;
	t_color			alcolor;
	int				swidth;
	int				sheight;
	int				save;
	int				tmp;
}					t_data;

typedef struct		s_image{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_image;
int					closewin2(int a);
#endif
