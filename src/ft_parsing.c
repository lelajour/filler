/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parsing.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/25 12:19:07 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/25 16:16:18 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/ft_filler.h"

int		ft_filler(void)
{
	char	*str;
	char	**tab;
	int		i;

	i = 0;
	tab = NULL;
	while (get_next_line(0, &str))
	{
		tab[i] = ft_strdup(str);
		free(str);
		i++;
	}
	return (1);
}

int	main(void)
{
	if (ft_filler() == 1)
		ft_printf("YES");
	return (0);
}
