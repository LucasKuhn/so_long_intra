/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex-ku <lalex-ku@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 22:04:45 by lalexk-ku         #+#    #+#             */
/*   Updated: 2022/01/31 11:05:20 by lalex-ku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

// This is just an alias to avoid writing mlx_put_image_to_window
void	print_tile(t_game *game, void *sprite, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, sprite, x * 64, y * 64);
}

int	invalid_character(char c)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P' || c == 'G')
		return (0);
	return (1);
}
