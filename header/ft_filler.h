/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_filler.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/25 13:20:44 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/08 19:12:47 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_FILLER_H
# define FT_FILLER_H

# include <stdarg.h>
# include <stdio.h>
#	include "get_next_line.h"
#	include "ft_printf.h"

typedef struct s_tab
{
	char	**tab;
	int		lenght;
	int		width;
	char	c;
}							t_tab;

typedef struct s_piece
{
	char	**tab;
	int		lenght;
	int		width;
	char	c;
}							t_piece;

int			ft_filler();
int			ft_tab_size(t_tab *tab);
t_piece	*ft_piece_size();
char		**ft_real_psize(char **f_tab, int p_i, t_piece *piece);
void		ft_clear_tab(char **tab, int i);
void		clear_piece(t_piece *piece);
void		clear_t_tab(t_tab *tab);
#endif
