/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fill_piece.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/09 23:57:40 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/01 06:45:11 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/ft_filler.h"

int		save_pos(int i, int score, t_tab *tab)
{
	tab->best_pos = i;
	return (score);
}

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

int		*get_pos_piece(char *str, int i, char c)
{
	int *tmp;

	tmp = NULL;
	tmp = malloc(sizeof(int) * 3);
	tmp[0] = i;
	tmp[1] = ft_strclen(str, c);
	tmp[2] = ft_strrclen(str, c);
	return (tmp);
}

void	ft_real_psize(char **tab, t_piece *piece)
{
	int	i;
	int	width;

	i = 0;
	width = 0;
	while (i < piece->width)
	{
		if (ft_strrchr(tab[i], '*') != 0)
			width++;
		i++;
	}
	i = 0;
	piece->pos_piece = malloc(sizeof(int*) * width);
	piece->width_pos = width;
	width = 0;
	while (i < piece->width)
	{
		if (ft_strrchr(tab[i], '*') != 0)
			piece->pos_piece[width++] = get_pos_piece(tab[i], i, '*');
		i++;
	}
}

t_piece	*ft_piece_size(void)
{
	int		i;
	char	*str;
	t_piece	*piece;

	i = 0;
	piece = (t_piece*)malloc(sizeof(t_piece) * 1);
	if (get_next_line(0, &str) != 0)
	{
		piece->width = ft_atoi(&str[6]);
		piece->lenght = ft_atoi(&str[8]);
		free(str);
		piece->tab = (char**)malloc(sizeof(char*) * piece->width);
		while (i < piece->width && get_next_line(0, &str))
		{
			piece->tab[i] = ft_strdup(str);
			i++;
			free(str);
		}
	}
	ft_real_psize(piece->tab, piece);
	return (piece);
}
