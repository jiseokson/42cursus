/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:58:05 by jison             #+#    #+#             */
/*   Updated: 2022/10/18 23:27:46 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_H
# define FT_PRINT_H

void	ft_fprint(int fd, char *str);
void	ft_print_file_name(char *path);
void	ft_print_usage(void);
void	ft_print_file_error(char *program_name, char *path, char *error);
void	ft_print_offset_error(char *program_name, char *offset);

#endif
