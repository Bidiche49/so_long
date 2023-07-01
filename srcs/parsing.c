/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntardy <ntardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 19:13:17 by ntardy            #+#    #+#             */
/*   Updated: 2023/01/19 20:12:29 by ntardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	return_double(t_map_content *map_content)
{
	if (map_content->exit > 1 || map_content->player > 1)
		return (3);
	if (map_content->item < 1 || map_content->exit < 1
		|| map_content->player < 1)
		return (4);
	return (1);
}

int	if_forest_parsing(t_data *data, t_map_content *map_content, int x, int y)
{
	(void)data;
	if (map_content->map[y][x] != '1' && map_content->map[y][x] != '0'
		&& map_content->map[y][x] != 'C' && map_content->map[y][x] != 'P'
		&& map_content->map[y][x] != 'E')
		return (2);
	if (map_content->map[y][x] == '1')
		map_content->wall++;
	else if (map_content->map[y][x] == 'C')
		map_content->item++;
	else if (map_content->map[y][x] == 'P')
		map_content->player++;
	else if (map_content->map[y][x] == 'E')
		map_content->exit++;
	return (0);
}

int	ft_check_double(t_map_content *map_content, t_data *data, int y, int x)
{
	y = 0;
	while (y < map_content->height)
	{
		x = 0;
		while (map_content->map[y][x] && map_content->map[y][x] != '\n')
		{
			if (if_forest_parsing(data, map_content, x, y) == 2)
				return (2);
			x++;
		}
		y++;
	}
	return (return_double(map_content));
}

char	*ft_parsing(t_data *data)
{
	int	error;
	int	y;
	int	x;

	y = 0;
	x = 0;
	error = ft_check_double(&data->map_content, data, y, x);
	if (error == 2)
		return (", map contains forbidden char");
	if (error == 3)
		return (", map contains duplicates");
	if (error == 4)
		return (", map not completed");
	if (!check_wall(&data->map_content))
		return (" not enought walls");
	else
		return (NULL);
}
