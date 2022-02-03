/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:54:54 by ejafer            #+#    #+#             */
/*   Updated: 2022/02/03 17:10:51 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# define BUFSIZE 2048

# include <stdio.h>
# include <signal.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_data
{
	char	str[BUFSIZE];
	int		c;
	int		s_index;
	int		bits;
} t_data;

t_data g_data;

int	ft_atoi(const char *s);
int ft_putstr(char *str);
int ft_putnbr(int n);

#endif
