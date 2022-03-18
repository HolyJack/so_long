/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_field.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:44:45 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/14 18:15:55 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_validate_map(char **map)
{
	int			i;
	int			j;
	const int	width = ft_strlen(map[0]);
	const int	heigth = sl_arrlen(map);

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j] && ft_strchr("01CPE", map[i][j]))
			if ((i == 0 || i == heigth - 1 || j == 0 || j == width -1)
				&& map[i][j] != '1')
				return (0);
		if (j != width)
			return (0);
	}
	if (sl_arrchr(map, 'P') != 1
		|| !sl_arrchr(map, 'E')
		|| !sl_arrchr(map, 'C'))
		return (0);
	return (1);
}

int	sl_count_strings(int fd)
{
	char	*tmp;
	int		count;

	count = 0;
	tmp = get_next_line(fd);
	while (tmp)
	{
		free(tmp);
		tmp = get_next_line(fd);
		count++;
	}
	return (count);
}

void	sl_exit_at_read(void *mlx)
{
	ft_putstr_fd("Error\n", 2);
	mlx_destroy_display(mlx);
	free(mlx);
	exit(0);
}

char	**sl_readmap(char *map_name, void *mlx)
{
	char	**array;
	int		fd;
	int		count;
	char	*tmp;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		sl_exit_at_read(mlx);
	count = sl_count_strings(fd);
	close(fd);
	array = malloc(sizeof(char *) * (count + 1));
	array[count] = 0;
	fd = open(map_name, O_RDONLY);
	count = 0;
	array[count] = get_next_line(fd);
	while (array[count])
	{
		tmp = ft_strchr(array[count], '\n');
		if (tmp)
			*tmp = 0;
		array[++count] = get_next_line(fd);
	}
	close(fd);
	return (array);
}

t_field	*sl_init_field(char *map_name, void *mlx)
{
	t_field	*field;
	char	**map;

	map = sl_readmap(map_name, mlx);
	field = malloc(sizeof(t_field));
	field->map = map;
	field->steps = 0;
	field->collectables = sl_arrchr(field->map, 'C');
	field->actr_x = sl_arrchr_x(field->map, 'P');
	field->actr_y = sl_arrchr_y(field->map, 'P');
	field->actr = malloc(sizeof(t_img));
	field->free = malloc(sizeof(t_img));
	field->wall = malloc(sizeof(t_img));
	field->coll = malloc(sizeof(t_img));
	field->exit = malloc(sizeof(t_img));
	return (field);
}
