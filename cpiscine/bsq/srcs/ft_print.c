/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:08:17 by jison             #+#    #+#             */
/*   Updated: 2022/10/17 17:09:10 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_fprint_char(int fd, char c)
{
	write(fd, &c, 1);
}

void	ft_fprint(int fd, char *str)
{
	while (*str)
		write(fd, str++, 1);
}
