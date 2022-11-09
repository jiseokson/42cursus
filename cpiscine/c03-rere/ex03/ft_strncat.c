/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:44:59 by jison             #+#    #+#             */
/*   Updated: 2022/10/06 10:03:07 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	char			*ret;

	ret = dest;
	while (*dest)
		++dest;
	i = 0;
	while ((i < nb) && *src)
	{
		*dest++ = *src++;
		++i;
	}
	*dest = '\0';
	return (ret);
}
