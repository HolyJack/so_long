/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:49:59 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/14 18:13:23 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_readimage(t_img *img, char *path, void *mlx)
{
	img->img = mlx_xpm_file_to_image(mlx, path, &(img->width), &(img->height));
}

void	sl_readassets(t_field *field, void *mlx)
{
	sl_readimage(field->actr, "./assets/Player.xpm", mlx);
	sl_readimage(field->wall, "./assets/Wall.xpm", mlx);
	sl_readimage(field->free, "./assets/Floor.xpm", mlx);
	sl_readimage(field->coll, "./assets/Coin.xpm", mlx);
	sl_readimage(field->exit, "./assets/Exit.xpm", mlx);
}

t_data	*sl_init_data(void *mlx, void *win, t_field *field)
{
	t_data	*data;

	data = malloc(sizeof(t_data) * 1);
	data->mlx = mlx;
	data->field = field;
	data->win = win;
	data->update = 1;
	return (data);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	t_field	*field;
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	if (argc != 2)
		return (0);
	field = sl_init_field(argv[1], mlx);
	sl_readassets(field, mlx);
	win = mlx_new_window(mlx,
			SCALING * ft_strlen(field->map[0]),
			SCALING * sl_arrlen(field->map),
			"so_long");
	data = sl_init_data(mlx, win, field);
	if (!sl_validate_map(field->map))
	{
		ft_putstr_fd("Error!\n", 2);
		sl_exit(data);
	}
	mlx_hook(win, 2, 1L << 0, sl_inputs, data);
	mlx_hook(win, 33, 1L << 17, sl_exit, data);
	mlx_loop_hook(mlx, sl_render, data);
	mlx_loop(mlx);
	return (0);
}
