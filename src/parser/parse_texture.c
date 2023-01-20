/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:52:19 by mzaraa            #+#    #+#             */
/*   Updated: 2023/01/20 15:52:54 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Parse the texture path of the identifier, it check if it's an .xpm file and
** if the path is valid
*/
char	*parse_tex(t_data *data, char *line)
{
	char	*temp;
	char	**texture_path;
	char	*texture;

	temp = (line + 2);
	texture_path = ft_split(temp, WHITESPACE);
	if (texture_path == NULL || ft_split_len(texture_path) != 1)
		data->flag_error = 1;
	if (data->flag_error || ft_strncmp(*texture_path + \
		(ft_strlen(*texture_path) - 4), ".xpm", 4) != 0)
	{
		printf("Error\nTexture path invalid\n");
		ft_free_split(texture_path);
		free(line);
		ft_exit_program(data);
	}
	texture = ft_strdup(*texture_path);
	ft_free_split(texture_path);
	return (texture);
}
