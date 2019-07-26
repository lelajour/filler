/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fill_piece.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/09 23:57:40 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/26 05:06:35 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/ft_filler.h"

// void	get_pos_tpiece(t_piece *piece)
// {
// 	int		i;
// 	int		len;
//
// 	i = 0;
// 	len = ft_strlen(piece->tab[i]);
// 	if (piece)
// 	{
// 		piece->top_left = ft_strclen(piece->tab[i], '*');
// 		piece->top_right = ft_strrclen(piece->tab[i], '*');
// 		i = piece->width - 1;
// 		piece->bot_left = ft_strclen(piece->tab[i], '*');
// 		piece->bot_right = ft_strrclen(piece->tab[i], '*');
// 	}
// }

// char	**ft_adjust_rest(char **tab, int width, t_piece *piece)
// {
// 	int		i;
// 	int		len;
// 	char	*tmp;
//
// 	i = 0;
// 	len = 2147483647;
// 	while (i < width)
// 	{
// 		if ((tmp = ft_strrchr(tab[i], '*')))
// 		{
// 			tmp++;
// 			len = ft_strlen(tmp) < len ? ft_strlen(tmp) : len;
// 		}
// 		i++;
// 	}
// 	i = -1;
// 	while (++i < piece->width)
// 		ft_memset(tab[i] + (ft_strlen(tab[i]) - len), '\0', len);
// 	piece->lenght = ft_strlen(tab[0]);
// 	return (tab);
// }
//
// char	**ft_real_psize(char **f_tab, int p_i, t_piece *piece)
// {
// 	int		i;
// 	int		len;
// 	int		width;
// 	char	**tab;
//
// 	len = 2147483647;
// 	i = -1;
// 	width = 0;
// 	while (++i < p_i && i >= 0)
// 	{
// 		if ((ft_strclen(f_tab[i], '*')) < len)
// 			len = ft_strclen(f_tab[i], '*');
// 		if (ft_strrchr(f_tab[i], '*') != 0)
// 			width++;
// 	}
// 	piece->width = width;
// 	width = 0;
// 	i = -1;
// 	tab = malloc(sizeof(char*) * piece->width);
// 	while (width < piece->width)
// 	{
// 		if (ft_strrchr(f_tab[++i], '*') != 0)
// 			tab[width++] = ft_strdup(f_tab[i] + len);
// 	}
// 	return (ft_adjust_rest(tab, piece->width, piece));
// }

int	*get_pos_piece(char *str, int i, char c)
{
	int *tmp;

	tmp = NULL;
	tmp = malloc(sizeof(int) * 3);
	tmp[0] = i;
	tmp[1] = ft_strclen(str, c);
	tmp[2] = ft_strrclen(str, c);
	ft_printf("[%d]|[%d][%d]\n", tmp[0], tmp[1], tmp[2]);
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

t_piece *ft_piece_size()
{
	int			i;
	char		*str;
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
	// ft_printf("je suis width ->[%d]\nJe suis lenght ->[%d]\n", piece->width, piece->lenght);
	return (piece);
}
