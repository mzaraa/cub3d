
#include "cub3d.h"

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
