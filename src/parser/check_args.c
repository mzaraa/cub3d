/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:44:07 by mzaraa            #+#    #+#             */
/*   Updated: 2023/01/11 16:37:38 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Check if the file_name is valid
*/

int	check_file_name(char *file_name)
{
	int	i;

	i = 0;
	while (file_name[i])
		i++;
	if (ft_strcmp(file_name + i - 4, ".cub") == 0)
		return (1);
	return (0);
}
