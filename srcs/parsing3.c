/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntardy <ntardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:31:42 by ntardy            #+#    #+#             */
/*   Updated: 2023/01/18 15:34:45 by ntardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*check_ber(char *path)
{
	int	i;

	i = 0;
	while (path[i + 4])
		i++;
	if (path[i] != '.' || path[i + 1] != 'b'
		|| path[i + 2] != 'e' || path[i + 3] != 'r')
		return (", map must be .ber file");
	return (NULL);
}

int	wall_height(char **map, int i)
{
	int	j;

	j = 0;
	if (map[i][j] != '1')
		return (0);
	while (map[i][j + 1])
		j++;
	if (map[i][j] != '1')
		return (0);
	return (1);
}

int	check_wall(t_map_content *map_content)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (map_content->map[i][++j])
		if (map_content->map[i][j] != '1')
			return (0);
	while (i + 1 < map_content->height)
		if (!wall_height(map_content->map, ++i))
			return (0);
	j = -1;
	while (map_content->map[i][++j])
		if (map_content->map[i][j] != '1')
			return (0);
	return (1);
}
