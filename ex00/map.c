/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 11:43:37 by mhaouas           #+#    #+#             */
/*   Updated: 2024/08/17 12:24:21 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static void	print_line(t_map *map, size_t len, size_t i)
{
	if (i < len)
	{
		write(1, &map[i].c_value, 1);
		write(1, " ", 1);
		return (print_line(map, len, ++i));
	}
}

static void	print_collumn(t_map **map, size_t len, size_t i)
{
	if (i < len)
	{
		print_line(map[i], len, 0);
		write(1, "\n", 1);
		return (print_collumn(map, len, ++i));
	}
}

void	print_map(size_t size, t_map **map)
{
	print_collumn(map, size, 0);
}

static t_map	**malloc_line(t_map **map, size_t x, size_t i)
{
	t_map	**tmp;

	tmp = NULL;
	if (i < x)
	{
		map[i] = ft_calloc(x, sizeof(t_map));
		if (!map[i])
			return (NULL);
		tmp = malloc_line(map, x, ++i);
		if (!tmp)
		{
			free(map[i]);
			return (NULL);
		}
	}
	return (map);
}

static t_map	**malloc_map(t_map **map, size_t x, size_t y)
{
	if (!map)
	{
		map = malloc(sizeof(t_map *) * y);
		if (!map)
			return (NULL);
		else
			return (malloc_map(map, x, y));
	}
	else
	{
		map = malloc_line(map, x, 0);
		if (!map)
		{
			free(map);
			return (NULL);
		}
		return (map);
	}
}

t_map	**set_map(size_t x, size_t y)
{
	t_map	**map;

	map = malloc_map(NULL, x, y);
	for(size_t i = 0; i < y; i++)
	{
		for (size_t j = 0; j < x; j++)
			map[i][j].c_value = '1';
	}
	return (map);
}

static void	free_line(t_map **map, size_t size, size_t i)
{
	if (i < size)
	{
		free(map[i]);
		return (free_line(map, size, ++i));
	}
}

void	free_map(t_map **map, size_t size)
{
	free_line(map, size, 0);
	free(map);
}

int	main(void)
{
	t_map	**map;

	map = set_map(4, 4);
	print_map(4, map);
	free_map(map, 4);
}
