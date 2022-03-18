/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:42:37 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/14 01:01:40 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_chose(int nbr, int value1, int value2)
{
	if (nbr == value1)
		return (1);
	if (nbr == value2)
		return (-1);
	return (0);
}

void	sl_print_totalmoves(int steps)
{
	ft_putstr_fd("Total moves: ", 1);
	ft_putnbr_fd(steps, 1);
	ft_putstr_fd("\n", 1);
}

int	sl_game(int keycode, t_field *field)
{
	int	i;
	int	j;

	i = sl_chose(keycode, S, W);
	j = sl_chose(keycode, D, A);
	if ((i || j) && field->map[field->actr_x + i][field->actr_y + j] != '1')
	{
		if (field->map[field->actr_x + i][field->actr_y + j] == 'E' &&
			field->collectables)
			return (0);
		field->steps++;
		sl_print_totalmoves(field->steps);
		if (field->map[field->actr_x + i][field->actr_y + j] == 'C')
			field->collectables--;
		if (field->map[field->actr_x + i][field->actr_y + j] == 'E' &&
			!field->collectables)
			return (2);
		field->map[field->actr_x][field->actr_y] = '0';
		field->map[field->actr_x + i][field->actr_y + j] = 'P';
		field->actr_x += i;
		field->actr_y += j;
		return (1);
	}
	return (0);
}
