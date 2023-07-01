/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntardy <ntardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:54:03 by ntardy            #+#    #+#             */
/*   Updated: 2023/01/19 20:31:39 by ntardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	animation_ennemy(t_data *data, t_element **ennemy)
{
	int			i;
	t_element	*tmp_ennemy;

	i = 0;
	tmp_ennemy = *ennemy;
	while (i < data->map_content.monster)
	{
		if (data->count <= 3300)
			mlx_put_image_to_window(data->ptr.mlx, data->ptr.win,
				data->images.ennemy_1, tmp_ennemy->pos_x * 64,
				tmp_ennemy->pos_y * 64);
		else if (data->count > 3300)
			mlx_put_image_to_window(data->ptr.mlx, data->ptr.win,
				data->images.ennemy_2, tmp_ennemy->pos_x * 64,
				tmp_ennemy->pos_y * 64);
		if (data->count == 10000)
			data->count = 0;
		i++;
		tmp_ennemy = tmp_ennemy->next;
	}
	return (0);
}

int	animation_player(t_data *data)
{
	if (data->count <= 5000)
		mlx_put_image_to_window(data->ptr.mlx, data->ptr.win,
			data->images.player_1, data->player.pos_x * 64,
			data->player.pos_y * 64);
	else if (data->count > 5000)
		mlx_put_image_to_window(data->ptr.mlx, data->ptr.win,
			data->images.player_2, data->player.pos_x * 64,
			data->player.pos_y * 64);
	if (data->count == 10000)
		data->count = 0;
	return (0);
}

int	animation(t_data *data)
{
	animation_ennemy(data, &data->ennemy);
	animation_player(data);
	data->count++;
	return (0);
}
