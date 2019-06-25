/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/11 13:46:03 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/25 14:26:50 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"
# define BUFF_SIZE 5646
# define FD_MAX 9999

char	*new_tmp(char *tmp);
void	line_return(char *tmp, char **line);
char	*save_buff(char *buff, char *tmp);
int		get_next_line(const int fd, char **line);

#endif
