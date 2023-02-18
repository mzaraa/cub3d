/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:05:23 by mzaraa            #+#    #+#             */
/*   Updated: 2023/02/18 13:36:35 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* 
int	check_wall_dir(t_data *data)
{
	if (data->ray.side == 0)
	{
		if (data->ray.map.y < data->player.pos.y)
			return (NO);
		else
			return (SO);
	}
	else
	{
		if (data->ray.map.x < data->player.pos.x)
			return (WE);
		else
			return (EA);
	}
}
*/

int	check_wall_dir(t_data *data)
{
	if (data->ray.side == 0 && data->ray.ray_dir.x < 0)
		return (NO);
	else if (data->ray.side == 0 && data->ray.ray_dir.x > 0)
		return (SO);
	else if (data->ray.side == 1 && data->ray.ray_dir.y < 0)
		return (WE);
	else if (data->ray.side == 1 && data->ray.ray_dir.y > 0)
		return (EA);
	return (0);
}

void	set_vector_d(t_vector_d *vector, double x, double y)
{
	vector->x = x;
	vector->y = y;
}

void	set_vector_i(t_vector_i *vector, int x, int y)
{
	vector->x = x;
	vector->y = y;
}

void	rotate_vector(t_vector_d *vector, double rotspeed)
{
	double	old_x;

	old_x = vector->x;
	vector->x = vector->x * cos(rotspeed) - vector->y * sin(rotspeed);
	vector->y = old_x * sin(rotspeed) + vector->y * cos(rotspeed);
}
