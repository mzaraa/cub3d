#include "cub3d.h"
// check for each '0' if it's near outside of the map, if it is, it's not closed
void	check_map_closed(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
			printf("%s\n", data->map[i]);
		while (data->map[i][j])
		{
			if (data->map[i][j] == '0')
			{
				if ((i - 1) < 0 || (i + 1) > ft_lstsize(data->map_list) || \
					(j - 1) < 0 || (j + 1) > (int)ft_strlen(data->map[i]) || \
					!data->map[i - 1][j] || !data->map[i + 1][j] || \
					!data->map[i][j - 1] || !data->map[i][j + 1])
				{
					free(data->map);
					data->map = NULL;
					printf("Error\nMap not closed\n");
					ft_exit_program(data);
				}
			}
			j++;
		}
		i++;
	}
}

void	check_pos_player(t_data *data)
{
	size_t	i;
	size_t	j;
	int		count;

	i = 0;
	count = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{

			if (ft_strchr("NSEW" , data->map[i][j]))
			{
				data->player_pos_x = j;
				data->player_pos_y = i;
				data->player_dir = data->map[i][j];
				count++;
			}
			j++;
		}
		i++;
	}
	if (count != 1)
	{
		free(data->map);
		data->map = NULL;
		printf("Error\nmultiple player position\n");
		ft_exit_program(data);
	}
}

void	fill_map(t_data *data)
{
	t_list	*tmp;
	size_t	i;

	tmp = data->map_list;
	data->map = (char **)malloc(sizeof(char *) * (ft_lstsize(data->map_list) + 1));
	i = 0;
	while (tmp)
	{
		data->map[i] = ((char *)tmp->content);
		tmp = tmp->next;
		i++;
	}
	data->map[i] = NULL;
	check_pos_player(data);
	check_map_closed(data);
}