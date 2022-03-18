/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_inputs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:49:45 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/14 17:44:08 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_exit(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	sl_free_field(data->mlx, data->field);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data);
	exit(0);
	return (0);
}

int	sl_inputs(int keycode, t_data *data)
{
	if (keycode == ESCAPE)
		sl_exit(data);
	if (keycode == W || keycode == A || keycode == S || keycode == D)
		data->update = sl_game(keycode, data->field);
	return (0);
}
