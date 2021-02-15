/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 19:01:30 by rcaraway          #+#    #+#             */
/*   Updated: 2021/02/09 19:03:51 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_MLX_H
# define MY_MLX_H
# include "my_math.h"
# include "minirt.h"

typedef struct		s_datastruct{
	t_obj			*obj;
	t_cam			*cam;
}					t_datastruct;

int					closewin(int keycode, t_mlx *mlx);
void				mlx_start();
void				get_image(t_cam *c);
int					color_to_int(t_color *c);
void				mlx_put_color(int c, int x, int y);
int					checkobjects(t_line *l);
void				addlight(t_color *c, t_vector v, t_point *p, t_vector vv);
int					checkinter(t_line *l, t_point *p);
double				addblight(t_vector vv, t_vector vr, double brightness);
t_vector			computereflected(t_vector vl, t_vector vn);
void				checkobjects2(t_line *l, t_obj *o, t_result *res);
void				checkobjects3(t_line *l, t_obj *o, t_result *res);
void				checkres(double *res, t_obj *o, t_line *l);
void				control2(int keycode);
void				resizeobj(t_obj *o, double d);
void				rotateobj(t_obj *o, double angle);
void				addcres(t_cres *c, t_color co, double brightness);
void				initcres(t_cres *c, t_color co, double bright);
#endif
