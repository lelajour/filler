/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   heat_map_adjust.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/19 23:03:03 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/02 15:37:39 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/ft_filler.h"

void	sept(int **map, t_tab *t)
{
	int	i;
	int	y;
	int	heat;

	heat = 0;
	i = 0;
	while (++i < t->width)
	{
		y = 0;
		while ((++y < t->lenght))
		{
			if (map[i][y] != -1)
				map[i][y] = ++heat;
		}
	}
}

void	seize(int **map, t_tab *t)
{
	int	i;
	int	y;
	int	ret;
	int	heat;

	ret = 0;
	i = t->pos_en[t->width_en - 1][0];
	y = t->pos_en[t->width_en - 1][2];
	while (y < t->lenght && y > -1)
	{
		i = t->pos_en[t->width_en - 1][0];
		heat = map[i][y] + ret;
		while ((++i < t->width && i > -1) && (y < t->lenght && y > -1))
			map[i][y] = ++heat;
		y = t->pos_en[t->width_en - 1][2] + ++ret;
	}
}

void	fortytwo(int **map, t_tab *t)
{
	static int a = 100;

	if (a > 19)
	{
		if (t->dw == 4)
			a = 16;
		else
			a = 19;
	}
	if (a-- > 0 && t->c != 'O')
	{
		if (t->dw == 4)
			seize(map, t);
		else
			sept(map, t);
	}
}
