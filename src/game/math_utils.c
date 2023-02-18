
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
	return (EA);
}

void set_vector_d(t_vector_d *vector, double x, double y)
{
	vector->x = x;
	vector->y = y;
}

void set_vector_i(t_vector_i *vector, int x, int y)
{
	vector->x = x;
	vector->y = y;
}

void rotate_vector(t_vector_d *vector, double rotspeed)
{
	double old_x;

	old_x = vector->x;
	vector->x = vector->x * cos(rotspeed) - vector->y * sin(rotspeed);
	vector->y = old_x * sin(rotspeed) + vector->y * cos(rotspeed);
}
