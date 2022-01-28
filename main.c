/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex-ku <lalex-ku@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 22:03:52 by lalexk-ku         #+#    #+#             */
/*   Updated: 2022/01/22 18:26:06 by lalex-ku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_init(t_game *game)
{
	game->moves = 0;
	game->game_ended = 0;
	game->coins = 0;
	game->exit = 0;
	game->x = 0;
	game->y = 0;
	game->collected_coins = 0;
	game->last_key = KEY_S;
	game->map = NULL;
}

int	ft_update(t_game *game)
{
	static int	frame;

	if (game->game_ended)
		return (0);
	draw_map(game, frame);
	draw_moves(game);
	if (frame == 30 * 4)
		frame = 0;
	else
		frame++;
	return (0);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		return (close_game(game));
	if (keycode == KEY_R)
	{
		free_map(game);
		game_init(game);
		load_map(game);
	}
	if (keycode == KEY_P)
		game_complete(game);
	if (game->game_ended)
		return (0);
	if (is_movement_key(keycode))
		handle_movement(keycode, game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	game_init(&game);
	if (argc < 2)
		return (map_error("Map file missing", &game));
	game.map_file = argv[1];
	validate_map(&game);
	if (!game.map_valid)
		return (1);
	game.mlx = mlx_init();
	game.win = mlx_new_window(
			game.mlx, game.map_width, game.map_height, "so_long");
	load_images(&game);
	load_user_sprites(&game);
	mlx_hook(game.win, BTN_X, NO_EVENT, close_game, &game);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_loop_hook(game.mlx, *ft_update, &game);
	mlx_loop(game.mlx);
	return (0);
}
