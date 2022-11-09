/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:50:57 by jison             #+#    #+#             */
/*   Updated: 2022/10/16 20:50:09 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "parse_dict.h"
#include "dict_list.h"
#include "io.h"

char	*get_key(char *str)
{
	int		i;
	int		start;
	int		len;
	char	*word;

	i = 0;
	while (is_empty(str[i]))
		++i;
	if (str[i] == '+')
		++i;
	start = i;
	len = 0;
	while ('0' <= str[i] && str[i] <= '9')
		increaser(&i, &len);
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (! word)
		return (0);
	i = 0;
	while (i < len)
	{
		word[i] = str[start + i];
		++i;
	}
	word[i] = '\0';
	return (word);
}

char	*get_value(char *str)
{
	int		i;
	int		start;
	int		len;
	char	*word;

	i = 0;
	while (is_empty(str[i]))
		++i;
	start = i;
	len = 0;
	while (32 <= str[i] && str[i] <= 126)
		increaser(&i, &len);
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (! word)
		return (0);
	i = 0;
	while (i < len)
	{
		word[i] = str[start + i];
		++i;
	}
	word[i] = '\0';
	return (word);
}

int	append_pair(t_dict_list *dict_list, char *line)
{
	int		colon_count;
	char	*key;
	char	*value;

	if (is_empty_line(line))
		return (1);
	colon_count = count_colon(line);
	if (colon_count != 1)
		return (0);
	key = get_key(line);
	while (*line != ':')
		++line;
	value = get_value(line + 1);
	if (is_empty_line(key) || is_empty_line(value))
	{
		free(key);
		free(value);
		return (0);
	}
	append(dict_list, new_dict_node(key, value));
	return (1);
}

int	parse_line(t_dict_list *dict_list, int fd_line, int len)
{
	char	*line;

	line = (char *)malloc(sizeof(char) * (len + 2));
	if (! line)
		return (0);
	read(fd_line, line, len + 1);
	line[len] = '\0';
	if (! append_pair(dict_list, line))
	{
		free(line);
		return (0);
	}
	free(line);
	return (1);
}

int	parse_dict(t_dict_list *dict_list, char *path)
{
	int		fd_len;
	int		fd_line;
	int		len;
	char	buf;

	len = 0;
	if (! open_file(path, &fd_len, &fd_line))
		return (0);
	while (read(fd_len, &buf, 1))
	{
		if (buf == '\n')
		{
			if (! parse_line(dict_list, fd_line, len))
				return (0);
			len = 0;
		}
		else
			++len;
	}
	close_file(fd_len, fd_line);
	return (check_double_key(dict_list));
}
