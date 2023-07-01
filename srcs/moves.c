/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntardy <ntardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:17:01 by ntardy            #+#    #+#             */
/*   Updated: 2023/01/19 22:33:11 by ntardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_data *data)
{
	char	**map;
	int		y;
	int		x;

	y = data->player.pos_y;
	x = data->player.pos_x;
	map = data->map_content.map;
	if (map[y - 1][x] == '0' || map[y - 1][x] == 'C')
	{
		data->player.nb_moves += 1;
		if (map[y - 1][x] == 'C')
			data->map_content.item -= 1;
		map[y][x] = '0';
		map[y - 1][x] = 'P';
		data->player.pos_y -= 1;
		print_move_count(data);
	}
	else if ((map[y - 1][x] == 'E'
		&& data->map_content.item == 0))
		exit_game_win(data);
	fill_window(data);
}

void	move_right(t_data *data)
{
	char	**map;
	int		y;
	int		x;

	y = data->player.pos_y;
	x = data->player.pos_x;
	map = data->map_content.map;
	if (map[y][x + 1] == '0' || map[y][x + 1] == 'C')
	{
		data->player.nb_moves += 1;
		if (map[y][x + 1] == 'C')
			data->map_content.item -= 1;
		map[y][x] = '0';
		map[y][x + 1] = 'P';
		data->player.pos_x += 1;
		print_move_count(data);
	}
	else if ((map[y][x + 1] == 'E'
		&& data->map_content.item == 0))
		exit_game_win(data);
	fill_window(data);
}

void	move_down(t_data *data)
{
	char	**map;
	int		y;
	int		x;

	y = data->player.pos_y;
	x = data->player.pos_x;
	map = data->map_content.map;
	if (map[y + 1][x] == '0' || map[y + 1][x] == 'C')
	{
		data->player.nb_moves += 1;
		if (map[y + 1][x] == 'C')
			data->map_content.item -= 1;
		map[y][x] = '0';
		map[y + 1][x] = 'P';
		data->player.pos_y += 1;
		print_move_count(data);
	}
	else if ((map[y + 1][x] == 'E'
		&& data->map_content.item == 0))
		exit_game_win(data);
	fill_window(data);
}

void	move_left(t_data *data)
{
	char	**map;
	int		y;
	int		x;

	y = data->player.pos_y;
	x = data->player.pos_x;
	map = data->map_content.map;
	if (map[y][x - 1] == '0' || map[y][x - 1] == 'C')
	{
		data->player.nb_moves += 1;
		if (map[y][x - 1] == 'C')
			data->map_content.item -= 1;
		map[y][x] = '0';
		map[y][x - 1] = 'P';
		data->player.pos_x -= 1;
		print_move_count(data);
	}
	else if ((map[y][x - 1] == 'E'
		&& data->map_content.item == 0))
		exit_game_win(data);
	fill_window(data);
}

void	print_move_count(t_data *data)
{
	if (data->player.str_moves != NULL)
		free(data->player.str_moves);
	data->player.str_moves = ft_itoa(data->player.nb_moves);
	write(1, data->player.str_moves, ft_strlen(data->player.str_moves));
	write(1, "\n", 1);
}
