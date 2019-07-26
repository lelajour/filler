/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parsing_f.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/25 12:19:07 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/26 08:03:15 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/ft_filler.h"

int		ck_pos(int i, t_piece *pce, t_tab *tb)
{
	int	r_j;
	int	r_i;

	r_i = i / tb->lenght;
	r_j = i % tb->lenght;
	if (tb->tab[r_i + pce->p_i][r_j + pce->p_j] == tb->c ||
		tb->tab[r_i + pce->p_i][r_j + pce->p_j] == tb->c + 32)
		return (1);
	else
		return (-1);
}

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
	if (tmp < tb->nb || (tb->nb == 0 && tmp != 0))
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
	if ((pce->width + r_i) >= tb->width || (pce->lenght + r_j) >= tb->lenght)
		return (-1);
	while (pce->p_i < pce->width && (pce->p_i + r_i) < tb->width)
	{
		pce->p_j = -1;
		while (++pce->p_j < pce->lenght && (r_j + pce->p_j) < tb->lenght)
		{
			if (tab[r_i + pce->p_i][r_j + pce->p_j] != '.' && ck_pos(i, pce, tb) == 1)
				c++;
			else if (ck_pos(i, pce, tb) == 0)
				return (-1);
		}
		pce->p_i++;
	}
	ft_printf("[%d]", c);
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
			if (tb->map[r_i + p_i][r_j + p_j] == -1 && pce->tab[p_i][p_j] != '.')
				return (-1);
			tb->nb += tb->map[r_i + p_i][r_j + p_j] == -1 ? 0 : tb->map[r_i + p_i][r_j + p_j];
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
	piece = NULL;
	if (ft_tab_size(tab) == 0)
		return (0);
	piece = ft_piece_size();
	while (i < (tab->width * tab->lenght))
	{
		ret = tab_pos(tab, i, piece);
		if (ret != -1 && ret <= score)
			if ((verif_pos(tab, tab->tab, piece, i)) == 1)
				score = ret;
		ft_printf("[%d][%d]|%d\n", i / tab->lenght, i % tab->lenght, score);
		i++;
	}
	i = -1;
	// while (i++ < piece->width  - 1)
	// 	ft_printf("%03d %s\n", i, piece->tab[i]);
	clear_piece(piece);
	return (1);
}

int		ft_filler()
{
	int		i;
	char	first;
	t_tab *tab;
	char	*str;

	i = 0;
	tab = malloc(sizeof(t_tab) * 2);
	first = 'O';
	while (i < 9 && get_next_line(0, &str))
	{
		if (i == 8)
			if (ft_strequ(&str[14], "[../lelajour.filler]"))
				first = 'X';
		free(str);
		i++;
	}
	tab->c = first;
	// while (i != 0)
		i = ft_start(tab);
	clear_t_tab(tab);
	return (1);
}
int	main(void)
{
	// int c;

	if (ft_filler() == 1)
		// ft_printf("YES\n");
	return (0);
}
