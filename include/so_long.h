/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 19:48:22 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/20 15:56:32 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "get_next_line.h"
# define ESCAPE 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define SCALING 32

typedef struct s_img
{
	void	*img;
	int		width;
	int		height;
}	t_img;

typedef struct s_field
{
	char	**map;
	int		actr_x;
	int		actr_y;
	int		collectables;
	int		steps;
	t_img	*actr;
	t_img	*wall;
	t_img	*free;
	t_img	*coll;
	t_img	*exit;
}	t_field;

typedef struct s_data
{
	int		update;
	void	*mlx;
	void	*win;
	t_field	*field;
}	t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_data	*img;
}	t_vars;

t_field	*sl_init_field(char *map_name);
void	sl_free_field(void *mlx, t_field *field);
int		sl_render(t_data *data);
int		sl_game(int keycode, t_field *field);
int		sl_inputs(int keycode, t_data *data);
int		sl_exit(t_data *data);
void	sl_error_exit(void);
int		sl_validate_map(char **map);
int		sl_arrlen(char **arr);
int		sl_arrchr(char **arr, char c);
int		sl_arrchr_x(char **arr, char c);
int		sl_arrchr_y(char **arr, char c);

int		ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_putchar_fd(char c, int fd);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
