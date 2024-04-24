/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endgame.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykulkarn <ykulkarn@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 13:01:28 by ykulkarn          #+#    #+#             */
/*   Updated: 2024/04/25 01:32:39 by ykulkarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	clear_game(t_scuba *scuba)
{
	int	x;

	x = 0;
	if (scuba->pos[0])
	{
		while (x < scuba->h)
		{
			free(scuba->pos[x]);
			x++;
		}
		free(scuba->pos);
	}
	free(scuba);
}

void	clear_img(t_scuba *img)
{
	mlx_destroy_image(img->mlx, img->sea);
	mlx_destroy_image(img->mlx, img->dive);
	mlx_destroy_image(img->mlx, img->gold);
	mlx_destroy_image(img->mlx, img->mine);
	mlx_destroy_image(img->mlx, img->boat);
	mlx_clear_window(img->mlx, img->win);
	mlx_destroy_window(img->mlx, img->win);
	free(img->mlx);
}

int	end_game(t_scuba *game)
{
	clear_img(game);
	clear_game(game);
	write(1, "GAME OVER\n", 11);
	exit(0);
	return (0);
}
