/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex-ku <lalex-ku@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 22:02:09 by lalexk-ku         #+#    #+#             */
/*   Updated: 2022/01/31 11:05:20 by lalex-ku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{			
			if (game->map[y][x] == 'P' && !game->x)
			{
				game->x = x;
				game->y = y;
			}
			else if (game->map[y][x] == 'P')
				game->map[y][x] = '0';
			if (game->map[y][x] == 'C')
				game->coins++;
			x++;
		}
		y++;
	}
	game->map_width = x * 64;
	game->map_height = y * 64;
}

void	load_map(t_game *game)
{
	int		fd;
	char	read_buffer[1024];

	fd = open(game->map_file, O_RDONLY);
	ft_bzero(read_buffer, 1024);
	read(fd, read_buffer, 1024);
	close(fd);
	game->map = ft_split(read_buffer, '\n');
	init_map(game);
}

int	free_map(t_game *game)
{
	int	y;

	if (!game->map)
		return (1);
	y = 0;
	while (game->map[y])
	{
		free(game->map[y]);
		game->map[y] = NULL;
		y++;
	}
	free(game->map);
	game->map = NULL;
	return (1);
}
