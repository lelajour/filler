/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fill_tab.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/06 19:27:04 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/08 20:07:00 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/ft_filler.h"

char	**ft_adjust_rest(char **tab, int width, t_piece *piece)
{
	int		i;
	int		len;
	char	*tmp;

	i = 0;
	len = 2147483647;
	while (i < width)
	{
		if ((tmp = ft_strrchr(tab[i], '*')))
		{
			tmp++;
			len = ft_strlen(tmp) < len ? ft_strlen(tmp) : len;
		}
		i++;
	}
	i = -1;
	while (++i < piece->width)
		ft_memset(tab[i] + (ft_strlen(tab[i]) - len), '\0', len);
	piece->lenght = ft_strlen(tab[0]);
	return (tab);
}

char	**ft_real_psize(char **f_tab, int p_i, t_piece *piece)
{
	int		i;
	int		len;
	int		width;
	char	**tab;

	len = 2147483647;
	i = -1;
	width = 0;
	while (++i < p_i && i >= 0)
	{
		if ((ft_strclen(f_tab[i], '*')) < len)
			len = ft_strclen(f_tab[i], '*');
		if (ft_strrchr(f_tab[i], '*') != 0)
			width++;
	}
	piece->width = width;
	width = 0;
	i = -1;
	tab = malloc(sizeof(char*) * piece->width);
	while (width < piece->width)
	{
		if (ft_strrchr(f_tab[++i], '*') != 0)
			tab[width++] = ft_strdup(f_tab[i] + len);
	}
	return (ft_adjust_rest(tab, piece->width, piece));
}

t_piece *ft_piece_size()
{
	int			i;
	char		*str;
	char		**tmp;
	t_piece	*piece;

	i = 0;
	tmp = NULL;
	piece = (t_piece*)malloc(sizeof(t_piece) * 1);
	if (get_next_line(0, &str) != 0)
	{
		piece->width = ft_atoi(&str[6]);
		piece->lenght = ft_atoi(&str[8]);
		free(str);
		tmp = (char**)malloc(sizeof(char*) * piece->width);
		while (i < piece->width && get_next_line(0, &str))
		{
			ft_printf("piece->width ==%#x\n", &*str);
			tmp[i] = ft_strdup(str);
			i++;
			free(str);
		}
	}
	piece->tab = ft_real_psize(tmp, i, piece);
	ft_clear_tab(tmp, i);
	return (piece);
}

int		ft_tab_size(t_tab *tab)
{
	int		i;
	char	*str;

	i = 0;
	get_next_line(0, &str);
	if (ft_strnequ(&str[5], "fin:", 4))
		return (0);
	tab->width = ft_atoi(&str[8]);
	tab->lenght = ft_atoi(&str[11]);
	free(str);
	get_next_line(0, &str);
	free(str);
	if (!(tab->tab = (char**)malloc(sizeof(char*) * tab->width)))
		exit(-1);
	while (i < tab->width)
	{
		get_next_line(0, &str);
		tab->tab[i] = ft_strdup(&str[4]);
		free(str);
		i++;
	}
	return (1);
}
