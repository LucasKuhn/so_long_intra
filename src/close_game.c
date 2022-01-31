/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex-ku <lalex-ku@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 22:04:45 by lalexk-ku         #+#    #+#             */
/*   Updated: 2022/01/22 17:05:10 by lalex-ku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_user_sprites(t_game *game)
{
	mlx_destroy_image(game->mlx, game->user_sprites.s_0);
	mlx_destroy_image(game->mlx, game->user_sprites.s_1);
	mlx_destroy_image(game->mlx, game->user_sprites.s_2);
	mlx_destroy_image(game->mlx, game->user_sprites.s_3);
	mlx_destroy_image(game->mlx, game->user_sprites.w_0);
	mlx_destroy_image(game->mlx, game->user_sprites.w_1);
	mlx_destroy_image(game->mlx, game->user_sprites.w_2);
	mlx_destroy_image(game->mlx, game->user_sprites.w_3);
	mlx_destroy_image(game->mlx, game->user_sprites.a_0);
	mlx_destroy_image(game->mlx, game->user_sprites.a_1);
	mlx_destroy_image(game->mlx, game->user_sprites.a_2);
	mlx_destroy_image(game->mlx, game->user_sprites.a_3);
	mlx_destroy_image(game->mlx, game->user_sprites.d_0);
	mlx_destroy_image(game->mlx, game->user_sprites.d_1);
	mlx_destroy_image(game->mlx, game->user_sprites.d_2);
	mlx_destroy_image(game->mlx, game->user_sprites.d_3);
}

int	close_game(t_game *game)
{
	free_map(game);
	destroy_user_sprites(game);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->tile);
	mlx_destroy_image(game->mlx, game->exit_sprites.open);
	mlx_destroy_image(game->mlx, game->exit_sprites.closed);
	mlx_destroy_image(game->mlx, game->ghost_sprites.ghost_0);
	mlx_destroy_image(game->mlx, game->ghost_sprites.ghost_1);
	mlx_destroy_image(game->mlx, game->ghost_sprites.ghost_2);
	mlx_destroy_image(game->mlx, game->ghost_sprites.ghost_3);
	mlx_destroy_image(game->mlx, game->coin_sprites.coin_0);
	mlx_destroy_image(game->mlx, game->coin_sprites.coin_1);
	mlx_destroy_image(game->mlx, game->coin_sprites.coin_2);
	mlx_destroy_image(game->mlx, game->coin_sprites.coin_3);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	game->mlx = NULL;
	exit(0);
}

int	game_over(t_game *game)
{
	int		x;
	int		y;
	void	*sprite;
	int		sprite_w;
	int		sprite_h;

	sprite = mlx_xpm_file_to_image(
			game->mlx, "sprites/game_over.xpm", &sprite_w, &sprite_h);
	x = (game->map_width / 2) - (sprite_w / 2);
	y = (game->map_height / 2) - (sprite_h / 2);
	mlx_put_image_to_window(game->mlx, game->win, sprite, x, y);
	mlx_destroy_image(game->mlx, sprite);
	sprite = NULL;
	game->game_ended = 1;
	return (0);
}

int	game_complete(t_game *game)
{
	int		x;
	int		y;
	void	*sprite;
	int		sprite_w;
	int		sprite_h;

	sprite = mlx_xpm_file_to_image(
			game->mlx, "sprites/you_win.xpm", &sprite_w, &sprite_h);
	x = (game->map_width / 2) - (sprite_w / 2);
	y = (game->map_height / 2) - (sprite_h / 2);
	mlx_put_image_to_window(game->mlx, game->win, sprite, x, y);
	mlx_destroy_image(game->mlx, sprite);
	sprite = NULL;
	game->game_ended = 1;
	return (0);
}
