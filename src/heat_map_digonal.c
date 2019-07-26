/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   heat_map_digonal.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/15 14:14:10 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/15 23:43:11 by lelajour    ###    #+. /#+    ###.fr     */
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

	i_up = *tmp;
	j = *(tmp + 2);
	a = 1;

	while (j >= *(tmp + 1))
	{
		heat = 1;
		i_up = *tmp;
		while (j < tab->lenght)
		{
			if (++i_up < tab->width)
				if (map[i_up][j] > heat)
					map[i_up][j] = heat;
			heat++;
			j++;
		}
		j = (*(tmp + 2)) - a++;
	}
}

void	lmap_diagonal_up(int **map, int *tmp, t_tab *tab)
{
	int i_up;
	int j;
	int	heat;
	int	a;

	i_up = *tmp;
	j = *(tmp + 2);
	a = 1;
	while (j >= *(tmp + 1))
	{
		heat = 1;
		i_up = *tmp;
		while (j < tab->lenght)
		{
			if (--i_up >= 0)
				if (map[i_up][j] > heat)
					map[i_up][j] = heat;
			heat++;
			j++;
		}
		j = (*(tmp + 2)) - a++;
	}
	lmap_diagonal_down(map, tmp, tab);
}

void	rmap_diagonal_down(int **map, int *tmp, t_tab *tab)
{
	int i_up;
	int j;
	int	heat;
	int	a;

	i_up = *tmp;
	j = *(tmp + 2);
	a = 1;
	while (j >= *(tmp + 1))
	{
		heat = 1;
		i_up = *tmp;
		while (j > -1)
		{
			if (++i_up < tab->width)
				if (map[i_up][j] > heat)
					map[i_up][j] = heat;
			heat++;
			j--;
		}
		j = (*(tmp + 2)) - a++;
	}
	lmap_diagonal_up(map, tmp, tab);
	// int i;
	// int y;
	// i = -1;
	// while (++i < tab->width)
	// {
	// 	y = 0;
	// 	while (y < tab->lenght)
	// 		ft_printf("|%03d|", tab->map[i][y++]);
	// 	ft_putchar('\n');
	// }
}

void	rmap_diagonal_up(int **map, int *tmp, t_tab *tab)
{
	int i_up;
	int j;
	int	heat;
	int	a;

	(void)tab;
	i_up = *tmp;
	j = *(tmp + 2);
	a = 1;
	while (j >= *(tmp + 1))
	{
		heat = 1;
		i_up = *tmp;
		while (j > -1)
		{
			if (--i_up >= 0)
				if (map[i_up][j] > heat)
					map[i_up][j] = heat;
			heat++;
			j--;
		}
		j = (*(tmp + 2)) - a++;
	}
	rmap_diagonal_down(map, tmp, tab);
}