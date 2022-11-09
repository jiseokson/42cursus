/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 13:37:55 by jison             #+#    #+#             */
/*   Updated: 2022/10/18 18:40:58 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUFFER_SIZE (4096)

int		open_file(char *path);
int		close_file(int fd);
int		read_content(int fd, char *buffer, int buffer_size);
void	ft_fprint(int fd, char *str);

void	print_content(int fd)
{
	char	buffer[BUFFER_SIZE];

	while (read_content(fd, buffer, BUFFER_SIZE))
		ft_fprint(1, buffer);
}

int	main(int argc, char **argv)
{
	int		fd;

	if (argc == 1)
	{
		ft_fprint(2, "File name missing.\n");
		return (1);
	}
	if (argc > 2)
	{
		ft_fprint(2, "Too many arguments.\n");
		return (1);
	}
	fd = open_file(*(++argv));
	if (fd < 0)
	{
		ft_fprint(2, "Cannot read file.\n");
		return (1);
	}
	print_content(fd);
	close_file(fd);
	return (0);
}
