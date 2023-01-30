/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:22:05 by jison             #+#    #+#             */
/*   Updated: 2023/01/27 12:13:16 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, void *app_ptr)
{
	if (keycode == K_ESC)
		((t_app *)app_ptr)->is_running = 0;
	else if (keycode == K_LEFT || keycode == K_A)
		((t_app *)app_ptr)->game_command = (t_vec2){-1, 0};
	else if (keycode == K_RIGHT || keycode == K_D)
		((t_app *)app_ptr)->game_command = (t_vec2){1, 0};
	else if (keycode == K_UP || keycode == K_W)
		((t_app *)app_ptr)->game_command = (t_vec2){0, -1};
	else if (keycode == K_DOWN || keycode == K_S)
		((t_app *)app_ptr)->game_command = (t_vec2){0, 1};
	return (0);
}
