/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntardy <ntardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:06:28 by ntardy            #+#    #+#             */
/*   Updated: 2023/01/19 22:26:09 by ntardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	deal_key(int key, t_data *data)
{
	if (key == 119)
		move_up(data);
	else if (key == 97)
		move_left(data);
	else if (key == 115)
		move_down(data);
	else if (key == 100)
		move_right(data);
	if (key == 65307)
		exit_game(data);
	return (key);
}

int	full_parsing(t_data *data)
{
	char	*error;

	error = check_ber(data->map_content.path_map);
	if (error != NULL)
		return (error_map(data, NULL, error));
	error = ft_fill_map(data);
	if (error != NULL)
		return (error_map(data, NULL, error));
	if (!data->map_content.map)
		return (error_map(data, NULL, ", fill_map KO"));
	error = ft_parsing(data);
	if (error != NULL)
		return (error_map(data, NULL, error));
	if (check_map_doable(data) != 1)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;

	ft_init_data(&data, argv[1]);
	if (argc != 2)
		return (write(1, "Wrong number of args\n", 21), 1);
	if (full_parsing(&data) != 1)
		return (2);
	data.ptr.mlx = mlx_init();
	if (data.ptr.mlx == NULL)
		return (exit_game(&data));
	data.ptr.win = mlx_new_window(data.ptr.mlx, data.map_content.lenght * 64,
			data.map_content.height * 64, "so_long");
	if (data.ptr.win == NULL)
		return (exit_game(&data));
	mlx_key_hook(data.ptr.win, deal_key, &data);
	mlx_hook(data.ptr.win, 17, 1, exit_game, &data);
	if (fill_images(&data) == 0)
		return (exit_game(&data));
	fill_window(&data);
	mlx_loop(data.ptr.mlx);
	ft_free(&data);
	return (0);
}
