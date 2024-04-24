/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykulkarn <ykulkarn@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 17:12:57 by ykulkarn          #+#    #+#             */
/*   Updated: 2024/04/25 01:34:16 by ykulkarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "../mlx/mlx.h"
# include <X11/keysym.h>
# define W 13
# define A 0
# define S 1
# define D 2
# define ESC 53
# define BUFFER_SIZE 100000

typedef struct s_scuba {
	char	**pos;
	int		h;
	int		w;
	int		xpos;
	int		ypos;
	int		moves;
	int		player;
	int		exit;
	int		to_collect;
	int		collected;
	int		fd;
	int		fd2;
	void	*mlx;
	void	*win;
	void	*dive;
	void	*boat;
	void	*sea;
	void	*mine;
	void	*gold;

}				t_scuba;

void	put_elems(t_scuba *elems, int x, int y, char elements);
int		put_elems2(t_scuba *map);

void	count_steps(t_scuba *steps);
int		move_player(t_scuba *m, char c, int x, int y);
int		key_press(int keys, t_scuba *map);

int		wall_verif(t_scuba *walls);
int		elems_verif(t_scuba *elems);
int		verif_bounds(t_scuba *scuba);
void	final_check(t_scuba *map);

int		map_parse1(t_scuba *elems, char c);
int		map_parse2(t_scuba *elems);
void	map_parse3(t_scuba *elems);

void	clear_game(t_scuba *scuba);
void	clear_img(t_scuba *img);
int		end_game(t_scuba *game);

int		verif_arg(int ac, char **av);

void	game(t_scuba *map, char *str);
void	str_parse(t_scuba *map, char *str);
void	render_map(t_scuba *map);

void	ft_putchar(char c);
void	ft_putnbr(int n);
int		ft_strlen2(char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

void	img_init(t_scuba *img);

//-----------GET_NEXT_LINE----------------------//

char	*get_next_line(int fd);
char	*ft_strchr(char *s, int c);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*find_nl(char *line);
char	*after_nl(char *store);
char	*combine(int fd, char *store);
char	ft_if(char *s1);
char	*get_next_line(int fd);

#endif
