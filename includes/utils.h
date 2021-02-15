/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 19:04:22 by rcaraway          #+#    #+#             */
/*   Updated: 2021/02/14 17:59:55 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "minirt.h"

int		ft_atoi(char **str);
void	ft_putstr(char *s);
int		foo();
double	ft_atoi_double(char **s);
void	cleanall();
void	cleanall2();
void	cleanall3();
int		create_bmp_image(t_image img, char *file_name);
void	*ft_calloc(int size1, int size2);
int		checkcolor(t_color c);
#endif
