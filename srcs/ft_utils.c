/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntardy <ntardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:55:55 by ntardy            #+#    #+#             */
/*   Updated: 2023/01/19 22:32:17 by ntardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	unsigned int	i;
	char			*str;

	i = -1;
	str = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (str == NULL)
		return (NULL);
	while (src[++i])
		str[i] = src[i];
	str[i] = '\0';
	return (str);
}

int	exit_game(t_data *data)
{
	ft_free(data);
	exit (1);
}

int	exit_game_win(t_data *data)
{
	write(1, "GAME WIN in ", 12);
	data->player.nb_moves++;
	if (data->player.str_moves != NULL)
		free(data->player.str_moves);
	data->player.str_moves = ft_itoa(data->player.nb_moves);
	write(1, data->player.str_moves, ft_strlen(data->player.str_moves));
	write(1, " moves\n", 7);
	ft_free(data);
	exit (0);
}

int	exit_game_over(t_data *data)
{
	write(1, "GAME OVER !!\n", 13);
	ft_free(data);
	exit (0);
}
