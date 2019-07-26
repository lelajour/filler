/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   heat_map.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/12 22:07:35 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/25 07:47:10 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/ft_filler.h"

void	assign_heat_vertikal_down(int **map, int *tmp, t_tab *tab)
{
	int	heat;
	int	i;
	int	j;

	j = *(tmp + 1) + 1;
	while (j < *(tmp + 2))
	{
		i = *tmp;
		heat = 0;
		while (++i < tab->width)
		{
			if (map[i][j] > heat++ && map[i][j] != -1)
				map[i][j] = heat;
		}
		j++;
	}
}

void	ft_assign_en_pos(int *tmp, int i, t_tab *tab)
{
	int j;
	char c;

	c = tab->c == 'O' ? 'x' : 'o';
	j = *(tmp + 1);
	while (++j < *(tmp + 2))
	{
		if (tab->tab[i][j] == c || tab->tab[i][j] == c - 32)
			tab->map[i][j] = -1;
	}
}

void	assign_heat_vertikal(int **map, int *tmp, t_tab *tab)
{
	int	heat;
	int	i;
	int	j;

	(void)tab;
	i = *tmp;
	j = *(tmp + 1) + 1;
	while (j < *(tmp + 2))
	{
		heat = 0;
		if (i > 0 && map[i - 1][j] != -1)
		{
			while (--i > -1 && map[i][j] != -1)
			{
				if (map[i][j] > heat++)
					map[i][j] = heat;
			}
			i = *tmp;
		}
		j++;
	}
	assign_heat_vertikal_down(map, tmp, tab);

}

void	assign_heat_horizon(int **map, int *tmp, t_tab *tab)
{
	int	heat;
	int	i;
	int	j;
	int	t;

	heat = 0;
	i = *tmp;
	j = *(tmp + 1);
	t = *(tmp + 2);
	while (j >= 0)
	{
		while (t < tab->lenght)
		{
			if (map[i][t] > heat++)
				map[i][t] = heat;
			if (t == tab->lenght - 1)
				heat = 0;
			t++;
		}
		if (map[i][j] > ++heat)
			map[i][j] = heat;
		j--;
	}
	ft_assign_en_pos(tmp, i, tab);
}

void	fill_heat_map(t_tab *tab)
{
	int	*tmp;
	int	i;
	int	len;

	i = -1;
	len = tab->lenght;
	tab->map = (int**)malloc(sizeof(int*) * tab->width);
	while (++i < tab->width)
		tab->map[i] = ft_imemset(ft_memalloc(len), len, len);
	i = -1;
	int y;
	while (++i < tab->width_en)
	{
		tmp = tab->pos_en[i];
		assign_heat_horizon(tab->map, tmp, tab);
		assign_heat_vertikal(tab->map, tmp, tab);
		rmap_diagonal_up(tab->map, tmp, tab);

	}
	adjust_map(tab->map, tab);
	// last_verif(tab);
	i = -1;
	while (++i < tab->width)
	{
		y = 0;
		ft_printf("[%d]", i);
		while (y < len)
			ft_printf("|%03d|", tab->map[i][y++]);
		ft_putchar('\n');
	}
}
