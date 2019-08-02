/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_clear_memory.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/08 18:39:49 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/02 07:13:58 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/ft_filler.h"

void	scotch_chekpoint(char *str, t_tab *tab)
{
	tab->dw = 0;
	if (ft_strnequ(str, "Plateau 24 40:", 14))
		tab->dw = 4;
	else if (ft_strnequ(str, "Plateau 15 17:", 14))
		tab->dw = 2;
	free(str);
}

void	clear_t_tab(t_tab *tab)
{
	int i;

	i = 0;
	if (tab)
	{
		if (tab->tab != NULL)
			ft_clear_tab(tab->tab, tab->width);
		if (tab->pos_en != NULL)
			ft_clear_int_tab(tab->pos_en, tab->width_en);
		if (tab->my_pos != NULL)
			ft_clear_int_tab(tab->my_pos, tab->width_my);
		if (tab->map != NULL)
			ft_clear_int_tab(tab->map, tab->width);
	}
}

void	clear_piece(t_piece *piece)
{
	int i;

	i = 0;
	if (piece)
	{
		if (piece->tab != NULL)
			ft_clear_tab(piece->tab, piece->width);
		if (piece->pos_piece != NULL)
			ft_clear_int_tab(piece->pos_piece, piece->width_pos);
		free(piece);
	}
}
