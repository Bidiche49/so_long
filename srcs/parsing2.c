/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntardy <ntardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 21:07:02 by ntardy            #+#    #+#             */
/*   Updated: 2023/01/19 18:15:46 by ntardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_exit(char **map_tmp, int y, int x)
{
	if (map_tmp[y][x] == '1')
		return (0);
	map_tmp[y][x] = '1';
	if (map_tmp[y + 1][x] == 'E' || map_tmp[y][x + 1] == 'E' ||
		map_tmp[y - 1][x] == 'E' || map_tmp[y][x - 1] == 'E')
		return (1);
	if ((map_tmp[y + 1][x] != '1' && check_exit(map_tmp, y + 1, x)) ||
		(map_tmp[y][x + 1] != '1' && check_exit(map_tmp, y, x + 1)) ||
		(map_tmp[y - 1][x] != '1' && check_exit(map_tmp, y - 1, x)) ||
		(map_tmp[y][x - 1] != '1' && check_exit(map_tmp, y, x - 1)))
		return (1);
	return (0);
}

int	check_collectible(char **map_tmp, int y, int x)
{
	int	count;

	count = 0;
	if (map_tmp[y][x] == '1' || map_tmp[y][x] == 'E')
		return (0);
	if (map_tmp[y][x] == 'C')
		count++;
	map_tmp[y][x] = '1';
	if (map_tmp[y + 1][x] == '0' || map_tmp[y + 1][x] == 'C')
		count += check_collectible(map_tmp, y + 1, x);
	if (map_tmp[y][x + 1] == '0' || map_tmp[y][x + 1] == 'C')
		count += check_collectible(map_tmp, y, x + 1);
	if (map_tmp[y - 1][x] == '0' || map_tmp[y - 1][x] == 'C')
		count += check_collectible(map_tmp, y - 1, x);
	if (map_tmp[y][x - 1] == '0' || map_tmp[y][x - 1] == 'C')
		count += check_collectible(map_tmp, y, x - 1);
	return (count);
}

int	check_exit_colectible(t_data *data
	, char **map_tmp)
{
	if (!check_exit(map_tmp, data->player.pos_y, data->player.pos_x))
		return (error_map(data, map_tmp, ", exit impossible to reach"));
	ft_free_map_tmp(map_tmp);
	map_tmp = fill_map_tmp(&data->map_content);
	if (!map_tmp)
		return (error_map(data, map_tmp, ", malloc KO"));
	if (check_collectible(map_tmp,
			data->player.pos_y, data->player.pos_x) != data->map_content.item)
		return (error_map(data, map_tmp,
				", some collectibles impossible to reach"));
	ft_free_map_tmp(map_tmp);
	return (1);
}

int	check_map_doable(t_data *data)
{
	char	**map_tmp;

	data->player.pos_x = 0;
	map_tmp = fill_map_tmp(&data->map_content);
	if (!map_tmp)
		return (error_map(data, map_tmp, ", malloc KO"));
	data->player.pos_y = -1;
	while (map_tmp[++data->player.pos_y])
	{
		data->player.pos_x = -1;
		while (map_tmp[data->player.pos_y][++data->player.pos_x])
			if (map_tmp[data->player.pos_y][data->player.pos_x] == 'P')
				break ;
		if (map_tmp[data->player.pos_y][data->player.pos_x] == 'P')
			break ;
	}
	return (check_exit_colectible(data, map_tmp));
}
