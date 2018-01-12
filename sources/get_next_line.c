/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesso <aperesso@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 20:12:05 by aperesso          #+#    #+#             */
/*   Updated: 2017/12/03 17:11:27 by aperesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

static	int	read_line(int const fd, char *tab[fd])
{
	int		rd;
	char	buffer[BUFF_SIZE + 1];
	char	*tmp;

	while ((rd = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[rd] = '\0';
		tmp = tab[fd];
		tab[fd] = ft_strjoin(tmp, buffer);
		free(tmp);
		if (!tab[fd])
			return (GNL_ERROR);
		if (ft_strchr(tab[fd], '\n'))
			break;
	}
	return (rd);
}

static	int	process_line(int const fd, char *tab[fd], char **line)
{
	int		n;
	char	*tmp;

	n = -1;
	while (tab[fd][++n])
	{
		if (tab[fd][n] == '\n')
			break;
	}
	*line = ft_strsub(tab[fd], 0, n);
	if (!(tmp = (char *)malloc(sizeof(tmp) * (ft_strlen(tab[fd]) + 1))))
		return (GNL_ERROR);
	ft_strcpy(tmp, &tab[fd][n + 1]);
	ft_strclr(tab[fd]);
	ft_strcpy(tab[fd], tmp);
	free(tmp);
	return (GNL_SUCCESS);
}

int			get_next_line(int const fd, char **line)
{
	static	char	*tab[256];

	if (fd < 0 || !line || fd > 256 ||
	 	(!tab[fd] && (!(tab[fd] = ft_strnew(BUFF_SIZE)))) 
		 || read_line(fd, &(*tab)) < 0 )
		return (GNL_ERROR);
	if (tab[fd][0] == '\0')
	{
		*line = NULL;
		return (GNL_END);
	}
	return (process_line(fd, tab, line) < 0) ? GNL_ERROR : GNL_SUCCESS;
}