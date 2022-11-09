/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 15:48:22 by jison             #+#    #+#             */
/*   Updated: 2022/10/16 19:29:58 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

# include "dict_list.h"

void	rush(t_dict_list *dict_list, char *str, int block_index);
char	*rush_preprocess(char *arg);
int		is_valid_arg(t_dict_list *dict_list, char *str);
int		is_head_printed(char *str, int i, int n);
int		is_valid_arg(t_dict_list *dict_list, char *arg);
char	*rush_preprocess(char *arg);
void	print_100(t_dict_list *dict_list, char *str);
void	print_10(t_dict_list *dict_list, char *str);
void	print_block_unit(t_dict_list *dict_list, char *str, int block_index);

#endif
