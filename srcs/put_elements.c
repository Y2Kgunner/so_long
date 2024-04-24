/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykulkarn <ykulkarn@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 18:58:41 by ykulkarn          #+#    #+#             */
/*   Updated: 2024/04/25 01:33:44 by ykulkarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_elems(t_scuba *map, int x, int y, char elems)
{
	if (elems == '1')
		mlx_put_image_to_window(map->mlx, map->win, map->mine, y * 64, x * 64);
	if (elems == '0')
		mlx_put_image_to_window(map->mlx, map->win, map->sea, y * 64, x * 64);
	if (elems == 'P')
	{	
		map->xpos = x;
		map->ypos = y;
		mlx_put_image_to_window(map->mlx, map->win, map->dive, y * 64, x * 64);
	}
	if (elems == 'C')
		mlx_put_image_to_window(map->mlx, map->win, map->gold, y * 64, x * 64);
	if (elems == 'E')
		mlx_put_image_to_window(map->mlx, map->win, map->boat, y * 64, x * 64);
}

int	put_elems2(t_scuba *map)
{
	char	elements;
	int		x;
	int		y;

	x = 0;
	while (x < map->w)
	{
		y = 0;
		while (y < map->h)
		{
			elements = map->pos[y][x];
			put_elems(map, y, x, elements);
			y++;
		}
		x++;
	}
	return (0);
}
