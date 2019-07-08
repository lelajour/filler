/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_clear_memory.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/08 18:39:49 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/08 19:16:50 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/ft_filler.h"

void	ft_clear_tab(char **tab, int i)
{
	int	x;

	x = 0;
	while (x < i)
		free(tab[x++]);
	free(tab);
}

void	clear_t_tab(t_tab *tab)
{
	int i;

	i = 0;
	if (tab)
	{
		if (tab->tab[0] != NULL)
		{
			while (i < tab->width)
				free(tab->tab[i++]);
			free(tab->tab);
		}
		free(tab);
	}
}

void	clear_piece(t_piece *piece)
{
	int i;

	i = 0;
	if (piece)
	{
		if (piece->tab[0] != NULL)
		{
			while (i < piece->width)
				free(piece->tab[i++]);
			free(piece->tab);
		}
		free(piece);
	}
}
