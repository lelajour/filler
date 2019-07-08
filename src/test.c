/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/08 21:57:08 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/08 22:08:28 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/ft_filler.h"

int		main(int ac, char **av)
{
	int	fd;
	char	*str;

	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &str) != 0)
	{
		ft_printf("%s\n", str);
		free(str);
	}
	// free(str);
	return (0);
}
