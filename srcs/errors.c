/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykulkarn <ykulkarn@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:40:38 by ykulkarn          #+#    #+#             */
/*   Updated: 2024/04/25 01:32:47 by ykulkarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	arg_num(int ac)
{
	if (ac != 2)
	{
		write (2, "Error\nINSUFFICIENT ARGUMENTS!\n", 31);
		exit(1);
	}
}

int	verif_arg(int ac, char **av)
{
	char	*file;
	int		fd;

	arg_num(ac);
	fd = open(av[1], O_DIRECTORY);
	if (fd != -1)
	{	
		write(2, "Error\nNOT ACCESSING A FILE!\n", 29);
		exit(1);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{	
		write(2, "Error\nUNABLE TO ACCESS!\n", 25);
		exit(1);
	}
	file = ft_strchr(av[1], '.');
	if (ft_strncmp(file, ".ber", 4) != 0)
	{	
		write(2, "Error\nINCORRECT FILE TYPE!\n", 28);
		exit(1);
	}
	return (fd);
}
