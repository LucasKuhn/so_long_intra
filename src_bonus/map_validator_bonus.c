/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex-ku <lalex-ku@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 22:02:09 by lalexk-ku         #+#    #+#             */
/*   Updated: 2022/01/31 11:05:20 by lalex-ku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_file(t_game *game)
{
	char	*extension;
	int		fd;

	extension = ft_strrchr(game->map_file, '.');
	if (!extension || ft_strncmp(extension, ".ber", 4) != 0)
		map_error("Map is not a .ber file", game);
	fd = open(game->map_file, O_RDONLY);
	if (fd == -1)
		map_error("Map path is not valid", game);
	close(fd);
}

void	check_walls(t_game *game)
{
	size_t	x;
	size_t	y;
	size_t	width;
	size_t	height;

	y = 0;
	width = ft_strlen(game->map[y]);
	height = ft_arrlen(game->map);
	while (game->map[y])
	{
		x = 0;
		if (ft_strlen(game->map[y]) != width)
			map_error("Map is not rectangular", game);
		while (game->map[y][x])
		{
			if (y == 0 || x == 0 || x == width - 1 || y == height - 1)
			{
				if (game->map[y][x] != '1')
					map_error("Map not surrounded by walls", game);
			}
			x++;
		}
		y++;
	}
}

void	check_characters(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (invalid_character(game->map[y][x]))
				map_error("Map contains an invalid character", game);
			if (game->map[y][x] == 'E')
				game->exit++;
			x++;
		}
		y++;
	}
	if (game->x == 0)
		map_error("Map has no player", game);
	if (game->coins == 0)
		map_error("Map has no coins", game);
	if (game->exit != 1)
		map_error("Map should have one exit", game);
}

void	check_new_lines(t_game *game)
{
	int		fd;
	char	read_buffer[1024];

	fd = open(game->map_file, O_RDONLY);
	if (fd == -1)
		return ;
	ft_bzero(read_buffer, 1024);
	read(fd, read_buffer, 1024);
	close(fd);
	if (ft_strnstr(read_buffer, "\n\n", 1024) != 0)
		map_error("Empty line in map", game);
	if (read_buffer[0] == '\n')
		map_error("Empty line in map", game);
}

int	validate_map(t_game *game)
{
	game->map_valid = 1;
	check_file(game);
	check_new_lines(game);
	if (!game->map_valid)
		return (1);
	load_map(game);
	check_walls(game);
	check_characters(game);
	if (!game->map_valid)
		free_map(game);
	return (0);
}
