/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 20:29:24 by seojyang          #+#    #+#             */
/*   Updated: 2022/10/18 16:55:40 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

int		is_printable(char c);
int		is_num(char c);
int		ft_atoi(char *buffer, int len);
void	make_info(char *buffer, char *info);
int		is_info(char now, char *info);

#endif
