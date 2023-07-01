/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntardy <ntardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:09:37 by ntardy            #+#    #+#             */
/*   Updated: 2023/01/19 23:02:48 by ntardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define PATH_PLAYER_1 "srcs/images/player_1.xpm"
# define PATH_PLAYER_2 "srcs/images/player_2.xpm"
# define PATH_ENNEMY_1 "srcs/images/ennemy_1.xpm"
# define PATH_ENNEMY_2 "srcs/images/ennemy_2.xpm"
# define PATH_KEY_1 "srcs/images/key_1.xpm"
# define PATH_LOCK_DOOR "srcs/images/door_locked.xpm"
# define PATH_UNLOCK_DOOR "srcs/images/door_unlock.xpm"
# define PATH_LAVA "srcs/images/lava.xpm"
# define PATH_FLOOR "srcs/images/floor.xpm"

# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../GNL/get_next_line.h"
# include "../minilibx-linux/mlx.h"

/******************************************/
/*                STRUCTS                 */
/******************************************/

typedef struct s_ptr
{
	void	*mlx;
	void	*win;
}				t_ptr;

typedef struct s_images
{
	void	*player_1;
	void	*player_2;
	void	*ennemy_1;
	void	*ennemy_2;
	void	*key_1;
	void	*lock_door;
	void	*unlock_door;
	void	*floor;
	void	*lava;
}				t_images;

typedef struct s_map_content
{
	int				wall;
	int				item;
	int				exit;
	int				player;
	int				monster;
	int				lenght;
	int				height;
	char			*path_map;
	char			**map;
}				t_map_content;

typedef struct s_player
{
	int		pos_x;
	int		pos_y;
	int		nb_moves;
	char	*str_moves;
}				t_player;

typedef struct s_element
{
	int					pos_x;
	int					pos_y;
	struct s_element	*next;
}				t_element;

typedef struct s_data
{
	int				count;
	t_ptr			ptr;
	t_map_content	map_content;
	t_images		images;
	t_player		player;
	t_element		*ennemy;
}				t_data;

/******************************************/
/*                                        */
/*               Fonctions                */
/*                                        */
/******************************************/

/*********************************/
/*            Parsing            */
/*********************************/
char	*ft_parsing(t_data *data);
char	*check_ber(char *path);
char	*ft_check_len(t_map_content *map_content);
int		check_map_doable(t_data *data);
int		check_wall(t_map_content *map_content);

/*********************************/
/*           fill/init           */
/*********************************/
char	**fill_map_tmp(t_map_content *map_content);
char	*ft_fill_map(t_data *data);
void	ft_init_content(t_map_content *map_content, char *path);
void	ft_init_data(t_data *data, char *path);
void	ft_init_ptr(t_ptr *ptr);
void	fill_element(t_data *data, t_element **element, int y, int x);
int		fill_images(t_data *data);
int		fill_window(t_data *data);

/*********************************/
/*             moves             */
/*********************************/
void	move_up(t_data *data);
void	move_right(t_data *data);
void	move_down(t_data *data);
void	move_left(t_data *data);

/*********************************/
/*             utils             */
/*********************************/
char	*ft_strdup(char *src);
char	*ft_check_len(t_map_content *map_content);
int		ft_strlen(char *str);
int		exit_game(t_data *data);
int		exit_game_win(t_data *data);
int		exit_game_over(t_data *data);
void	print_move_count(t_data *data);

/*********************************/
/*            errors             */
/*********************************/
int		error_map(t_data *data, char **map_tmp, char *error_str);
int		error_image(t_data *data);
void	error_malloc(t_data *data);

/*********************************/
/*             frees             */
/*********************************/
void	ft_free_map(t_map_content *map_content);
void	ft_free_map_tmp(char **map);
void	ft_free_image(t_data *data);
void	ft_free(t_data *data);

/*********************************/
/*             bonus             */
/*********************************/
int		animation(t_data *data);
void	monster_move(t_data *data);
char	*ft_itoa(int n);

#endif
