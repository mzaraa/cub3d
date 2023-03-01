/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:04:40 by mzaraa            #+#    #+#             */
/*   Updated: 2023/03/01 13:34:42 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	dda(t_data *data)
{
	data->ray.hit = 0;
	while (data->ray.hit == 0)
	{
		if (data->ray.side_dist.x < data->ray.side_dist.y)
		{
			data->ray.side_dist.x += data->ray.delta.x;
			data->ray.map.x += data->ray.step.x;
			data->ray.side = 0;
		}
		else
		{
			data->ray.side_dist.y += data->ray.delta.y;
			data->ray.map.y += data->ray.step.y;
			data->ray.side = 1;
		}
		if (data->map[data->ray.map.y][data->ray.map.x] == '1')
			data->ray.hit = 1;
	}
}

void	set_step(t_data *data)
{
	set_vector_i(&data->ray.step, 0, 0);
	if (data->ray.ray_dir.x < 0)
	{
		data->ray.step.x = -1;
		data->ray.side_dist.x = (data->player.pos.x - data->ray.map.x) * \
			data->ray.delta.x;
	}
	else
	{
		data->ray.step.x = 1;
		data->ray.side_dist.x = (data->ray.map.x + 1.0 - data->player.pos.x) * \
			data->ray.delta.x;
	}
	if (data->ray.ray_dir.y < 0)
	{
		data->ray.step.y = -1;
		data->ray.side_dist.y = (data->player.pos.y - data->ray.map.y) * \
			data->ray.delta.y;
	}
	else
	{
		data->ray.step.y = 1;
		data->ray.side_dist.y = (data->ray.map.y + 1.0 - data->player.pos.y) * \
			data->ray.delta.y;
	}
}

void	set_delta(t_data *data)
{
	set_vector_d(&data->ray.delta, 0, 0);
	if (data->ray.ray_dir.x == 0)
		data->ray.delta.x = INFINITY;
	else
		data->ray.delta.x = fabs(1 / data->ray.ray_dir.x);
	if (data->ray.ray_dir.y == 0)
		data->ray.delta.y = INFINITY;
	else
		data->ray.delta.y = fabs(1 / data->ray.ray_dir.y);
}

void	raycast(t_data *data)
{
	while (data->ray.x < data->window_width)
	{
		set_vector_d(&data->ray.side_dist, 0, 0);
		set_vector_i(&data->ray.step, 0, 0);
		set_vector_i(&data->ray.map, 0, 0);
		data->ray.side = 0;
		data->ray.camera_x = 2 * data->ray.x / (double)data->window_width - 1;
		set_vector_d(&data->ray.ray_dir, \
			data->player.dir.x + data->player.plane.x * data->ray.camera_x, \
				data->player.dir.y + data->player.plane.y * data->ray.camera_x);
		set_vector_i(&data->ray.map, (int)data->player.pos.x, \
			(int)data->player.pos.y);
		set_delta(data);
		set_step(data);
		dda(data);
		data->tex_to_draw = check_wall_dir(data);
		if (data->ray.side == 0)
			data->ray.pwd = (data->ray.side_dist.x - data->ray.delta.x);
		else
			data->ray.pwd = (data->ray.side_dist.y - data->ray.delta.y);
		draw_wall(data);
		data->ray.x++;
	}
}
/* 		data->rays_coords[data->ray.x].x = 
data->player.pos.x + data->ray.pwd * data->ray.ray_dir.x;
		data->rays_coords[data->ray.x].y = 
		data->player.pos.y + data->ray.pwd * data->ray.ray_dir.y; */
