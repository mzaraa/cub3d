/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:40:23 by mzaraa            #+#    #+#             */
/*   Updated: 2023/02/06 14:02:13 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_release(int keycode, t_data *data)
{
	data->keys[keycode] = 0;
	return (0);
}

int	key_press(int keycode, t_data *data)
{
	data->keys[keycode] = 1;
	if (keycode == ESC)
		ft_destroy_mlx(data);
	return (0);
}

int	close_window(t_data *data)
{
	ft_destroy_mlx(data);
	return (0);
}
