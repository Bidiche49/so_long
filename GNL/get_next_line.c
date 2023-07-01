/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntardy <ntardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 18:10:38 by ntardy            #+#    #+#             */
/*   Updated: 2023/01/19 21:36:29 by ntardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#define BUFFER_SIZE 5

static int	ft_is_bn(char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_save_buff(char *buff)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!buff)
		return (NULL);
	while (buff[i] && buff[i - 1] != '\n')
		i++;
	while (buff[i])
		buff[j++] = buff[i++];
	buff[j] = '\0';
	return (buff);
}

static char	*ft_read_line(int fd, int res_read, char *buff, char *next_line)
{
	while (res_read > 0)
	{
		res_read = read(fd, buff, BUFFER_SIZE);
		if (res_read == -1)
			return (NULL);
		buff[res_read] = '\0';
		if (ft_is_bn(buff))
		{
			next_line = ft_strcat_remake(next_line, buff);
			ft_save_buff(buff);
			return (next_line);
		}
		next_line = ft_strcat_remake(next_line, buff);
	}
	if (res_read < BUFFER_SIZE)
		buff[0] = '\0';
	return (next_line);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*next_line;
	int			res_read;

	res_read = 1;
	next_line = NULL;
	if (*buff)
	{
		next_line = ft_strdup_remake(buff, '\n');
		if (ft_is_bn(next_line))
		{
			ft_save_buff(buff);
			return (next_line);
		}
	}
	next_line = ft_read_line(fd, res_read, buff, next_line);
	if (!next_line)
		return (NULL);
	if (next_line[0] == '\0')
	{
		free(next_line);
		return (NULL);
	}
	return (next_line);
}

// int main(int argc, char **argv)
// {
// 	int		fd;
// 	char	*str;

// 	if (argc != 2)
// 		return (0);
// 	fd = open(argv[1], O_RDONLY);
// 	str = malloc(sizeof(char) * printf("%s", get_next_line(fd)));
// 	// while (str)
// 	// {
// 	// 	str = get_next_line(fd);
// 	// 	if (str)
// 	// 		printf("%s", str);
// 	// }
// 	// printf("%s", get_next_line(fd));

// 	close (fd);
// 	return (0);
// }
