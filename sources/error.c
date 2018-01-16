/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesso <aperesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 23:47:56 by aperesso          #+#    #+#             */
/*   Updated: 2018/01/16 12:08:59 by aperesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		*error(char *message)
{
	ft_putstr(message);
	return (NULL);
}

void		flush_loader(t_loader *loader)
{
	t_loader	*tmp;

	while (loader)
	{
		tmp = loader;
		loader = loader->next;
		free(tmp->data);
		tmp->data = NULL;
		free(tmp);
		tmp = NULL;
	}
	free(loader);
}
