/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:47:40 by rcaraway          #+#    #+#             */
/*   Updated: 2021/02/09 18:47:41 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

int		parsefile(char *s);
int		parseline(char *s);
int		parseres(char *s);
int		parseamb(char *s);
int		parsecam(char *s);
int		parselight(char *s);
int		parsesphere(char *s);
int		parseplane(char *s);
int		parsesquare(char *s);
int		parsecylinder(char *s);
int		parsetriangle(char *s);
void	readpoint(t_point *p, char **s);
void	readvector(t_vector *p, char **s);
void	readcolor(t_color *c, char **s);

#endif
