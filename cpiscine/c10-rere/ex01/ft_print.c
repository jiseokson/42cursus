/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 13:59:14 by jison             #+#    #+#             */
/*   Updated: 2022/10/18 18:41:41 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_fprint(int fd, char *str)
{
	while (*str)
		write(fd, str++, 1);
}

void	ft_print(char *str)
{
	ft_fprint(1, str);
}

void	ft_print_error(char *program_name, char *path, char *error)
{
	ft_fprint(2, program_name);
	ft_fprint(2, ": ");
	ft_fprint(2, path);
	ft_fprint(2, ": ");
	ft_fprint(2, error);
	ft_fprint(2, "\n");
}
