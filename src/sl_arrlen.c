/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_arrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 13:09:41 by ejafer            #+#    #+#             */
/*   Updated: 2022/01/20 15:25:12 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_arrlen(char **arr)
{
	int	len;

	len = 0;
	while (arr[len])
		len++;
	return (len);
}
