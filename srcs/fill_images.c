/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntardy <ntardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:40:49 by ntardy            #+#    #+#             */
/*   Updated: 2023/01/19 18:06:49 by ntardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	fill_player_ennemy(t_data *data)
{
	int	h_w;

	h_w = 64;
	data->images.player_1
		= mlx_xpm_file_to_image(data->ptr.mlx, PATH_PLAYER_1, &h_w, &h_w);
	data->images.player_2
		= mlx_xpm_file_to_image(data->ptr.mlx, PATH_PLAYER_2, &h_w, &h_w);
	data->images.ennemy_1
		= mlx_xpm_file_to_image(data->ptr.mlx, PATH_ENNEMY_1, &h_w, &h_w);
	data->images.ennemy_2
		= mlx_xpm_file_to_image(data->ptr.mlx, PATH_ENNEMY_2, &h_w, &h_w);
	if (data->images.player_1 == NULL || data->images.player_2 == NULL
		||data->images.ennemy_1 == NULL || data->images.ennemy_2 == NULL)
		return (0);
	return (1);
}

int	fill_key(t_data *data)
{
	int	h_w;

	h_w = 64;
	data->images.key_1
		= mlx_xpm_file_to_image(data->ptr.mlx, PATH_KEY_1, &h_w, &h_w);
	if (data->images.key_1 == NULL)
		return (0);
	return (1);
}

int	fill_door(t_data *data)
{
	int	h_w;

	h_w = 64;
	data->images.unlock_door
		= mlx_xpm_file_to_image(data->ptr.mlx, PATH_UNLOCK_DOOR, &h_w, &h_w);
	data->images.lock_door
		= mlx_xpm_file_to_image(data->ptr.mlx, PATH_LOCK_DOOR, &h_w, &h_w);
	if (data->images.lock_door == NULL)
		return (0);
	return (1);
}

int	fill_background(t_data *data)
{
	int	h_w;

	h_w = 64;
	data->images.lava
		= mlx_xpm_file_to_image(data->ptr.mlx, PATH_LAVA, &h_w, &h_w);
	data->images.floor
		= mlx_xpm_file_to_image(data->ptr.mlx, PATH_FLOOR, &h_w, &h_w);
	if (data->images.lava == NULL || data->images.floor == NULL)
		return (0);
	return (1);
}

int	fill_images(t_data *data)
{
	if (fill_player_ennemy(data) == 0)
		return (error_image(data));
	if (fill_key(data) == 0)
		return (error_image(data));
	if (fill_door(data) == 0)
		return (error_image(data));
	if (fill_background(data) == 0)
		return (error_image(data));
	return (1);
}
