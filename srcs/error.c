/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntardy <ntardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 19:17:51 by ntardy            #+#    #+#             */
/*   Updated: 2023/01/19 22:03:04 by ntardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error_map(t_data *data, char **map_tmp, char *error_str)
{
	if (map_tmp != NULL)
		ft_free_map_tmp(map_tmp);
	ft_free(data);
	write(STDERR_FILENO, "error", 6);
	write(STDERR_FILENO, error_str, ft_strlen(error_str));
	write(STDERR_FILENO, "\n", 1);
	return (0);
}

int	error_image(t_data *data)
{
	ft_free(data);
	write(STDERR_FILENO, "error, one or more images were not converted\n", 45);
	return (0);
}

void	error_malloc(t_data *data)
{
	write(STDERR_FILENO, "error, malloc KO\n", 17);
	exit_game(data);
}
