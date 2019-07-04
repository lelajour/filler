/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parsing.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/25 12:19:07 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/04 09:58:41 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/ft_filler.h"

int		ft_filler(char **tab)
{
	int		i;
	int		first;
	char	*str;

	i = 0;
	first = 1;
	while (get_next_line(1, &str) && i < 9)
	{
		ft_putendl_fd(tab[i], 0);
		if ((i == 6 || i == 8) && first != 2)
			if (ft_strequ(&str[14], "[../lelajour.filler]"))
				first = 2;
		i++;
		free(str);
	}
	if (first == 1)
		printf("Je suis premier\n");
	if (first == 2)
		printf("Je suis second\n");
	return (1);
}

int	main(int	ac, char **av)
{
	int		fd;
	int		i;
	char	*line;
	char	**tab;

	(void)ac;
	i = 0;
	fd = open(av[1], O_RDONLY);
	tab = (char**)malloc(sizeof(char*) * 55);
	while (get_next_line(fd, &line))
	{
		tab[i++] = ft_strdup(line);
		free(line);
	}
	i = 0;
	if (ft_filler(tab) == 1)
		ft_printf("YES");
	close(fd);
	return (0);
}
