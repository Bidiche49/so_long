/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntardy <ntardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:54:32 by ntardy            #+#    #+#             */
/*   Updated: 2023/01/19 21:44:01 by ntardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_content(t_map_content *map_content, char *path)
{
	map_content->wall = 0;
	map_content->item = 0;
	map_content->exit = 0;
	map_content->player = 0;
	map_content->lenght = 0;
	map_content->height = 2;
	map_content->path_map = path;
	map_content->monster = 0;
	map_content->map = NULL;
}

void	ft_init_ptr(t_ptr *ptr)
{
	ptr->mlx = NULL;
	ptr->win = NULL;
}

void	ft_init_images(t_images *images)
{
	images->ennemy_1 = NULL;
	images->ennemy_2 = NULL;
	images->key_1 = NULL;
	images->floor = NULL;
	images->lava = NULL;
	images->lock_door = NULL;
	images->player_1 = NULL;
	images->player_2 = NULL;
	images->unlock_door = NULL;
}

void	ft_init_data(t_data *data, char *path)
{
	ft_init_content(&data->map_content, path);
	ft_init_ptr(&data->ptr);
	ft_init_images(&data->images);
	data->player.str_moves = NULL;
	data->ennemy = NULL;
	data->count = 0;
	data->player.nb_moves = 0;
}
