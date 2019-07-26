/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   heat_map_adjust.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/19 23:03:03 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/20 00:21:52 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/ft_filler.h"

void	scotchisimo(int *y, int *i, int *num)
{
	*y = 0;
	*i = -1;
	*num = 707;
}

void		last_verif(t_tab *tab)
{
	int	i;
	int	y;
	int	num;
	int	value;

	y = 0;
	num = 0;
	value = 2147483647;
	while(y < tab->lenght)
	{
		i = 0;
		while (i < tab->width && tab->map[i][y] != 1)
		{
			if (tab->map[i][y] < value)
				value = tab->map[i][y];
			if (tab->map[i][y] > value)
				tab->map[i][y] = value;
			if ((i == tab->width - 1 && y == 0) && num == 0)
				scotchisimo(&y, &i, &num);
			i++;
		}
		y++;
	}
}
