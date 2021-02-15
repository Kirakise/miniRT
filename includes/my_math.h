/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 19:00:47 by rcaraway          #+#    #+#             */
/*   Updated: 2021/02/09 19:01:11 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_MATH_H
# define MY_MATH_H
# include <math.h>
# define PI_NUM 3.1415926
# define DELTA  0.001

typedef struct		s_color
{
	int				r;
	int				g;
	int				b;
}					t_color;

typedef struct		s_vector{
	double			x;
	double			y;
	double			z;
}					t_vector;

typedef struct		s_point{
	double			x;
	double			y;
	double			z;
}					t_point;

typedef	struct		s_line{
	double			xmul;
	double			xadd;
	double			ymul;
	double			yadd;
	double			zmul;
	double			zadd;
}					t_line;

typedef struct		s_sphere{
	t_point			center;
	double			radius;
	t_color			color;
}					t_sphere;

typedef struct		s_plane{
	t_vector		v;
	t_point			p;
	t_color			color;
}					t_plane;

typedef struct		s_result{
	double			res;
	t_vector		v;
	t_color			color;
}					t_result;

typedef struct		s_cam
{
	t_point			p;
	t_vector		v;
	int				fow;
	struct s_cam	*next;
}					t_cam;

typedef struct		s_square{
	t_point			pc;
	t_point			p1;
	t_point			p2;
	t_point			p3;
	t_point			p4;
	t_vector		v;
	double			side;
	t_color			color;
}					t_square;

typedef struct		s_triangle{
	t_point			p1;
	t_point			p2;
	t_point			p3;
	t_color			color;
	t_vector		v;
}					t_triangle;

typedef struct		s_cylinder{
	t_point			p;
	t_vector		v;
	double			radius;
	double			height;
	t_color			color;
}					t_cylinder;

typedef struct		s_cres
{
	double			rres;
	double			gres;
	double			bres;
}					t_cres;

double				trunc(double d);
t_point				getpointonline(t_line *l, double t);
t_line				makeline(t_point *p, t_vector *v);
void				normvector(t_vector *v);
double				distance(t_point *t1, t_point *t2);
double				checkplane(t_line *l, t_plane *p);
double				checksphere(t_line *l, t_sphere *s);
t_line				makelinep(t_point *p1, t_point *p2);
t_vector			getcynorm(t_cylinder c, t_point p);
void				rotatecams(double angle1, double angle2);
void				changecords(t_cam *c);
void				rotatezv(t_vector *v, double angle);
void				rotateyv(t_vector *v, double angle);
void				rotatexv(t_vector *v, double angle);
double				getangle(t_vector *v1, t_vector *v2);
void				rotatexp(t_point *v, double angle);
void				rotateyp(t_point *v, double angle);
void				rotatezp(t_point *v, double angle);
void				rotatecord(t_cam *c);
void				rotatelights(double angle1, double angle2);
void				rotateobjects(double angle1, double angle2);
void				rotatecam(double angle1, double angle2, t_cam *c);
void				rotatesphere(double angle1, double angle2, t_sphere *s);
double				vectormodule(t_vector *t);
void				rotateall(double angle1, double angle2);
void				makecolor(t_color *c, int r, int g, int b);
int					eqpoint(t_point *p1, t_point *p2);
int					myequal(double d1, double d2);
t_vector			getvectorofline(t_line *v);
void				addlightcolor(t_color *c, t_cres light);
double				checktriangle(t_line *l, t_triangle *t);
double				checksquare(t_line *l, t_square *s);
double				checksquare2(t_square *s, t_point p1, double res);
double				checksquare3(t_square *s, t_point p1, double res);
double				checksquare4(t_square *s, t_point p1, double res);
double				checkcylinder(t_line *l, t_cylinder *c);
double				checkcylinder2(t_line *l, t_cylinder *c);
double				checkcylinder3(t_line *l,
		t_cylinder *c, double r1, double r2);
t_vector			getvectorfromplane(t_plane p);
void				rotatesquare(t_square *s, double angle1, double angle2);
void				rotatesquareinit(t_square *s);
void				rotatecylinder(t_cylinder *c, double angle1, double angle2);
void				rotateline(t_line *l, double angle1, double angle2);
void				rotatetriangle(t_triangle *t, double angle1, double angle2);
void				rotateplane(t_plane *p, double angle1, double angle2);
void				makepoint(t_point *p, double x, double y, double z);
void				changecordplane(t_plane *p, double x, double y, double z);
void				changecordsquare(t_square *s, double x, double y, double z);
void				changecordcylinder(t_cylinder *c,
		double x, double y, double z);
void				changecordtriangle(t_triangle *s,
		double x, double y, double z);
t_plane				getplane(t_point p1, t_point p2, t_point p3);
#endif
