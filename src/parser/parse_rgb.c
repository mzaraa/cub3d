/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:11:39 by mzaraa            #+#    #+#             */
/*   Updated: 2023/01/16 17:03:55 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_rgb_value(t_data *data, char **rgb)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (rgb[i] && data->flag_error == 0)
	{
		if (ft_strlen(rgb[i]) > 3)
			return (1);
		j = 0;
		while (rgb[i][j])
		{
			if (!ft_isdigit(rgb[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/*
**	Parse the rgb values from the line+1 (to skip the identifier) and split it
**	into an array of strings. Check if the array size is 3 or more and if the 
**	values are digits. If not, free the array and the line and exit the program.
*/
char	**parse_rgb(t_data *data, char *line)
{
	int		i;
	int		j;
	char	**rgb;

	i = 0;
	j = 0;
	rgb = ft_split(line + 1, ", ");
	if (rgb == NULL || ft_split_len(rgb) != 3)
		data->flag_error = 1;
	if (data->flag_error || check_rgb_value(data, rgb))
	{
		if (*rgb)
			free(rgb);
		free(line);
		ft_exit_program(data);
	}
	return (rgb);
}
