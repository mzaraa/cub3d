/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_program.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:51:47 by mzaraa            #+#    #+#             */
/*   Updated: 2023/01/16 18:01:00 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// todo : free all the data
void	ft_exit_program(t_data *data)
{
	(void)data;
	if (data->id_tab)
		free(data->id_tab);
	printf("Exiting program");
	exit(0);
}
