/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parsing_f.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/25 12:19:07 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/02 15:37:08 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/ft_filler.h"

int		last_ck(int i, t_piece *pce, t_tab *tb)
{
	int	r_i;
	int	r_j;
	int	tmp;

	r_i = i / tb->lenght;
	r_j = i % tb->lenght;
	pce->p_i = 0;
	tmp = 0;
	while (pce->p_i < pce->width && (pce->p_i + r_i) < tb->width)
	{
		pce->p_j = -1;
		while (++pce->p_j < pce->lenght && (r_j + pce->p_j) < tb->lenght)
		{
			if (pce->tab[pce->p_i][pce->p_j] == '*' && ck_pos(i, pce, tb) == 1)
				tmp++;
		}
		pce->p_i++;
	}
	if (tmp == 1)
	{
		tb->nb = tmp;
		return (1);
	}
	else
		return (-1);
}

int		verif_pos(t_tab *tb, char **tab, t_piece *pce, int i)
{
	int	r_j;
	int	r_i;
	int	c;

	r_i = i / tb->lenght;
	r_j = i % tb->lenght;
	pce->p_i = 0;
	c = 0;
	if ((pce->width + r_i) > tb->width || (pce->lenght + r_j) > tb->lenght)
		return (-1);
	while (pce->p_i < pce->width && (pce->p_i + r_i) < tb->width)
	{
		pce->p_j = -1;
		while (++pce->p_j < pce->lenght && (r_j + pce->p_j) < tb->lenght)
		{
			if (tab[r_i + pce->p_i][r_j + pce->p_j] != '.' &&
			ck_pos(i, pce, tb) == 1)
				c++;
			else if (ck_pos(i, pce, tb) == 0)
				return (-1);
		}
		pce->p_i++;
	}
	return (c >= 1 ? last_ck(i, pce, tb) : -1);
}

int		tab_pos(t_tab *tb, int i, t_piece *pce)
{
	int	r_i;
	int	r_j;
	int	p_i;
	int	p_j;

	r_i = i / tb->lenght;
	r_j = i % tb->lenght;
	p_i = 0;
	tb->nb = 0;
	while (p_i < pce->width && (p_i + r_i) < tb->width)
	{
		p_j = 0;
		while (p_j < pce->lenght && (r_j + p_j) < tb->lenght)
		{
			if (tb->map[r_i + p_i][r_j + p_j] == -1 &&
				pce->tab[p_i][p_j] != '.')
				return (-1);
			tb->nb += tb->map[r_i + p_i][r_j + p_j] == -1 ? 0 :
			tb->map[r_i + p_i][r_j + p_j];
			p_j++;
		}
		p_i++;
	}
	return (tb->nb);
}

int		ft_start(t_tab *tab)
{
	int		i;
	int		score;
	int		ret;
	t_piece *piece;

	i = 0;
	score = 2147483647;
	ret = 0;
	tab->tmp = 0;
	tab->best_pos = 0;
	if (ft_tab_size(tab) == 0 || (piece = ft_piece_size()) == 0)
		return (0);
	while (i < (tab->width * tab->lenght))
	{
		ret = tab_pos(tab, i, piece);
		if (ret != -1 && ret <= score)
			if ((verif_pos(tab, tab->tab, piece, i)) == 1)
				score = save_pos(i, ret, tab);
		i++;
	}
	ft_printf("%d %d\n", tab->best_pos / tab->lenght,
	tab->best_pos % tab->lenght);
	clear_piece(piece);
	clear_t_tab(tab);
	return (score == 2147483647 ? 0 : 1);
}

int		main(void)
{
	int		i;
	t_tab	*tab;
	char	*str;

	i = 1;
	tab = malloc(sizeof(t_tab) * 2);
	get_next_line(0, &str);
	if (ft_strnequ(str, "$$$ exec p2", 11) == 1)
		tab->c = 'X';
	else
		tab->c = 'O';
	while (i != 0)
		i = ft_start(tab);
	free(tab);
	free(str);
	return (0);
}
