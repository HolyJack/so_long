/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_server.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 04:15:46 by ejafer            #+#    #+#             */
/*   Updated: 2022/02/03 17:19:55 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include "stdlib.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str++)
		len++;
	return (len);
}

int	ft_putstr(char *str)
{
	return (write(1, str, ft_strlen(str)));
}

int	ft_intlen(int n)
{
	int	len;

	len = 1;
	while (n /= 10)
		len++;
	return (len);
}

int	ft_putnbr(int n)
{
	int			i;
	const int 	len = ft_intlen(n);
	char		buf[11];

	buf[len] = 0;
	i = (int) len;
	while (n)
	{
		buf[--i] = n % 10 + '0';
		n /= 10;
	}
	ft_putstr(buf);
	return (len);
}