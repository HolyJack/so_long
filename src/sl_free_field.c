/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_free_field.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:48:18 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/14 17:50:04 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_free_img(void *mlx, t_img *img)
{
	if (img)
	{
		if (img->img)
			mlx_destroy_image(mlx, img->img);
		free(img);
	}
}

void	sl_free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

void	sl_free_field(void *mlx, t_field *field)
{
	if (field)
	{
		if (field->map)
			sl_free_map(field->map);
		sl_free_img(mlx, field->actr);
		sl_free_img(mlx, field->free);
		sl_free_img(mlx, field->wall);
		sl_free_img(mlx, field->coll);
		sl_free_img(mlx, field->exit);
		free(field);
	}
}
