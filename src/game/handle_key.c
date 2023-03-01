/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:40:23 by mzaraa            #+#    #+#             */
/*   Updated: 2023/03/01 13:36:00 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_release(int keycode, t_data *data)
{
	data->keys[keycode] = 0;
	return (1);
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == KEY_ECHAP)
		ft_destroy_mlx(data, "Exit program");
	else
		data->keys[keycode] = 1;
	return (1);
}

int	close_window(t_data *data)
{
	ft_destroy_mlx(data, "Exit program");
	return (0);
}

void	key_manager_bis(t_data *data)
{
	if (data->keys[KEY_D])
	{
		rotate_vector(&data->player.dir, data->player.rot_speed);
		rotate_vector(&data->player.plane, data->player.rot_speed);
	}
	if (data->keys[KEY_A])
	{
		rotate_vector(&data->player.dir, -data->player.rot_speed);
		rotate_vector(&data->player.plane, -data->player.rot_speed);
	}
}

void	key_manager(t_data *data)
{
	if (data->keys[KEY_W])
	{
		if (data->map[(int)data->player.pos.y][(int)(data->player.pos.x + \
			data->player.dir.x * data->player.move_speed)] != '1')
			data->player.pos.x += (data->player.dir.x * \
				data->player.move_speed);
		if (data->map[(int)(data->player.pos.y + data->player.dir.y * \
			data->player.move_speed)][(int)data->player.pos.x] != '1')
			data->player.pos.y += (data->player.dir.y * \
				data->player.move_speed);
	}
	if (data->keys[KEY_S])
	{
		if (data->map[(int)data->player.pos.y][(int)(data->player.pos.x - \
			data->player.dir.x * data->player.move_speed)] != '1')
			data->player.pos.x -= data->player.dir.x * data->player.move_speed;
		if (data->map[(int)(data->player.pos.y - data->player.dir.y * \
			data->player.move_speed)][(int)data->player.pos.x] != '1')
			data->player.pos.y -= data->player.dir.y * data->player.move_speed;
	}
	key_manager_bis(data);
}
