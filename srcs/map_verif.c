/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykulkarn <ykulkarn@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 12:46:56 by ykulkarn          #+#    #+#             */
/*   Updated: 2024/04/25 01:33:36 by ykulkarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	wall_verif(t_scuba *walls)
{
	int	count;

	count = 0;
	while (count < walls->w)
	{
		if (walls->pos[0][count] != '1')
			return (1);
		if (walls->pos[walls->h - 1][count] != '1')
			return (1);
		count++;
	}
	count = 0;
	while (count < walls->h)
	{
		if (walls->pos[count][walls->w - 1] != '1')
			return (1);
		if (walls->pos[count][0] != '1')
			return (1);
		count++;
	}
	return (0);
}

int	elems_verif(t_scuba *elems)
{
	elems->exit = map_parse1(elems, 'E');
	elems->player = map_parse1(elems, 'P');
	elems->collected = map_parse1(elems, 'C');
	elems->to_collect = map_parse1(elems, 'C');
	if (map_parse2(elems))
		return (1);
	if (elems->player != 1 || elems->collected == 0 || elems->exit == 0)
		return (1);
	map_parse3(elems);
	return (0);
}

int	verif_bounds(t_scuba *scuba)
{
	int	x;

	x = 0;
	while (x <= 12)
	{
		if (ft_strlen2(scuba->pos[x]) == 12)
			x++;
		else
			return (1);
	}
	if (scuba->h == scuba->w)
		return (1);
	return (0);
}

void	final_check(t_scuba *map)
{
	if (wall_verif(map) || elems_verif(map))
	{
		write(2, "Error\nINVALID MAP!\n", 20);
		if (map)
			clear_game(map);
		exit(1);
	}
}
