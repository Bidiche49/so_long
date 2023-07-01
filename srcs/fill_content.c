/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_content.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntardy <ntardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 19:21:06 by ntardy            #+#    #+#             */
/*   Updated: 2023/01/19 22:13:16 by ntardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_fill_map(t_data *data)
{
	int		fd;
	int		y;
	char	*error;

	error = ft_check_len(&data->map_content);
	if (error != NULL)
		return (error);
	data->map_content.map = malloc(sizeof(char *)
			* (data->map_content.height + 1));
	if (data->map_content.map == NULL)
		return (", malloc KO");
	fd = open(data->map_content.path_map, O_RDONLY);
	y = -1;
	while (++y < data->map_content.height)
	{
		data->map_content.map[y] = get_next_line(fd);
		if (data->map_content.map[y] == NULL)
		{
			close(fd);
			return (", malloc KO");
		}
	}
	close(fd);
	return (error);
}

char	**fill_map_tmp(t_map_content *map_content)
{
	char	**map_tmp;
	int		i;

	map_tmp = malloc(sizeof(char *) * (map_content->height + 1));
	if (!map_tmp)
		return (NULL);
	i = -1;
	while (++i < map_content->height)
	{
		map_tmp[i] = ft_strdup(map_content->map[i]);
		if (!map_tmp[i])
			return (NULL);
	}
	map_tmp[i] = NULL;
	return (map_tmp);
}

void	fill_element(t_data *data, t_element **element, int y, int x)
{
	t_element	*new_element;
	t_element	*actu;

	new_element = malloc(sizeof(t_element));
	if (new_element == NULL)
		error_malloc(data);
	new_element->pos_y = y;
	new_element->pos_x = x;
	new_element->next = NULL;
	data->map_content.monster++;
	if (*element == NULL)
	{
		*element = new_element;
		return ;
	}
	actu = *element;
	while (actu->next != NULL)
		actu = actu->next;
	actu->next = new_element;
}
