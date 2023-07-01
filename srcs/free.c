/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntardy <ntardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:25:17 by ntardy            #+#    #+#             */
/*   Updated: 2023/01/19 19:42:23 by ntardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_map_tmp(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
		free(map[i++]);
	free(map);
}

void	ft_free_map(t_map_content *map_content)
{
	int	i;

	i = 0;
	if (!map_content->map)
		return ;
	while (i < map_content->height)
		free(map_content->map[i++]);
	free(map_content->map);
}

void	ft_free_image(t_data *data)
{
	if (data->images.ennemy_1 != NULL)
		mlx_destroy_image(data->ptr.mlx, data->images.ennemy_1);
	if (data->images.ennemy_2 != NULL)
		mlx_destroy_image(data->ptr.mlx, data->images.ennemy_2);
	if (data->images.player_1 != NULL)
		mlx_destroy_image(data->ptr.mlx, data->images.player_1);
	if (data->images.player_2 != NULL)
		mlx_destroy_image(data->ptr.mlx, data->images.player_2);
	if (data->images.key_1 != NULL)
		mlx_destroy_image(data->ptr.mlx, data->images.key_1);
	if (data->images.unlock_door != NULL)
		mlx_destroy_image(data->ptr.mlx, data->images.unlock_door);
	if (data->images.lock_door != NULL)
		mlx_destroy_image(data->ptr.mlx, data->images.lock_door);
	if (data->images.lava != NULL)
		mlx_destroy_image(data->ptr.mlx, data->images.lava);
	if (data->images.floor != NULL)
		mlx_destroy_image(data->ptr.mlx, data->images.floor);
}

void	ft_free_element(t_element *element)
{
	t_element	*to_del;

	if (!element)
		return ;
	while (element)
	{
		if (element && element->next)
		{
			to_del = element;
			element = element->next;
			free(to_del);
		}
		else
		{
			free(element);
			element = NULL;
		}
	}
	return ;
}

void	ft_free(t_data *data)
{
	ft_free_map(&data->map_content);
	ft_free_image(data);
	ft_free_element(data->ennemy);
	free(data->player.str_moves);
	if (data->ptr.win != NULL)
		mlx_destroy_window(data->ptr.mlx, data->ptr.win);
	if (data->ptr.mlx != NULL)
	{
		mlx_destroy_display(data->ptr.mlx);
		free(data->ptr.mlx);
	}
	ft_init_data(data, NULL);
}
