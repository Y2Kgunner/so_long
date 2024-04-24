/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykulkarn <ykulkarn@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:22:49 by ykulkarn          #+#    #+#             */
/*   Updated: 2024/04/25 01:33:51 by ykulkarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	game(t_scuba *map, char *str)
{
	map->h = 1;
	map->w = ft_strlen2(str);
	map->pos = (char **)malloc(sizeof(char *) * 1);
	if (!map->pos)
	{
		write(2, "Error\nINVALID ALLOCATION!\n", 27);
		if (map)
			clear_game(map);
		exit(1);
	}
	map->pos[0] = str;
}

void	str_parse(t_scuba *map, char *str)
{
	char	**val;
	char	**str_t;
	int		x;

	x = 0;
	str_t = map->pos;
	val = (char **)malloc(sizeof(char *) * (map->h + 1));
	if (!val)
	{	
		write(2, "Error\nINVALID ALLOCATION!\n", 27);
		if (map)
			clear_game(map);
		exit(1);
	}
	while (x < map->h)
	{
		val[x] = str_t[x];
		x++;
	}
	val[x] = str;
	free(map->pos);
	map->pos = val;
	map->h++;
}

void	render_map(t_scuba *map)
{
	char	*str_t;

	str_t = get_next_line(map->fd);
	if (str_t)
		game(map, str_t);
	else
	{
		free(map);
		write(2, "Error\nINCORRECT MAP ELEMENTS!\n", 31);
		exit(1);
	}
	str_t = get_next_line(map->fd);
	while (str_t)
	{
		str_parse(map, str_t);
		str_t = get_next_line(map->fd);
	}
	close(map->fd);
}
