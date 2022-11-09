/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:53:59 by jison             #+#    #+#             */
/*   Updated: 2022/10/11 12:50:42 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_valid_base(char *base);
int	digit_at(char c, char *base, int base_size);
int	ft_atoi_base(char *str, char *base);

int	my_strlen(char *str)
{
	int	ret;

	ret = 0;
	while (str[ret])
		++ret;
	return (ret);
}

int	get_num_base_len(long long n, char base_size)
{
	if (n / base_size == 0)
		return (1);
	return (1 + get_num_base_len(n / base_size, base_size));
}

void	convert_base_to(char *ret, long long nbr, char *base, int index)
{
	int	base_size;

	if (nbr < 0)
	{
		ret[0] = '-';
		convert_base_to(ret, -nbr, base, index);
		return ;
	}
	base_size = my_strlen(base);
	if (nbr / base_size == 0)
	{
		ret[index] = base[nbr % base_size];
		return ;
	}
	convert_base_to(ret, nbr / base_size, base, index - 1);
	ret[index] = base[nbr % base_size];
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long long	n;
	char		*ret;
	int			ret_buf_size;

	if (! (is_valid_base(base_from) && is_valid_base(base_to)))
		return (0);
	n = (long long)ft_atoi_base(nbr, base_from);
	if (n < 0)
		ret_buf_size = get_num_base_len(-n, my_strlen(base_to)) + 2;
	else
		ret_buf_size = get_num_base_len(n, my_strlen(base_to)) + 1;
	ret = (char *)malloc(sizeof(char) * ret_buf_size);
	if (! ret)
		return (0);
	ret[ret_buf_size - 1] = '\0';
	convert_base_to(ret, n, base_to, ret_buf_size - 2);
	return (ret);
}
