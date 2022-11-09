/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:44:45 by jison             #+#    #+#             */
/*   Updated: 2022/10/06 19:41:49 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_space(char c)
{
	char	*space_class;

	space_class = "\t\n\v\f\r ";
	while (*space_class)
	{
		if (c == *space_class)
			return (1);
		++space_class;
	}
	return (0);
}

int	is_valid_base(char *base)
{
	int	i;
	int	base_size;
	int	char_counts[256];

	base_size = 0;
	while (base[base_size])
		++base_size;
	if (base_size <= 1)
		return (0);
	i = -1;
	while (++i < 256)
		char_counts[i] = 0;
	i = -1;
	while (++i < base_size)
	{
		if (is_space(base[i]))
			return (0);
		++char_counts[(unsigned char)base[i]];
	}
	i = -1;
	while (++i < 256)
		if (char_counts[i] >= 2)
			return (0);
	return (char_counts['+'] == 0 && char_counts['-'] == 0);
}

int	digit_at(char c, char *base, int base_size)
{
	int	ret;

	ret = -1;
	while (++ret < base_size)
		if (c == base[ret])
			return (ret);
	return (-1);
}

long long	atoi_base(char *str, char *base, int base_size)
{
	long long	ret;
	int			d;

	if (*str == '-')
		return (-atoi_base(str + 1, base, base_size));
	if (*str == '+')
		return (atoi_base(str + 1, base, base_size));
	ret = 0;
	d = digit_at(*str, base, base_size);
	while (d != -1)
	{
		ret *= base_size;
		ret += d;
		++str;
		d = digit_at(*str, base, base_size);
	}
	return (ret);
}

int	ft_atoi_base(char *str, char *base)
{
	int	base_size;

	if (! is_valid_base(base))
		return (0);
	while (is_space(*str))
		++str;
	base_size = 0;
	while (base[base_size])
		++base_size;
	return ((int)(atoi_base(str, base, base_size)));
}
