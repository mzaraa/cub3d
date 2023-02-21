/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:30:36 by mzaraa            #+#    #+#             */
/*   Updated: 2023/02/21 12:23:21 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

void	render_rays(t_data *data, t_point from, t_point to, int color)
{
	double	x_incr;
	double	y_incr;
	int		steps;

	if ((from.x < 0 || from.x >= WIDTH || from.y < 0 || from.y >= HEIGHT)
		&& (to.x < 0 || to.x >= WIDTH || to.y < 0 || to.y >= HEIGHT))
		return ;
	x_incr = to.x - from.x;
	y_incr = to.y - from.y;
	steps = max_of(ceil(fabs(x_incr)), ceil(fabs(y_incr)));
	x_incr /= steps;
	y_incr /= steps;
	while (1)
	{
		my_pixel_put(&data->img, from.x, from.y, color);
		from.x += x_incr;
		from.y += y_incr;
		if (data->map[(int)from.y / SCALE][(int)from.x / SCALE] == '1')
			break ;
		if (from.x < 0 || from.x >= WIDTH || from.y < 0 || from.y >= HEIGHT)
			break ;
		// if (sqrt(pow(from.x - data->player.pos.x * SCALE, 2) + pow(from.y - data->player.pos.y * SCALE, 2)) > 50)
		// 	break ;
	}
}

void draw_map(t_data *data)
{
	int i;
	int j;
	int color;

	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			if (data->map[i][j] == '1')
				color = GREY_PIXEL;
			else
				color = WHITE_PIXEL;
			render_rectangle(&data->img, (t_rect){j * SCALE, i * SCALE, SCALE, SCALE, color});
			++j;
		}
		++i;
	}
}

void draw_rays(t_data *data)
{
	int i;
	int color;

	i = 0;
	color = RED_PIXEL;
	while (i < WIDTH)
	{
		render_rays(data, (t_point){data->player.pos.x * SCALE, \
			data->player.pos.y * SCALE}, \
			(t_point){data->rays_coords[i].x * SCALE, \
			data->rays_coords[i].y * SCALE}, color);
		++i;
	}
}

void draw_player(t_data *data)
{
	int color;

	color = BLACK_PIXEL;
	render_rectangle(&data->img, (t_rect){data->player.pos.x * SCALE - 2.5, 
		data->player.pos.y * SCALE - 2.5, 5, 5, color});
	render_rays(data, (t_point){data->player.pos.x * SCALE, data->player.pos.y * SCALE},
		(t_point){data->player.pos.x * SCALE + data->player.dir.x * SCALE,
		data->player.pos.y * SCALE + data->player.dir.y * SCALE}, BLACK_PIXEL);
}

void minimap(t_data *data)
{
	draw_map(data);
	draw_rays(data);
	draw_player(data);
}