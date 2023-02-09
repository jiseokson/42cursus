/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:00:27 by jison             #+#    #+#             */
/*   Updated: 2023/02/09 15:06:52 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex_log(char *message)
{
	ft_fprintf(
		STDERR_FILENO,
		"%s: %s: %s\n", PROGRAM_NAME, message, strerror(errno));
	exit(EXIT_FAILURE);
}
