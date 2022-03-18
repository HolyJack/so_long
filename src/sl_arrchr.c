/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_arrchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 13:32:07 by ejafer            #+#    #+#             */
/*   Updated: 2022/01/20 15:25:33 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_arrchr_y(char **arr, char c)
{
	int	i;
	int	j;

	i = -1;
	while (arr[++i])
	{
		j = -1;
		while (arr[i][++j])
			if (arr[i][j] == c)
				return (j);
	}
	return (-1);
}

int	sl_arrchr_x(char **arr, char c)
{
	int	i;

	i = -1;
	while (arr[++i])
		if (ft_strchr(arr[i], c))
			return (i);
	return (-1);
}

int	sl_arrchr(char **arr, char c)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	count = 0;
	while (arr[++i])
	{
		j = -1;
		while (arr[i][++j])
			if (arr[i][j] == c)
				count++;
	}
	return (count);
}
