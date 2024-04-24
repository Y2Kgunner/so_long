/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keybinds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykulkarn <ykulkarn@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:09:11 by ykulkarn          #+#    #+#             */
/*   Updated: 2024/04/25 01:33:12 by ykulkarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	count_steps(t_scuba *steps)
{
	write(1, "NO. OF STEPS: ", 15);
	ft_putnbr(steps->moves);
	write(1, "\n", 1);
}

int	move_player(t_scuba *m, char c, int x, int y)
{
	if (c == 'C' || c == '0')
	{
		mlx_put_image_to_window(m->mlx, m->win, m->sea, m->ypos * 64, \
		m->xpos * 64);
		m->pos[m->xpos][m->ypos] = '0';
		m->ypos = y;
		m->xpos = x;
		mlx_put_image_to_window(m->mlx, m->win, m->dive, m->ypos * 64, \
		m->xpos * 64);
		m->pos[m->xpos][m->ypos] = 'P';
		m->moves++;
		count_steps(m);
		if (c == 'C')
			m->collected++;
	}
	if (c == 'E' && (m->collected == m->to_collect))
	{
		m->moves++;
		count_steps(m);
		write(1, "GAME WON!\n", 11);
		end_game(m);
	}
	return (0);
}

int	key_press(int keys, t_scuba *map)
{
	int		x;
	int		y;
	char	elem;

	x = map->xpos;
	y = map->ypos;
	if (keys == XK_Up)
		x--;
	else if (keys == XK_Down)
		x++;
	else if (keys == XK_Left)
		y--;
	else if (keys == XK_Right)
		y++;
	else if (keys == XK_Escape)
		end_game(map);
	elem = map->pos[x][y];
	move_player(map, elem, x, y);
	return (0);
}
