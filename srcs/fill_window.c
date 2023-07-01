/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntardy <ntardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:37:16 by ntardy            #+#    #+#             */
/*   Updated: 2023/01/19 22:24:05 by ntardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	if_forest(t_data *data, int x, int y)
{
	if (data->map_content.map[y][x] == '1')
		mlx_put_image_to_window(data->ptr.mlx,
			data->ptr.win, data->images.lava, x * 64, y * 64);
	if (data->map_content.map[y][x] == '0')
		mlx_put_image_to_window(data->ptr.mlx,
			data->ptr.win, data->images.floor, x * 64, y * 64);
	if (data->map_content.map[y][x] == 'C')
		mlx_put_image_to_window(data->ptr.mlx,
			data->ptr.win, data->images.key_1, x * 64, y * 64);
	if (data->map_content.map[y][x] == 'P')
		mlx_put_image_to_window(data->ptr.mlx,
			data->ptr.win, data->images.player_1, x * 64, y * 64);
	if (data->map_content.map[y][x] == 'E' && data->map_content.item > 0)
		mlx_put_image_to_window(data->ptr.mlx,
			data->ptr.win, data->images.lock_door, x * 64, y * 64);
	else if (data->map_content.map[y][x] == 'E')
		mlx_put_image_to_window(data->ptr.mlx,
			data->ptr.win, data->images.unlock_door, x * 64, y * 64);
}

int	fill_window(t_data *data)
{
	int		x;
	int		y;

	y = -1;
	if (data->player.str_moves != NULL)
		free(data->player.str_moves);
	data->player.str_moves = ft_itoa(data->player.nb_moves);
	while (++y < data->map_content.height)
	{
		x = -1;
		while (++x < data->map_content.lenght)
			if_forest(data, x, y);
	}
	return (1);
}
