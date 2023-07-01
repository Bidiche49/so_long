/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntardy <ntardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:21:44 by ntardy            #+#    #+#             */
/*   Updated: 2023/01/19 22:32:59 by ntardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*loop_check_len(t_map_content *map_content, int fd, char *line)
{
	int		len_comp;

	while (map_content->lenght > 0)
	{
		line = get_next_line(fd);
		len_comp = ft_strlen(line);
		free(line);
		if (map_content->lenght != len_comp)
		{
			if (line == NULL)
				break ;
			close(fd);
			return (", map is not a square or malloc KO");
		}
		map_content->height++;
	}
	free(line);
	close(fd);
	return (NULL);
}

char	*ft_check_len(t_map_content *map_content)
{
	int		fd;
	char	*line;

	fd = open(map_content->path_map, __O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		return (", path is a directory");
	}
	fd = open(map_content->path_map, O_RDONLY);
	if (fd == -1)
		return (", invalid path");
	line = get_next_line(fd);
	if (line == NULL)
	{
		free(line);
		close(fd);
		return (", malloc KO");
	}
	map_content->lenght = ft_strlen(line);
	free (line);
	map_content->height = 1;
	return (loop_check_len(map_content, fd, line));
}
