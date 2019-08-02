/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fill_tab.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/06 19:27:04 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/02 07:12:28 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/ft_filler.h"

int		*get_pos_tab(char *str, int i, char c)
{
	int *tmp;

	tmp = NULL;
	tmp = ft_memalloc(3);
	tmp[0] = i;
	tmp[1] = ft_strnclen(str, c) - 1;
	tmp[2] = ft_strrnclen(str, c) + 1;
	return (tmp);
}

void	get_my_pos(t_tab *tab, int i, char c)
{
	int		width;
	int		tmp;

	width = 0;
	tmp = i;
	while (i < tab->width)
	{
		if (ft_strrchr(tab->tab[i], c) || ft_strrchr(tab->tab[i], c + 32))
			width++;
		i++;
	}
	tab->width_my = width;
	tab->my_pos = (int**)malloc(sizeof(int*) * width);
	width = 0;
	while (tmp < tab->width)
	{
		if (ft_strrchr(tab->tab[tmp], c) || ft_strrchr(tab->tab[tmp], c + 32))
			tab->my_pos[width++] = get_pos_tab(tab->tab[tmp], tmp, c);
		tmp++;
	}
}

void	get_pos_en(t_tab *tab, int i, char c)
{
	int		width;
	int		tmp;

	width = 0;
	tmp = i;
	while (i < tab->width)
	{
		if (ft_strrchr(tab->tab[i], c) || ft_strrchr(tab->tab[i], c - 32))
			width++;
		i++;
	}
	tab->pos_en = (int**)malloc(sizeof(int*) * width);
	tab->width_en = width;
	width = 0;
	while (tmp < tab->width)
	{
		if (ft_strrchr(tab->tab[tmp], c) || ft_strrchr(tab->tab[tmp], c - 32))
		{
			tab->pos_en[width] = get_pos_tab(tab->tab[tmp], tmp, c);
			width++;
		}
		tmp++;
	}
}

void	get_pos_stp(t_tab *tab)
{
	int		i;
	char	c;

	i = 0;
	tab->pos_en = NULL;
	tab->my_pos = NULL;
	tab->map = NULL;
	c = tab->c == 'O' ? 'x' : 'o';
	while (i < tab->width)
	{
		if (ft_strchr(tab->tab[i], tab->c) ||
		ft_strchr(tab->tab[i], tab->c + 32))
		{
			if (tab->my_pos == NULL)
				get_my_pos(tab, i, tab->c);
		}
		if (ft_strchr(tab->tab[i], c) || ft_strchr(tab->tab[i], c - 32))
		{
			if (tab->pos_en == NULL)
				get_pos_en(tab, i, c);
		}
		i++;
	}
}

int		ft_tab_size(t_tab *tab)
{
	int		i;
	char	*str;

	i = -1;
	str = NULL;
	while (ft_strnequ(str, "Plateau ", 8) == 0)
		get_next_line(0, &str);
	tab->width = ft_atoi(&str[8]);
	tab->lenght = ft_atoi(&str[11]);
	scotch_chekpoint(str, tab);
	get_next_line(0, &str);
	free(str);
	if (!(tab->tab = (char**)malloc(sizeof(char*) * tab->width)))
		return (0);
	while (++i < tab->width)
	{
		get_next_line(0, &str);
		if (ft_strchr(str, 'o') != 0)
			tab->c = 'X';
		tab->tab[i] = ft_strdup(&str[4]);
		free(str);
	}
	get_pos_stp(tab);
	fill_heat_map(tab);
	return (1);
}
