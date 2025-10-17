/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_flood_fill.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-cad <jose-cad@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 20:13:26 by jose-cad          #+#    #+#             */
/*   Updated: 2025/10/13 20:18:47 by jose-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void		flood_fill(char **map_copy, int y, int x);
static void		validate_flood_fill_result(t_game *game, char **map_copy);
static int		check_reachable_tiles(t_game *game, char **map_copy);
static size_t	get_map_height(char **map);

void	check_path(t_game *game)
{
	char	**map_copy;

	map_copy = copy_map(game->map, game->map_height);
	if (!map_copy)
		error_exit("Error: Failed to allocate memory for map copy.");
	flood_fill(map_copy, game->player_y, game->player_x);
	validate_flood_fill_result(game, map_copy);
	free_map(map_copy);
}

static int	check_reachable_tiles(t_game *game, char **map_copy)
{
	int	y;
	int	x;
	int	e_reached;

	y = 0;
	e_reached = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (map_copy[y][x] == 'C')
			{
				free_map(map_copy);
				error_exit("Error: Unreachable collectible(s).");
			}
			if (game->map[y][x] == 'E' && map_copy[y][x] == 'F')
				e_reached = 1;
			x++;
		}
		y++;
	}
	return (e_reached);
}

static void	validate_flood_fill_result(t_game *game, char **map_copy)
{
	int	e_reached;

	e_reached = check_reachable_tiles(game, map_copy);
	if (e_reached == 0)
	{
		free_map(map_copy);
		error_exit("Error: Unreachable exit.");
	}
}

static void	flood_fill(char **map_copy, int y, int x)
{
	if (y < 0 || (size_t)y >= get_map_height(map_copy) || x < 0
		|| (size_t)x >= ft_strlen(map_copy[0]))
		return ;
	if (map_copy[y][x] == '1' || map_copy[y][x] == 'F')
		return ;
	if (map_copy[y][x] == 'E')
	{
		map_copy[y][x] = 'F';
		return ;
	}
	map_copy[y][x] = 'F';
	flood_fill(map_copy, y + 1, x);
	flood_fill(map_copy, y - 1, x);
	flood_fill(map_copy, y, x + 1);
	flood_fill(map_copy, y, x - 1);
}

static size_t	get_map_height(char **map)
{
	size_t	i;

	i = 0;
	if (!map)
		return (0);
	while (map[i])
		i++;
	return (i);
}
