/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:46:58 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/14 01:32:15 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_draw_cell(t_data *data, int i, int j)
{
	if (data->field->map[i][j] == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->field->free->img,
			j * SCALING, i * SCALING);
	if (data->field->map[i][j] == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->field->wall->img,
			j * SCALING, i * SCALING);
	if (data->field->map[i][j] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->field->coll->img,
			j * SCALING, i * SCALING);
	if (data->field->map[i][j] == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->field->actr->img,
			j * SCALING, i * SCALING);
	if (data->field->map[i][j] == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->field->exit->img,
			j * SCALING, i * SCALING);
}

void	sl_drawfield(t_data *data)
{
	int		i;
	int		j;

	i = -1;
	while (data->field->map[++i])
	{
		j = -1;
		while (data->field->map[i][++j])
			sl_draw_cell(data, i, j);
	}
}

int	sl_render(t_data *data)
{
	if (data->update == 1)
	{
		data->update = 0;
		sl_drawfield(data);
	}
	if (data->update == 2)
		sl_exit(data);
	return (0);
}
