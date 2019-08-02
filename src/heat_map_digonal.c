/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   heat_map_digonal.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/15 14:14:10 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/02 14:54:49 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/ft_filler.h"

void	adjust_map(int **map, t_tab *tab)
{
	int i;
	int y;
	int heat;

	i = 0;
	heat = 0;
	while (i < tab->width)
	{
		y = 0;
		while (y < tab->lenght)
		{
			if (map[i][y] == tab->lenght)
			{
				while (y < tab->lenght && map[i][y] == tab->lenght)
					y++;
				y--;
				heat = map[i][y];
				while (y > -1 && map[i][y] == tab->lenght)
					map[i][y--] = ++heat;
			}
			y++;
		}
		i++;
	}
}

void	lmap_diagonal_down(int **map, int *tmp, t_tab *tab)
{
	int i_up;
	int j;
	int	heat;
	int	a;

	j = *(tmp + 1);
	a = 0;
	while (j >= 0 && j < tab->lenght)
	{
		heat = 0;
		i_up = *tmp;
		if ((j < tab->lenght && j > -1) && map[i_up][j] == -1)
		{
			while (--j < tab->lenght && j > -1)
			{
				if (++i_up < tab->width)
					if (map[i_up][j] > ++heat)
						map[i_up][j] = heat;
			}
		}
		j = *(tmp + 1) + ++a;
	}
}

void	lmap_diagonal_up(int **map, int *tmp, t_tab *tab)
{
	int i_up;
	int j;
	int	heat;
	int	a;

	j = *(tmp + 1);
	a = 0;
	while (j >= 0 && j < tab->lenght)
	{
		heat = 0;
		i_up = *tmp;
		if ((j < tab->lenght && j > -1) && map[i_up][j] == -1)
		{
			while (--j < tab->lenght && j > -1)
			{
				if (--i_up >= 0)
					if (map[i_up][j] > ++heat)
						map[i_up][j] = heat;
			}
		}
		j = *(tmp + 1) + ++a;
	}
	lmap_diagonal_down(map, tmp, tab);
}

void	rmap_diagonal_down(int **map, int *tmp, t_tab *tab)
{
	int i_up;
	int j;
	int	heat;
	int	a;

	j = *(tmp + 1);
	a = 0;
	while (j >= 0 && j < tab->lenght)
	{
		heat = 0;
		i_up = *tmp;
		if ((j > -1) && map[i_up][j] == -1)
		{
			while (++j > -1 && j < tab->lenght)
			{
				if ((++i_up < tab->width && i_up >= 0) && map[i_up][j] > ++heat)
					map[i_up][j] = heat;
			}
		}
		j = *(tmp + 1) + ++a;
	}
	lmap_diagonal_up(map, tmp, tab);
}

void	rmap_diagonal_up(int **map, int *tmp, t_tab *tab)
{
	int i_up;
	int j;
	int	heat;
	int	a;

	j = *(tmp + 1);
	a = 0;
	while (j > -1 && j < tab->lenght)
	{
		heat = 0;
		i_up = *tmp;
		if ((j > -1 && j < tab->lenght) && map[i_up][j] == -1)
		{
			while (++j > -1 && j < tab->lenght)
			{
				if ((--i_up >= 0 && i_up < tab->width) && map[i_up][j] > ++heat)
					map[i_up][j] = heat;
			}
		}
		j = *(tmp + 1) + ++a;
	}
	rmap_diagonal_down(map, tmp, tab);
}
