/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykulkarn <ykulkarn@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 19:07:50 by ykulkarn          #+#    #+#             */
/*   Updated: 2024/04/25 01:32:25 by ykulkarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	img_init(t_scuba *img)
{
	int	w;
	int	h;

	img->sea = mlx_xpm_file_to_image(img->mlx, "./images/water.xpm", &h, &w);
	img->mine = mlx_xpm_file_to_image(img->mlx, "./images/mine.xpm", &h, &w);
	img->dive = mlx_xpm_file_to_image(img->mlx, "./images/diver.xpm", &h, &w);
	img->gold = mlx_xpm_file_to_image(img->mlx, "./images/gold.xpm", &h, &w);
	img->boat = mlx_xpm_file_to_image(img->mlx, "./images/boat.xpm", &h, &w);
}

int	main(int ac, char **av)
{
	t_scuba	*s_l;

	s_l = malloc(sizeof(t_scuba));
	if (!s_l)
	{
		write (2, "Error\nINVALID ALLOCATION!\n", 27);
		exit(1);
	}
	s_l->fd = verif_arg(ac, av);
	render_map(s_l);
	final_check(s_l);
	s_l->mlx = mlx_init();
	s_l->win = mlx_new_window(s_l->mlx, s_l->w * 64, s_l->h * 64, "so_long");
	s_l->moves = 0;
	s_l->collected = 0;
	img_init(s_l);
	put_elems2(s_l);
	mlx_key_hook(s_l->win, &key_press, s_l);
	mlx_hook(s_l->win, 17, 0, &end_game, s_l);
	mlx_loop(s_l->mlx);
	return (0);
}
