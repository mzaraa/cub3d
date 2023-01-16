/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:52:19 by mzaraa            #+#    #+#             */
/*   Updated: 2023/01/16 17:57:36 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Parse the texture path of the identifier, it check if it's an .xpm file and
** if the path is valid
*/
char	*parse_texture(t_data *data, char *line)
{
	char	*temp;
	char	**texture_path;
	size_t	line_size;

	temp = (line + 2);
	texture_path = ft_split(temp, " \n\t\v\f\r");
	if (texture_path == NULL || ft_split_len(texture_path) != 1)
		data->flag_error = 1;
	line_size = ft_strlen(temp);
	if (data->flag_error || ft_strncmp(temp + line_size - 4, ".xpm", 4) != 0)
	{
		if (*texture_path)
			free(texture_path);
		free(line);
		ft_exit_program(data);
	}
	return (*texture_path);
}
