#include "cub3d.h"

void set_img(t_data *data)
{
    data->mlximg[0].img = mlx_xpm_file_to_image(data->mlx, "/Users/PietriniGlenn/Desktop/cub3d/xpm/mur.xpm", &data->map_width, &data->map_height);
    data->mlximg[0].img_str = mlx_get_data_addr(data->mlximg[0].img, &data->mlximg[0].bits_per_pixel, &data->mlximg[0].line_length, &data->mlximg[0].endian);
}

void get_texture(t_data *data)
{
    int x;
    int y;
    int i;
    int j;

    x = 0;
    y = 0;
    i = 0;
    j = 0;
    while (y < (int)ft_lstsize(data->map_list))
    {
        while (x < (int)data->longest_line)
        {
            if (data->map[i][j] == '1')
            {
              mlx_put_image_to_window(data->mlx, data->win, data->mlximg[0].img, i * 30, j * 30);     
            }
            x++;
            j++;
        }


        x = 0;
        j = 0;
        y++;
        i++;
    }



}


void	run_game(t_data *data)
{

    data->mlx = mlx_init();
    data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Cub3D");
    data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
    data->img_str = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
    set_img(data);
    get_texture(data);
    //mlx_hook(data->game->win, 2, 1L<<0, key_press, data);
    //mlx_hook(data->game->win, 3, 1L<<1, key_release, data);
    mlx_hook(data->win, 17, 1L<<17, ft_exit_program, data);
    //mlx_loop_hook(data->mlx, main_loop, data);
    mlx_loop(data->mlx);
    
}

