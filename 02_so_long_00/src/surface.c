/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surface.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:00:12 by jison             #+#    #+#             */
/*   Updated: 2023/01/25 15:17:41 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_surface	new_surface(t_mlx_ptr mlx, int width, int height)
{
	t_surface	surface;

	surface.image = mlx_new_image(mlx, width, height);
	surface.width = width;
	surface.height = height;
	surface.addr = mlx_get_data_addr(
			surface.image,
			&surface.bits_per_pixel,
			&surface.line_size,
			&surface.endian
			);
	return (surface);
}

t_surface	xpm_to_surface(t_mlx_ptr mlx, char *file)
{
	t_surface	surface;

	surface.image = mlx_xpm_file_to_image(
			mlx,
			file,
			&surface.width,
			&surface.height
			);
	surface.addr = mlx_get_data_addr(
			surface.image,
			&surface.bits_per_pixel,
			&surface.line_size,
			&surface.endian
			);
	return (surface);
}

int	is_overlapped(t_surface dst, t_surface src, int x, int y)
{
	return (
		(1 <= x + src.width) && (x < dst.width)
		&& (1 <= y + src.height) && (y < dst.height)
	);
}

t_surface	blit(t_surface dst, t_surface src, int x, int y)
{
	int	i;
	int	xi;
	int	xf;
	int	yi;
	int	yf;

	if (!is_overlapped(dst, src, x, y))
		return (dst);
	i = 0;
	xi = ft_max(0, x);
	xf = ft_min(dst.width - 1, x + src.width - 1);
	yi = ft_max(0, y);
	yf = ft_min(dst.height - 1, y + src.height - 1);
	while (yi + i <= yf)
	{
		ft_memcpy(
			dst.addr \
			+ ((yi + i) * dst.line_size + xi * (dst.bits_per_pixel / 8)),
			src.addr \
			+ ((ft_max(-y, 0) + i) * src.line_size \
			+ ft_max(-x, 0) * (src.bits_per_pixel / 8)),
			(xf - xi + 1) * sizeof(int));
		++i;
	}
	return (dst);
}

void	fill(t_surface surface, int color)
{
	ft_memset(
		surface.addr,
		color,
		surface.width * surface.height * sizeof(int));
}
