/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_filler.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/25 13:20:44 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/02 10:37:14 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_FILLER_H
# define FT_FILLER_H

# include <stdarg.h>
# include <stdio.h>
# include "get_next_line.h"
# include "ft_printf.h"

typedef struct		s_tab
{
	char			**tab;
	int				lenght;
	int				width;
	char			c;
	int				**pos_en;
	int				**my_pos;
	int				**map;
	int				width_en;
	int				width_my;
	int				best_pos;
	int				nb;
	int				dw;
	int				tmp;
}					t_tab;

typedef struct		s_piece
{
	char			**tab;
	int				lenght;
	int				width;
	int				p_i;
	int				p_j;
	char			c;
	int				**pos_piece;
	int				width_pos;
}					t_piece;

void				fortytwo(int **map, t_tab *t);
int					ft_tab_size(t_tab *tab);
t_piece				*ft_piece_size();
void				ft_real_psize(char **tab, t_piece *piece);
void				ft_clear_tab(char **tab, int i);
void				clear_piece(t_piece *piece);
void				clear_t_tab(t_tab *tab);
int					*get_pos_piece(char *str, int i, char c);
void				get_pos_stp(t_tab *tab);
void				get_pos_tpiece(t_piece *piece);
void				fill_heat_map(t_tab *tab);
void				rmap_diagonal_up(int **map, int *tmp, t_tab *tab);
void				rmap_diagonal_down(int **map, int *tmp, t_tab *tab);
void				adjust_map(int **map, t_tab *tab);
void				last_verif(t_tab *tab);
void				scotchisimo(int *y, int *i, int *num);
int					save_pos(int i, int score, t_tab *tab);
int					ck_pos(int i, t_piece *pce, t_tab *tb);
void				get_pos_ox(t_tab *tab, int i);
void				scotch_chekpoint(char *str, t_tab *tab);

#endif
