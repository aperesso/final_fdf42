/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesso <aperesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 20:12:05 by aperesso          #+#    #+#             */
/*   Updated: 2018/01/13 15:40:04 by aperesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include <unistd.h>

static t_fd	*get_current_fd(t_fd **head, int fd)
{
	t_fd	*current;
	t_fd	*new;

	if (*head)
	{
		current = *head;
		while (current)
		{
			if (current->fd == fd)
				return (current);
			current = current->next;
		}
	}
	if (!(new = (t_fd *)malloc(sizeof(t_fd))))
		return (NULL);
	new->fd = fd;
	new->line = ft_strnew(BUFF_SIZE);
	new->next = NULL;
	if (!*head)
		return ((*head = new));
	new->next = *head;
	*head = new;
	return (*head);
}

static int	read_line(t_fd **current)
{
	int		rd;
	char	buffer[BUFF_SIZE + 1];
	char	*tmp;
	t_fd	*cur;

	cur = *current;
	buffer[BUFF_SIZE] = 0;
	while ((rd = read(cur->fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[rd] = '\0';
		tmp = cur->line;
		cur->line = ft_strjoin(tmp, buffer);
		free(tmp);
		if (!cur->line)
			return (GNL_ERROR);
		if (ft_strchr(cur->line, '\n'))
			break ;
	}
	*current = cur;
	return (rd);
}

static int	process_line(t_fd **current, char **line)
{
	int		n;
	char	*tmp;
	t_fd	*cur;

	n = -1;
	cur = *current;
	while (cur->line[++n])
		if (cur->line[n] == '\n')
			break ;
	*line = ft_strsub(cur->line, 0, n);
	if (!(tmp = ft_strnew(ft_strlen(cur->line + n + 1))))
		return (GNL_ERROR);
	if (n == (int)ft_strlen(cur->line))
	{
		ft_strdel(&cur->line);
		cur->line = ft_strnew(1);
		return (GNL_SUCCESS);
	}
	ft_strcpy(tmp, cur->line + n + 1);
	ft_strclr(cur->line);
	ft_strcpy(cur->line, tmp);
	free(tmp);
	*current = cur;
	return (GNL_SUCCESS);
}

int			get_next_line(int const fd, char **line)
{
	static t_fd		*top = NULL;
	t_fd			*current;

	if (fd < 0 || !line || BUFF_SIZE < 1 ||
		!(current = get_current_fd(&top, fd)) || !current->line)
		return (GNL_ERROR);
	if (read_line(&current) < 0)
		return (GNL_ERROR);
	if (current->line[0] == '\0')
	{
		*line = NULL;
		return (GNL_END);
	}
	return ((process_line(&current, line) < 0) ? GNL_ERROR : GNL_SUCCESS);
}
