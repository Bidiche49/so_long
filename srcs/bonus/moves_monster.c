/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_monster.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntardy <ntardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:38:31 by ntardy            #+#    #+#             */
/*   Updated: 2023/01/19 20:25:22 by ntardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	monster_up(t_element *ennemy, char **map)
{
	if (map[ennemy->pos_y - 1][ennemy->pos_x] == '0')
	{
		map[ennemy->pos_y][ennemy->pos_x] = '0';
		map[ennemy->pos_y - 1][ennemy->pos_x] = 'M';
		ennemy->pos_y -= 1;
	}
}

void	monster_right(t_element *ennemy, char **map)
{
	if (map[ennemy->pos_y][ennemy->pos_x + 1] == '0')
	{
		map[ennemy->pos_y][ennemy->pos_x] = '0';
		map[ennemy->pos_y][ennemy->pos_x + 1] = 'M';
		ennemy->pos_x += 1;
	}
}

void	monster_down(t_element *ennemy, char **map)
{
	if (map[ennemy->pos_y + 1][ennemy->pos_x] == '0')
	{
		map[ennemy->pos_y][ennemy->pos_x] = '0';
		map[ennemy->pos_y + 1][ennemy->pos_x] = 'M';
		ennemy->pos_y += 1;
	}
}

void	monster_left(t_element *ennemy, char **map)
{
	if (map[ennemy->pos_y][ennemy->pos_x - 1] == '0')
	{
		map[ennemy->pos_y][ennemy->pos_x] = '0';
		map[ennemy->pos_y][ennemy->pos_x - 1] = 'M';
		ennemy->pos_x -= 1;
	}
}

void	monster_move(t_data *data)
{
	int			rd;
	int			i;
	t_element	*ennemy;

	i = 0;
	ennemy = data->ennemy;
	while (i++ < data->map_content.monster)
	{
		rd = rand() % 4;
		if (rd == 0)
			monster_up(ennemy, data->map_content.map);
		if (rd == 1)
			monster_right(ennemy, data->map_content.map);
		if (rd == 2)
			monster_down(ennemy, data->map_content.map);
		if (rd == 3)
			monster_left(ennemy, data->map_content.map);
		ennemy = ennemy->next;
	}
}
