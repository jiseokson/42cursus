/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:38:39 by jison             #+#    #+#             */
/*   Updated: 2022/10/06 14:36:27 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	my_strlen(char *str)
{
	int	ret;

	ret = 0;
	while (str[ret])
		++ret;
	return (ret);
}

int	is_valid_base(char *base)
{
	int	i;
	int	base_size;
	int	char_counts[256];

	base_size = my_strlen(base);
	if (base_size <= 1)
		return (0);
	i = -1;
	while (++i < 256)
		char_counts[i] = 0;
	i = -1;
	while (++i < base_size)
		++char_counts[(unsigned char)base[i]];
	i = -1;
	while (++i < 256)
		if (char_counts[i] >= 2)
			return (0);
	return (char_counts['+'] == 0 && char_counts['-'] == 0);
}

void	print_num_base(long long nbr, char *base, int base_size)
{
	if (nbr / base_size != 0)
		print_num_base(nbr / base_size, base, base_size);
	write(1, base + (nbr % base_size), 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long long	llnbr;
	int			base_size;

	if (! is_valid_base(base))
		return ;
	llnbr = (long long)nbr;
	base_size = my_strlen(base);
	if (nbr < 0)
	{
		llnbr = -llnbr;
		write(1, "-", 1);
	}
	print_num_base(llnbr, base, base_size);
}
