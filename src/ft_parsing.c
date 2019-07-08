/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parsing.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/25 12:19:07 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/08 19:18:33 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/ft_filler.h"

int		ft_start(t_tab *tab)
{
	int		i;
	t_piece *piece;

	i = 0;
	piece = NULL;
	if (ft_tab_size(tab) == 0)
		return (0);
	piece = ft_piece_size();
	while (i < tab->width)
	{
		if (i == 0)
		{
			write(1, "    ", 4);
			while (i < tab->lenght)
				ft_putchar((i++ % 10) +'0');
			ft_putchar('\n');
			i = 0;
		}
		ft_printf("%03d %s\n", i, tab->tab[i]);
		i++;
	}
	i = -1;
	while (i++ < piece->width  - 1)
		ft_printf("%03d %s\n", i, piece->tab[i]);
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
	tab = malloc(sizeof(t_tab) * 1);
	first = 'O';
	while (get_next_line(0, &str) && i < 9)
	{
		if (i == 8)
			if (ft_strequ(&str[14], "[../lelajour.filler]"))
				first = 'X';
		free(str);
		i++;
	}
	free(str);
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
