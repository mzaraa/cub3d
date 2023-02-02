#include "cub3d.h"

static int	main_loop(t_data *data)
{
    mlx_put_image_to_window(data->game->mlx, data->game->win, data->mlximg->ptr, 0, 0);
    return (0);
}

t_mlximg    *creat_img(void *mlx, int width, int height)
{
    t_mlximg	*img;

    img->ptr = mlx_new_image(mlx, width, height);
    img->addr = mlx_get_data_addr(img->ptr, &img->bits_per_pixel, &img->line_length, &img->endian);
    return (img);
}

void	run_game(t_data *data)
{
    data->game->mlx = mlx_init();
    data->game->win = mlx_new_window(data->game->mlx, WIDTH, HEIGHT, "Cub3D");
    data->mlximg = creat_img(data->game->mlx, WIDTH, HEIGHT);
    mlx_put_image_to_window(data->game->mlx, data->game->win, data->mlximg->ptr, 0, 0);

    //mlx_hook(data->game->win, 3, 0, &key_release, &info);
    //mlx_hook(data->game->win, 17, 0, &exit_game, &info);
    mlx_loop_hook(data->game->mlx, main_loop, &data);
    //mlx_hook(data->game->win, 2, 0, &key_press, &info);
    mlx_loop(data->game->mlx);
}

