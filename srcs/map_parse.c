/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykulkarn <ykulkarn@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 23:26:00 by ykulkarn          #+#    #+#             */
/*   Updated: 2024/04/25 01:33:25 by ykulkarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	map_parse1(t_scuba *elems, char c)
{
	int	y;
	int	x;
	int	count;

	y = 0;
	count = 0;
	while (y < elems->h)
	{
		x = 0;
		while (x < elems->w)
		{
			if (elems->pos[y][x] == c)
			{	
				count++;
			}
			x++;
		}
		y++;
	}
	return (count);
}

int	map_parse2(t_scuba *elems)
{
	int	x;
	int	y;

	x = 0;
	while (x < elems->h)
	{
		y = 0;
		while (y < elems->w)
		{
			if (elems->pos[x][y] != '1' && elems->pos[x][y] != '0'
				&& elems->pos[x][y] != 'E' && elems->pos[x][y] != 'P'
				&& elems->pos[x][y] != 'C')
				return (1);
			y++;
		}
		x++;
	}
	return (0);
}

void	map_parse3(t_scuba *elems)
{
	int	y;
	int	x;

	y = 0;
	while (y < elems->h)
	{
		x = 0;
		while (x < elems->w)
		{
			if (elems->pos[y][x] == 'P')
			{
				elems->ypos = y;
				elems->xpos = x;
				break ;
			}
			x++;
		}
		y++;
	}
}
